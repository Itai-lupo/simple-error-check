#pragma once

#include <err.h>

#define RETHROW_BASE(exp, traceWith, handleWith)                                                                       \
	err = exp;                                                                                                         \
	if (IS_ERROR(err)) [[unlikely]]                                                                                   \
	{                                                                                                                  \
		traceWith;                                                                                                     \
		handleWith;                                                                                                    \
	}

#define RETHROW_BASE_NOTRACE(exp, handleWith) RETHROW_BASE(exp, NONE, handleWith)


