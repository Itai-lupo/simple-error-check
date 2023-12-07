#pragma once


#define RETHROW(exp)                                                                                                   \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			TRACE_MACRO("");                                                                                          \
			HANDLE_MACRO();                                                                                         \
		}                                                                                                              \
	}

#define RETHROW_NOHANDLE(exp)                                                                                          \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			TRACE_MACRO("");                                                                                          \
		}                                                                                                              \
	}

#define RETHROW_NOTRACE(exp)                                                                                           \
	{                                                                                                                  \
		err_t temp = exp;                                                                                              \
		if (IS_ERROR(temp))                                                                                            \
		{                                                                                                              \
			err.value = temp.value;                                                                                    \
			HANDLE_MACRO();                                                                                         \
		}                                                                                                              \
	}


