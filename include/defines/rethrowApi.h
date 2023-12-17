/**
 * @file rethrowApi.h
 * @author itai lupo
 * @brief all the rethrows macro you can easily use
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "defines/rethrowImpls.h"

/**
 * @brief handle and trace errors returned from function of type err_t with custom message
 * trace with RETRACE_MACRO
 * handle with HANDLE_MACRO
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @param msg message to print if there was an error
 * @see err_t
 * @see CHECK
 * @see RETRACE_MACRO
 * @see HANDLE_MACRO
 */
#define RETHROW_TRACE(exp, msg, ...) RETHROW_BASE(exp, RETRACE_MACRO(msg, __VA_OPT__(, ) __VA_ARGS__), HANDLE_MACRO())

/**
 * @brief trace errors returned from function of type err_t  with custom message
 * trace with RETRACE_MACRO
 * handle with HANDLE_MACRO
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @param msg message to print if there was an error
 * @see err_t
 * @see CHECK
 * @see RETRACE_MACRO
 * @see HANDLE_MACRO
 */
#define RETHROW_NOHANDLE_TRACE(exp, msg, ...) RETHROW_BASE(exp, RETRACE_MACRO(msg, __VA_OPT__(, ) __VA_ARGS__), NONE)

/**
 * @brief handle and trace errors returned from function of type err_t
 * trace with RETRACE_MACRO
 * handle with HANDLE_MACRO
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @see err_t
 * @see CHECK
 * @see RETRACE_MACRO
 * @see HANDLE_MACRO
 */
#define RETHROW(exp) RETHROW_TRACE(exp, "")

/**
 * @brief trace errors returned from function of type err_t
 * trace with RETRACE_MACRO
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @see err_t
 * @see CHECK
 * @see RETRACE_MACRO
 */
#define RETHROW_NOHANDLE(exp) RETHROW_NOHANDLE_TRACE(exp, "")

/**
 * @brief handle errors returned from function of type err_t
 * handle with HANDLE_MACRO
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @see err_t
 * @see CHECK
 * @see HANDLE_MACRO
 */
#define RETHROW_NOTRACE(exp) RETHROW_BASE(exp, NONE, HANDLE_MACRO())

/**
 * @brief alias for RETHROW_NOTRACE
 *
 * @see RETHROW_NOTRACE
 */
#define QUITE_RETHROW(exp) RETHROW_NOTRACE(exp)

/**
 * @brief alias for RETHROW_NOHANDLE
 *
 * @see RETHROW_NOHANDLE
 */
#define REWARN(exp) RETHROW_NOHANDLE(exp)
