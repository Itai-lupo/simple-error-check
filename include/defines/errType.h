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


#define CONSTRACT_ERR(errCode, st, sst, severityVal)                                                                   \
	err = err_t{                                                                                                       \
		.fileId = FILE_ID,                                                                                             \
		.line = __LINE__,                                                                                              \
		.systemType = st,                                                                                              \
		.subSystemType = sst,                                                                                          \
		.errorCode = errCode,                                                                                          \
		.severity = severityVal,                                                                                       \
	};

#define IS_ERROR(err) (err.value != 0)
