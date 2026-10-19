#ifndef LIB_LOG_H_
#define LIB_LOG_H_

namespace win32
{

/*
 * Mirrors everything that goes through SDL_Log* (including the game's own
 * OutputDebugString output) into a text file. The previous log is kept as
 * "<path>.prev" so that a crash can still be inspected after a restart.
 * Every line is flushed immediately, so the file is complete up to the
 * moment the process dies.
 *
 * Output still goes to the default SDL log sink as well.
 */
void initLog(const char* path);

/* Logs the load address of the program (to resolve addresses of crash reports). */
void logImageBase();

/* Writes a formatted line to the log file (and the default sink). */
void logPrintf(const char* fmt, ...)
#if defined(__GNUC__)
    __attribute__((format(printf, 1, 2)))
#endif
    ;

/*
 * Watchdog for hangs (the process freezes without crashing).
 *
 * Threads announce blocking operations with WatchScope; the main loop calls
 * watchdogHeartbeat() whenever it pumps messages. A background thread reports
 * threads that stay blocked for several seconds, or a main loop that stopped
 * pumping, together with the last Win32 API function every thread called
 * (as an offset that aarch64-none-elf-addr2line can resolve).
 */
void startWatchdog();
void stopWatchdog();
void watchdogHeartbeat();
void watchdogEnter(const char* what, unsigned arg, const char* detail);
void watchdogLeave();
void watchdogNoteApi(const void* function);

struct WatchScope
{
    WatchScope(const char* what, unsigned arg = 0, const char* detail = 0)
    {
        watchdogEnter(what, arg, detail);
    }
    ~WatchScope()
    {
        watchdogLeave();
    }
};

}

#endif
