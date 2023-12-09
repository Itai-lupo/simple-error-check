#pragma once

#include <err.h>
#include "defines/unlikely.h"

#ifndef RETRACE_MACRO
#pragma message ("please provide RETRACE_MACRO to use other wise nothing will be printed")
#define RETRACE_MACRO(msg, ...)
#endif //! RETRACE_MACRO



#define RETHROW_BASE(exp, traceWith, handleWith)                                                                       \
	err = exp;                                                                                                         \
	unlikelyIf(IS_ERROR(err))                                                                                          \
	{                                                                                                                  \
		traceWith;                                                                                                     \
		handleWith;                                                                                                    \
	}

#define RETHROW_BASE_NOTRACE(exp, handleWith) RETHROW_BASE(exp, NONE, handleWith)


#define RETHROW_TRACE(exp, msg, ...) RETHROW_BASE(exp, RETRACE_MACRO(msg, __VA_OPT__(, ) __VA_ARGS__), HANDLE_MACRO())
#define RETHROW_NOHANDLE_TRACE(exp, msg, ...) RETHROW_BASE(exp, RETRACE_MACRO(msg, __VA_OPT__(, ) __VA_ARGS__), NONE)
