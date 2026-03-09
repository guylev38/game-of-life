/**
 * @file dlog.h
 * @author guylev38
 * @brief A logging module for C projects.
 * @date 07/03/2026
 */

#ifndef __DLOG_H__
#define __DLOG_H__

/*** Includes ***/

#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*** Enums ***/

typedef enum DLOG_log_level_e
{
    DLOG_LEVEL_DEBUG = 0,
    DLOG_LEVEL_INFO,
    DLOG_LEVEL_WARNING,
    DLOG_LEVEL_ERROR,

    DLOG_LOG_LEVEL_COUNT
} DLOG_log_level_t;

/*** Consts ***/

static const char *LEVEL_STRINGS[DLOG_LOG_LEVEL_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};

/*** Defines ***/

#define LOG_BUFFER_SIZE (500)
#define TIME_BUFFER_SIZE (26)
#define DEFAULT_FMT "[%s] [%s] (%s:%d) %s():"
#define DATE_FMT "%d/%m/%Y %H:%M:%S"

/*** Macros ***/

#define DLOG_DEBUG(fmt, ...) \
    _DLOG_dispatch_log_var_wrapper(DLOG_LEVEL_DEBUG, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define DLOG_INFO(fmt, ...) \
    _DLOG_dispatch_log_var_wrapper(DLOG_LEVEL_INFO, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define DLOG_WARNING(fmt, ...) \
    _DLOG_dispatch_log_var_wrapper(DLOG_LEVEL_WARNING, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)
#define DLOG_ERROR(fmt, ...) \
    _DLOG_dispatch_log_var_wrapper(DLOG_LEVEL_ERROR, __FILE__, __LINE__, __func__, fmt, ##__VA_ARGS__)

/*** Functions ***/

/**
 * @brief Writes the current time to a given buffer.
 *
 * @param[out] time_buf The buffer to write the time into.
 */
static inline void _DLOG_get_time(char *time_buf)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t)
    {
        strftime(time_buf, TIME_BUFFER_SIZE, DATE_FMT, t);
    }
    else
    {
        time_buf[0] = '\0'; // Safety fallback.
    }
}

/**
 * @brief Format the prefix of the log.
 *
 * @param[in] level The log level.
 * @param[in] file The file from which the log was called.
 * @param[in] line The line on which the log was called.
 * @param[in] func The function from which the log was called.
 * @param[out] prefix The prefix buffer into which the formatted prefix will be written.
 */
static inline void _DLOG_format_prefix(DLOG_log_level_t level,
                                       char *file,
                                       int line,
                                       const char *func, char *prefix)
{
    char time_buf[TIME_BUFFER_SIZE];
    _DLOG_get_time(time_buf);

    sprintf(prefix, DEFAULT_FMT, time_buf, LEVEL_STRINGS[level], file, line, func);
}

/**
 * @brief Dispatch a log.
 *
 * @param[in] level The log level
 * @param[in] file The file from which the log was called.
 * @param[in] line The line on which the log was called.
 * @param[in] func The function from which the log was called.
 * @param[in] fmt The format of the log message.
 * @param[in] args The arguments of the log message.
 */
static inline void _DLOG_dispatch_log(DLOG_log_level_t level,
                                      char *file,
                                      int line,
                                      const char *func,
                                      char *fmt, va_list args)
{
    char buffer[LOG_BUFFER_SIZE];
    char prefix[LOG_BUFFER_SIZE];

    _DLOG_format_prefix(level, file, line, func, prefix);

    vsnprintf(buffer, sizeof(buffer), fmt, args);

    fprintf(stdout, "%s %s", prefix, buffer);
}

/**
 * @brief Variardic wrapper for the dispatch_log function.
 *
 * @param[in] level The log level.
 * @param[in] file The file from which the log was called.
 * @param[in] line The line on which the log was called.
 * @param[in] func The function from which the log was called.
 * @param[in] fmt The foramt of the log message.
 * @param[in] ... The arguments of the log message.
 */
static inline void _DLOG_dispatch_log_var_wrapper(DLOG_log_level_t level,
                                                  char *file,
                                                  int line,
                                                  const char *func, char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    _DLOG_dispatch_log(level, file, line, func, fmt, args);
    va_end(args);
}
#endif