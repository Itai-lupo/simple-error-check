#pragma once
#include "types/err_t.h"
#include "defines/unlikely.h"

#ifndef TRACE_MACRO
#pragma message ("please provide TRACE_MACRO to use other wise nothing will be printed")
#define TRACE_MACRO(msg, ...)
#endif //! TRACE_MACRO


#define NONE

#define CHECK_BASE(exp, errCode, st, sst, severity, traceWith, handleWith)                                             \
	unlikelyIf(!(exp))                                                                                                 \
	{                                                                                                                  \
		CONSTRACT_ERR(errCode, st, sst, severity);                                                                     \
		traceWith;                                                                                                     \
		handleWith;                                                                                                    \
	}

#define CHECK_BASE_NOTRACE(exp, errCode, st, sst, severity, handleWith)                                                \
	CHECK_BASE(exp, errCode, st, sst, severity, NONE, handleWith)

#define CHECK_ERRORCODE_TRACE(exp, errCode, msg, ...)                                                                  \
	CHECK_BASE(exp, errCode, SYSTEM, SUBSYSTEM, 5, TRACE_MACRO(msg __VA_OPT__(, ) __VA_ARGS__), HANDLE_MACRO())

#define CHECK_NOHANDLE_ERRORCODE_TRACE(exp, errCode, msg, ...)                                                         \
	CHECK_BASE(exp, errCode, SYSTEM, SUBSYSTEM, 5, TRACE_MACRO(msg __VA_OPT__(, ) __VA_ARGS__), NONE)
