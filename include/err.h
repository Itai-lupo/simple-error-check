#pragma once

#include <stdint.h>
#include <time.h>
typedef struct
{
	union {
		struct
		{
			uint64_t fileId : 12;
			uint64_t line : 12;
			uint64_t systemType : 8;
			uint64_t subSystemType : 8;
			uint64_t errorCode : 21;
			uint64_t severity : 3;
		};
		uint64_t value;
	};

} err_t;

#define NO_ERRORCODE                                                                                                   \
	{                                                                                                                  \
		.value = 0                                                                                                     \
	}

#define IS_ERROR(err) (err.value != 0)

#ifndef TRACE_MACRO
#error "please provide a TRACE_MACRO(err_t err) to use"
#endif //! TRACE_MACRO

#ifndef HANDLE_MACRO
#define HANDLE_MACRO(err) goto cleanup;
#endif // !HANDLE_MACRO

#ifndef DEFAULT_ERRORCODE
#define DEFAULT_ERRORCODE (uint64_t) errno
#endif // !DEFAULT_ERRORCODE

#ifndef SYSTEM
#define SYSTEM 0
#endif // !SYSTEM

#ifndef SUBSYSTEM
#define SUBSYSTEM 0
#endif // !SUBSYSTEM

#ifndef FILE_ID
#define FILE_ID 0
#endif // !FILE_ID

#define CONSTRACT_ERR(errCode)                                                                                         \
	err = err_t{                                                                                                       \
		.fileId = FILE_ID,                                                                                             \
		.line = __LINE__,                                                                                              \
		.systemType = SYSTEM,                                                                                          \
		.subSystemType = SUBSYSTEM,                                                                                    \
		.errorCode = errCode,                                                                                          \
		.severity = 5,                                                                                                 \
	};

#define CHECK_ERRORCODE(exp, errCode)                                                                                  \
	if (!(exp)) [[unlikely]]                                                                                             \
	{                                                                                                                  \
		CONSTRACT_ERR(errCode);                                                                                        \
		TRACE_MACRO(err);                                                                                              \
		HANDLE_MACRO(err);                                                                                             \
	}

#define CHECK_NOTRACE_ERRORCODE(exp, errCode)                                                                          \
	if (!(exp)) [[unlikely]]                                                                                             \
	{                                                                                                                  \
		CONSTRACT_ERR(errCode);                                                                                        \
		HANDLE_MACRO(err);                                                                                             \
	}

#define CHECK_NOHANDLE_ERRORCODE(exp, errCode)                                                                         \
	if (!(exp)) [[unlikely]]                                                                                             \
	{                                                                                                                  \
		CONSTRACT_ERR(errCode);                                                                                        \
		TRACE_MACRO(err);                                                                                              \
	}

#define RETHROW(exp)                                                                                                   \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			TRACE_MACRO(err);                                                                                          \
			HANDLE_MACRO(err);                                                                                         \
		}                                                                                                              \
	}

#define RETHROW_NOHANDLE(exp)                                                                                          \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			TRACE_MACRO(err);                                                                                          \
		}                                                                                                              \
	}

#define RETHROW_NOTRACE(exp)                                                                                           \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			HANDLE_MACRO(err);                                                                                         \
		}                                                                                                              \
	}

#define CHECK(exp) CHECK_ERRORCODE(exp, DEFAULT_ERRORCODE)
#define CHECK_NOTRACE(exp) CHECK_NOTRACE_ERRORCODE(exp, DEFAULT_ERRORCODE)
#define CHECK_NOHANDLE(exp) CHECK_NOTRACE_ERRORCODE(exp, DEFAULT_ERRORCODE)

#define WARN(exp) CHECK_NOHANDLE(exp)

#define QUITE_RETHROW(exp) RETHROW_NOTRACE(exp)
#define REWARN(exp) RETHROW_NOTRACE(exp)

#define THROWS [[nodiscard]]
