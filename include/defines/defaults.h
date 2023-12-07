#pragma once

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


