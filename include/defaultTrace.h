/**
 * @file defaultTrace.h
 * @author itai lupo
 * @brief provide some sort of trace and retrace for you to use
 * if want to print something but not provide your own
 * they use fprintf and print to stderr.
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#ifndef ERROR_FMT
#define ERROR_FMT "error from (%lu:%lu) with code %lu\n"
#endif

#ifndef RETHROW_FMT
#define RETHROW_FMT "rethrow error from (%lu:%lu) with code %lu at %d:%d\n"
#endif

#include <stdio.h>

#ifndef TRACE_MACRO
#define TRACE_MACRO(msg, ...)                                                                                          \
	fprintf(stderr, ERROR_FMT msg, (uint64_t)err.fileId, (uint64_t)err.line,                                           \
			(uint64_t)err.errorCode __VA_OPT__(, ) __VA_ARGS__)
#endif

#ifndef RETRACE_MACRO
#define RETRACE_MACRO(msg, ...)                                                                                        \
	fprintf(stderr, RETHROW_FMT msg, (uint64_t)err.fileId, (uint64_t)err.line, (uint64_t)err.errorCode, FILE_ID,       \
			__LINE__ __VA_OPT__(, ) __VA_ARGS__)
#endif
