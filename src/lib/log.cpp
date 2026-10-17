#include <lib/log.h>
#include <SDL3/SDL.h>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>
#ifdef __SWITCH__
# include <unistd.h>
# include <switch.h>
#endif

/*
 * Lowest priority that is written to the log file. DEBUG also records every
 * file the game opens, which is useful for tracking down missing assets, but
 * produces a lot of output. Raise to SDL_LOG_PRIORITY_INFO to reduce it.
 */
#define NFS_LOG_LEVEL   SDL_LOG_PRIORITY_DEBUG

/*
 * Start of the memory region that contains addr. For addresses in the program
 * image this is the load base of the code (the .elf is linked at 0), so
 * "addr - textBase(addr)" can be given to addr2line.
 */
static unsigned long long textBase(unsigned long long addr)
{
#ifdef __SWITCH__
    MemoryInfo info;
    u32 pageInfo;
    if (R_SUCCEEDED(svcQueryMemory(&info, &pageInfo, addr)))
        return info.addr;
#endif
    (void)addr;
    return 0;
}

namespace win32
{

static FILE*                    s_logFile = nullptr;
static SDL_Mutex*               s_logMutex = nullptr;
static SDL_LogOutputFunction    s_prevOutput = nullptr;
static void*                    s_prevUserdata = nullptr;

static const char* priorityName(SDL_LogPriority priority)
{
    switch (priority)
    {
    case SDL_LOG_PRIORITY_TRACE:    return "TRACE";
    case SDL_LOG_PRIORITY_VERBOSE:  return "VERBOSE";
    case SDL_LOG_PRIORITY_DEBUG:    return "DEBUG";
    case SDL_LOG_PRIORITY_INFO:     return "INFO";
    case SDL_LOG_PRIORITY_WARN:     return "WARN";
    case SDL_LOG_PRIORITY_ERROR:    return "ERROR";
    case SDL_LOG_PRIORITY_CRITICAL: return "CRITICAL";
    default:                        return "?";
    }
}

static void writeLine(const char* prefix, const char* message)
{
    if (!s_logFile)
        return;
    if (s_logMutex)
        SDL_LockMutex(s_logMutex);
    unsigned long long ms = SDL_GetTicks();
    fprintf(s_logFile, "[%7llu.%03llu] t%llu %s%s\n", ms / 1000, ms % 1000,
            (unsigned long long) SDL_GetCurrentThreadID(), prefix, message);
    fflush(s_logFile);
    if (s_logMutex)
        SDL_UnlockMutex(s_logMutex);
}

static void SDLCALL logOutput(void* userdata, int category, SDL_LogPriority priority, const char* message)
{
    char prefix[48];
    snprintf(prefix, sizeof(prefix), "%-5s c%d: ", priorityName(priority), category);
    writeLine(prefix, message);
    if (s_prevOutput)
        s_prevOutput(s_prevUserdata, category, priority, message);
    (void)userdata;
}

void initLog(const char* path)
{
    if (s_logFile)
        return;

    std::string current(path);
    std::string previous = current + ".prev";
    /* rename() does not overwrite on the SD card file system */
    remove(previous.c_str());
    rename(current.c_str(), previous.c_str());

    s_logFile = fopen(current.c_str(), "w");
    if (!s_logFile)
        return;

    s_logMutex = SDL_CreateMutex();
    SDL_GetLogOutputFunction(&s_prevOutput, &s_prevUserdata);
    SDL_SetLogPriorities(NFS_LOG_LEVEL);
    SDL_SetLogOutputFunction(logOutput, nullptr);
    writeLine("", "log started");
    startWatchdog();
}

struct WatchSlot
{
    SDL_AtomicInt       used;
    SDL_ThreadID        tid;
    const void* volatile    lastApi;
    const char* volatile    what;
    const char* volatile    detail;
    volatile unsigned       arg;
    volatile Uint64         since;
    Uint64                  reported;
};

static const int    MaxSlots = 64;
static WatchSlot    s_slots[MaxSlots];
static volatile Uint64  s_heartbeat = 0;
static Uint64           s_heartbeatReported = 0;

static WatchSlot* currentSlot()
{
    static thread_local WatchSlot* slot = nullptr;
    if (!slot)
    {
        for (int i = 0; i < MaxSlots; ++i)
        {
            if (SDL_CompareAndSwapAtomicInt(&s_slots[i].used, 0, 1))
            {
                s_slots[i].tid = SDL_GetCurrentThreadID();
                slot = &s_slots[i];
                break;
            }
        }
        if (!slot)
            slot = &s_slots[MaxSlots - 1];
    }
    return slot;
}

void watchdogEnter(const char* what, unsigned arg, const char* detail)
{
    WatchSlot* slot = currentSlot();
    slot->arg = arg;
    slot->detail = detail;
    slot->since = SDL_GetTicks();
    slot->reported = 0;
    slot->what = what;
}

void watchdogLeave()
{
    currentSlot()->what = nullptr;
}

void watchdogNoteApi(const void* function)
{
    currentSlot()->lastApi = function;
}

void watchdogHeartbeat()
{
    s_heartbeat = SDL_GetTicks();
}

static unsigned long long imageBase()
{
    return textBase((unsigned long long) &textBase);
}

static void dumpThreads(const char* reason)
{
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "WATCHDOG: %s (image base 0x%llx)", reason, imageBase());
    writeLine("", buffer);
    for (int i = 0; i < MaxSlots; ++i)
    {
        WatchSlot& s = s_slots[i];
        if (!SDL_GetAtomicInt(&s.used))
            continue;
        const char* what = s.what;
        unsigned long long api = (unsigned long long) s.lastApi;
        if (imageBase() != 0 && api >= imageBase())
            api -= imageBase();
        if (what)
            snprintf(buffer, sizeof(buffer), "WATCHDOG:   thread %llu: blocked %llu ms in %s(%u) %s, last api +0x%llx",
                     (unsigned long long) s.tid, (unsigned long long) (SDL_GetTicks() - s.since), what, s.arg,
                     s.detail ? s.detail : "", api);
        else
            snprintf(buffer, sizeof(buffer), "WATCHDOG:   thread %llu: running, last api +0x%llx",
                     (unsigned long long) s.tid, api);
        writeLine("", buffer);
    }
}

static int SDLCALL watchdogMain(void*)
{
    for (;;)
    {
        SDL_Delay(1000);
        Uint64 now = SDL_GetTicks();
        bool dump = false;
        char reason[128];
        reason[0] = 0;
        for (int i = 0; i < MaxSlots; ++i)
        {
            WatchSlot& s = s_slots[i];
            /* worker threads normally sleep in infinite waits; only report real stalls */
            if (SDL_GetAtomicInt(&s.used) && s.what && s.arg != 0xffffffffu
                && now - s.since > 4000 && now - s.reported > 5000)
            {
                s.reported = now;
                snprintf(reason, sizeof(reason), "a thread is blocked for more than 4 s");
                dump = true;
            }
        }
        if (s_heartbeat && now - s_heartbeat > 4000 && now - s_heartbeatReported > 5000)
        {
            s_heartbeatReported = now;
            snprintf(reason, sizeof(reason), "main loop has not pumped messages for %llu ms", (unsigned long long) (now - s_heartbeat));
            dump = true;
        }
        if (dump)
            dumpThreads(reason);
    }
    return 0;
}

void startWatchdog()
{
    static bool started = false;
    if (started || !s_logFile)
        return;
    started = true;
    SDL_Thread* t = SDL_CreateThread(watchdogMain, "watchdog", nullptr);
    if (t)
        SDL_DetachThread(t);
}

void logPrintf(const char* fmt, ...)
{
    char buffer[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    SDL_Log("%s", buffer);
}

}

#ifdef __SWITCH__
/*
 * NFS2_ASSERT on the Switch: record where the assertion failed, then trap
 * like the plain macro did before. Most of the guest's Win32 API stubs end in
 * NFS2_ASSERT(false), so the function name identifies the unimplemented call.
 */
void nfs2_assertFailed(const char* expr, const char* file, int line, const char* func)
{
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "ASSERT FAILED: %s  (%s:%d, %s)", expr, file, line, func);
    win32::writeLine("", buffer);
    if (win32::s_logFile)
        fsync(fileno(win32::s_logFile));
    asm volatile("brk #0");
}
#endif

#ifdef __SWITCH__
/*
 * CPU exception handler (libnx calls this on a crash, e.g. a bad memory
 * access in the recompiled code). Logs the fault so it can be located; the
 * addresses can be resolved against the .elf with aarch64-none-elf-addr2line
 * after subtracting the load base. The handler runs on a small stack, so it
 * only uses a short buffer.
 */
extern "C" void __libnx_exception_handler(ThreadExceptionDump* ctx)
{
    FILE* f = win32::s_logFile;
    if (!f)
        return;
    char buffer[256];
    unsigned long long base = textBase((unsigned long long) ctx->pc.x);
    snprintf(buffer, sizeof(buffer),
             "CRASH: desc=%u pc=0x%llx lr=0x%llx sp=0x%llx far=0x%llx esr=0x%x\n",
             (unsigned) ctx->error_desc,
             (unsigned long long) ctx->pc.x, (unsigned long long) ctx->lr.x,
             (unsigned long long) ctx->sp.x, (unsigned long long) ctx->far.x,
             (unsigned) ctx->esr);
    fputs(buffer, f);
    snprintf(buffer, sizeof(buffer), "CRASH: image base=0x%llx pc-base=0x%llx lr-base=0x%llx\n",
             base, (unsigned long long) ctx->pc.x - base, (unsigned long long) ctx->lr.x - base);
    fputs(buffer, f);
    for (int i = 0; i < 29; i += 4)
    {
        snprintf(buffer, sizeof(buffer), "CRASH: x%d=%llx x%d=%llx x%d=%llx x%d=%llx\n",
                 i, (unsigned long long) ctx->cpu_gprs[i].x,
                 i + 1, (unsigned long long) (i + 1 < 29 ? ctx->cpu_gprs[i + 1].x : 0),
                 i + 2, (unsigned long long) (i + 2 < 29 ? ctx->cpu_gprs[i + 2].x : 0),
                 i + 3, (unsigned long long) (i + 3 < 29 ? ctx->cpu_gprs[i + 3].x : 0));
        fputs(buffer, f);
    }
    fflush(f);
    fsync(fileno(f));
}
#endif
