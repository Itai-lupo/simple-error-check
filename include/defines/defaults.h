#pragma once

#ifndef HANDLE_MACRO
#define HANDLE_MACRO(err) goto cleanup;
#endif // !HANDLE_MACRO

#ifndef DEFAULT_ERRORCODE
#include <errno.h>
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
