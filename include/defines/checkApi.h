/**
 * @file checkApi.h
 * @author itai lupo
 * @brief all the checks macro you can easily use
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "defines/checkImpls.h"

/**
 * @brief this check that (exp) is true if it isn't then it runs HANDLE_MACROO() with err code of errCode
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 *
 * @see err_t
 * @see HANDLE_MACRO
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOTRACE_ERRORCODE(exp, errCode) CHECK_BASE_NOTRACE(exp, errCode, SYSTEM, SUBSYSTEM, 5, HANDLE_MACRO())

/**
 * @brief this check that (exp) is true if it isn't then it runs HANDLE_MACROO() and TRACE_MACRO("") with err code of
 * errCode.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 *
 * @see err_t
 * @see HANDLE_MACRO
 * @see TRACE_MACRO
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_ERRORCODE(exp, errCode) CHECK_ERRORCODE_TRACE(exp, errCode, "")

/**
 * @brief this check that (exp) is true if it isn't then it runs HANDLE_MACROO() and TRACE_MACRO(msg ...) with err code
 * of DEFAULT_ERRORCODE.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param msg a msg to be printed if there was an error
 *
 * @see err_t
 * @see HANDLE_MACRO
 * @see TRACE_MACRO
 * @see DEFAULT_ERRORCODE
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_TRACE(exp, msg, ...) CHECK_ERRORCODE_TRACE(exp, DEFAULT_ERRORCODE, msg __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief this check that (exp) is true if it isn't then it runs TRACE_MACRO("") with err code of
 * errCode.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 *
 * @see err_t
 * @see TRACE_MACRO
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOHANDLE_ERRORCODE(exp, errCode) CHECK_NOHANDLE_ERRORCODE_TRACE(exp, errCode, "")

/**
 * @brief this check that (exp) is true if it isn't then it runs TRACE_MACRO(msg ...) with err code
 * of DEFAULT_ERRORCODE.
 *
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param msg a msg to be printed if there was an error
 *
 * @see err_t
 * @see TRACE_MACRO
 * @see DEFAULT_ERRORCODE
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOHANDLE_TRACE(exp, msg, ...)                                                                            \
	CHECK_NOHANDLE_ERRORCODE_TRACE(exp, DEFAULT_ERRORCODE, msg __VA_OPT__(, ) __VA_ARGS__)

/**
 * @brief this check that (exp) is true if it isn't then it runs HANDLE_MACROO() and TRACE_MACRO("") with err code
 * of DEFAULT_ERRORCODE.
 *
 * @param exp a boolean expresion to check(will only be used once)
 *
 * @see err_t
 * @see HANDLE_MACRO
 * @see TRACE_MACRO
 * @see DEFAULT_ERRORCODE
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK(exp) CHECK_ERRORCODE(exp, DEFAULT_ERRORCODE)

/**
 * @brief this check that (exp) is true if it isn't then it runs HANDLE_MACROO() with err code
 * of DEFAULT_ERRORCODE.
 *
 * @param exp a boolean expresion to check(will only be used once)
 *
 * @see err_t
 * @see HANDLE_MACRO
 * @see DEFAULT_ERRORCODE
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOTRACE(exp) CHECK_NOTRACE_ERRORCODE(exp, DEFAULT_ERRORCODE)

/**
 * @brief this check that (exp) is true if it isn't then it runs TRACE_MACRO("") with err code
 * of DEFAULT_ERRORCODE.
 *
 * @param exp a boolean expresion to check(will only be used once)
 *
 * @see err_t
 * @see TRACE_MACRO
 * @see DEFAULT_ERRORCODE
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOHANDLE(exp) CHECK_NOHANDLE_ERRORCODE(exp, DEFAULT_ERRORCODE)

/**
 * @brief alias for CHECK_NOHANDLE
 *
 * @see CHECK_NOHANDLE
 */
#define WARN(exp) CHECK_NOHANDLE(exp)

/**
 * @brief alias for CHECK_NOTRACE
 *
 * @see CHECK_NOTRACE
 */
#define QUITE_CHECK(exp) CHECK_NOTRACE(exp)
