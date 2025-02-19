/**
 * @file err_t.h
 * @author itai lupo
 * @brief the err_t type
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <stdint.h>
#include <time.h>

/**
 * @brief this is the value that CHECKS and RETHROWS use
 *
 * @note if you want to use RETHROW then you need to return this struct
 *
 * @see CHECK
 * @see RETHROW
 *
 * @var err_t::fileId
 * the file the error happened on
 * @see FILE_ID
 *
 * @var err_t::line
 * the line the error happened on
 *
 * @var err_t::systemType
 * the system the error happened on,
 * can be used to gain more info on the error or handle the error on a higher level.
 * @var err_t::subSystemType
 * further specialization of the system.
 * @var err_t::errorCode
 * the error that happend
 * @var err_t::severity
 * the severity of the error, can be use to mask some errors.
 * @var err_t::value
 * use to check if any of the values is set or to clear the error.
 */
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

/**
 * @brief init a new err_t with errors
 */
#define NO_ERRORCODE                                                                                                   \
	(err_t)                                                                                                            \
	{                                                                                                                  \
		.value = 0                                                                                                     \
	}

/**
 * @brief constract err_t with default parms.
 *
 * @param errCode the error code to use
 * @see err_t::errorCode
 * @param st the system to use
 * @see err_t::systemType
 * @param sst the subSystemType to use
 * @see err_t::subSystemType
 * @param severityVal the severity to use
 * @see err_t::severity
 */
#define CONSTRACT_ERR(errCode, st, sst, severityVal)                                                                   \
	err = (err_t)                                                                                                      \
	{                                                                                                                  \
		.fileId = FILE_ID, .line = __LINE__, .systemType = st, .subSystemType = sst, .errorCode = errCode,             \
		.severity = severityVal,                                                                                       \
	}

/**
 * @brief is err_t an error, if any of the values is set(value != 0)
 */
#define IS_ERROR(err) (err.value != 0)

/**
 * @brief you can use to mark a function as returned an error that can't be ignored.
 */
#define THROWS [[nodiscard]]
