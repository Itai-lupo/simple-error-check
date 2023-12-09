#pragma once

#include "defines/rethrowImpls.h"

#define RETHROW(exp) RETHROW_TRACE(exp, "")
#define RETHROW_NOHANDLE(exp) RETHROW_NOHANDLE_TRACE(exp, "")
#define RETHROW_NOTRACE(exp) RETHROW_BASE(exp, NONE, HANDLE_MACRO())

#define QUITE_RETHROW(exp) RETHROW_NOTRACE(exp)
#define REWARN(exp) RETHROW_NOHANDLE(exp)
