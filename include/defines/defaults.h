/**
 * @file defaults.h
 * @author itai lupo
 * @brief defaults values for the checks, you should override them
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#ifndef TRACE_MACRO
#pragma message("please provide TRACE_MACRO to use other wise nothing will be printed")

/**
 * @brief the default thing to do in order to trace errors in checks.
 * you can redefine it to what ever you want
 */
#define TRACE_MACRO(msg, ...)
#endif

#ifndef RETRACE_MACRO
#pragma message("please provide RETRACE_MACRO to use other wise nothing will be printed")

/**
 * @brief the default thing to do in order to trace errors in rethrows.
 * you can redefine it to what ever you want
 */
#define RETRACE_MACRO(msg, ...)
#endif

#ifndef HANDLE_MACRO
/**
 * @brief the default thing to do in order to handle errors in checks and rethrows.
 * you can redefine it to what ever you want
 */
#define HANDLE_MACRO(err) goto cleanup;
#endif

#ifndef DEFAULT_ERRORCODE
#include <errno.h>

/**
 * @brief the default error code to use
 * you can redefine it to what ever you want
 */
#define DEFAULT_ERRORCODE (uint64_t) errno
#endif

#ifndef SYSTEM
/**
 * @brief the default system to use
 * you can redefine it to what ever you want in order to get more info on the error
 */
#define SYSTEM 0
#endif

#ifndef SUBSYSTEM
/**
 * @brief the default system to use
 * you can redefine it to what ever you want in order to get even more info on the error
 */
#define SUBSYSTEM 0
#endif

#ifndef FILE_ID
/**
 * @brief the fileId
 *  this should be a uniq id for every source file.
 */
#define FILE_ID 0
#endif
