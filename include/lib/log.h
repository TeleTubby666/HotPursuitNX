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

/* Writes a formatted line to the log file (and the default sink). */
void logPrintf(const char* fmt, ...)
#if defined(__GNUC__)
    __attribute__((format(printf, 1, 2)))
#endif
    ;

}

#endif
