#pragma once

#include <err.h>
#include "defines/unlikely.h"

#define RETHROW_BASE(exp, traceWith, handleWith)                                                                       \
	err = exp;                                                                                                         \
	unlikelyIf(IS_ERROR(err))                                                                                          \
	{                                                                                                                  \
		traceWith;                                                                                                     \
		handleWith;                                                                                                    \
	}

#define RETHROW_BASE_NOTRACE(exp, handleWith) RETHROW_BASE(exp, NONE, handleWith)
