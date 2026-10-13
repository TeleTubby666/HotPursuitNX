#include <lib/log.h>
#include <SDL3/SDL.h>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>
#ifdef __SWITCH__
# include <unistd.h>
#endif

/*
 * Lowest priority that is written to the log file. DEBUG also records every
 * file the game opens, which is useful for tracking down missing assets, but
 * produces a lot of output. Raise to SDL_LOG_PRIORITY_INFO to reduce it.
 */
#define NFS_LOG_LEVEL   SDL_LOG_PRIORITY_DEBUG

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
    fprintf(s_logFile, "[%7llu.%03llu] %s%s\n", ms / 1000, ms % 1000, prefix, message);
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
