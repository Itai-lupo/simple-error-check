#pragma once

#include "defines/checkImpls.h"
#define CHECK_NOTRACE_ERRORCODE(exp, errCode) CHECK_BASE_NOTRACE(exp, errCode, SYSTEM, SUBSYSTEM, 5, HANDLE_MACRO())


#define CHECK_ERRORCODE(exp, errCode) CHECK_ERRORCODE_TRACE(exp, errCode, "")
#define CHECK_TRACE(exp, msg, ...) CHECK_ERRORCODE_TRACE(exp, DEFAULT_ERRORCODE, msg __VA_OPT__(, ) __VA_ARGS__)

#define CHECK_NOHANDLE_ERRORCODE(exp, errCode) CHECK_NOHANDLE_ERRORCODE_TRACE(exp, errCode, "")
#define CHECK_NOHANDLE_TRACE(exp, msg, ...)                                                                            \
	CHECK_NOHANDLE_ERRORCODE_TRACE(exp, DEFAULT_ERRORCODE, msg __VA_OPT__(, ) __VA_ARGS__)

#define CHECK(exp) CHECK_ERRORCODE(exp, DEFAULT_ERRORCODE)
#define CHECK_NOTRACE(exp) CHECK_NOTRACE_ERRORCODE(exp, DEFAULT_ERRORCODE)
#define CHECK_NOHANDLE(exp) CHECK_NOHANDLE_ERRORCODE(exp, DEFAULT_ERRORCODE)

#define WARN(exp) CHECK_NOHANDLE(exp)
#define QUITE_CHECK(exp) CHECK_NOTRACE(exp)


