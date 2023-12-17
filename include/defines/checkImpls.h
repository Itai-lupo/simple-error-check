/**
 * @file checkImpls.h
 * @author itai lupo
 * @brief the base code for checks
 * @version 0.1
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "defines/unlikely.h"
#include "types/err_t.h"


/**
 * @brief used in order to do nothing in the traceWith or handlWith.
 * just a little bit less confusing
 */
#define NONE

/**
 * @brief this check that (exp) is true if it isn't then it runs traceWith with in order to trace the error and then
 * handleWith in order to handle the error.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 * @param st int value of the system of the error
 * @param sst int value of the sub system of the error
 * @param severity int value of the system of the error
 * @param traceWith piece of code to run if there was an error in order to trace the error.
 * @param handleWith piece of code to run if there was an error in order to handle the error.
 *
 * @see err_t
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_BASE(exp, errCode, st, sst, severity, traceWith, handleWith)                                             \
	unlikelyIf(!(exp))                                                                                                 \
	{                                                                                                                  \
		CONSTRACT_ERR(errCode, st, sst, severity);                                                                     \
		traceWith;                                                                                                     \
		handleWith;                                                                                                    \
	}

/**
 * @brief this check that (exp) is true if it isn't then it runs handleWith with err
 * code of errCode.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 * @param st int value of the system of the error
 * @param sst int value of the sub system of the error
 * @param severity int value of the system of the error
 * @param handleWith piece of code to run if there was an error in order to handle the error.
 *
 * @see err_t
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_BASE_NOTRACE(exp, errCode, st, sst, severity, handleWith)                                                \
	CHECK_BASE(exp, errCode, st, sst, severity, NONE, handleWith)

/**
 * @brief this check that (exp) is true if it isn't then it runs TRACE_MACRO(msg ...) and then HANDLE_MACRO() with err
 * code of errCode.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 * @param msg a msg to be printed if there was an error
 *
 * @see err_t
 * @see TRACE_MACRO
 * @see HANDLE_MACRO
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_ERRORCODE_TRACE(exp, errCode, msg, ...)                                                                  \
	CHECK_BASE(exp, errCode, SYSTEM, SUBSYSTEM, 5, TRACE_MACRO(msg __VA_OPT__(, ) __VA_ARGS__), HANDLE_MACRO())

/**
 * @brief this check that (exp) is true if it isn't then it runs TRACE_MACRO(msg ...) with err code of
 * errCode.
 *
 * @param exp a boolean expresion to check(will only be used once)
 * @param errCode int value to put as the errCode(will only be used once)
 * @param msg a msg to be printed if there was an error
 *
 * @see err_t
 * @see TRACE_MACRO
 * @note expect err_t err to be defined and will change it in case exp is false
 */
#define CHECK_NOHANDLE_ERRORCODE_TRACE(exp, errCode, msg, ...)                                                         \
	CHECK_BASE(exp, errCode, SYSTEM, SUBSYSTEM, 5, TRACE_MACRO(msg __VA_OPT__(, ) __VA_ARGS__), NONE)
