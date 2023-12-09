#pragma once

#define ERROR_FMT "error from (%lu:%lu) with code %lu\n"
#define RETHROW_FMT "rethrow error from (%lu:%lu) with code %lu at %d:%d\n"

#include <stdio.h>
#define TRACE_MACRO(msg, ...) fprintf(stderr, ERROR_FMT msg, (uint64_t)err.fileId, (uint64_t)err.line, (uint64_t)err.errorCode __VA_OPT__(,) __VA_ARGS__)
#define RETRACE_MACRO(msg, ...) fprintf(stderr, RETHROW_FMT msg, (uint64_t)err.fileId, (uint64_t)err.line, (uint64_t)err.errorCode, FILE_ID, __LINE__ __VA_OPT__(,) __VA_ARGS__)


