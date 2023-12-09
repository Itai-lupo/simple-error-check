#pragma once
#include "defines/errType.h"
#include "defines/unlikely.h"

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

