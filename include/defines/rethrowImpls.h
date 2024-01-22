/**
 * @file rethrowImpls.h
 * @author itai lupo
 * @brief the base code for rethrows
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include "defines/unlikely.h"
#include <err.h>

/**
 * @brief handle and trace errors returned from function of type err_t
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @param traceWith code used to trace the error
 * @param handleWith code used to handle the error with
 *
 * @see err_t
 * @see CHECK
 */
#define RETHROW_BASE(exp, traceWith, handleWith)                                                                       \
	{                                                                                                                  \
		err_t temp_err = exp;                                                                                          \
		unlikelyIf(IS_ERROR(temp_err))                                                                                 \
		{                                                                                                              \
			err = temp_err;                                                                                            \
			traceWith;                                                                                                 \
			handleWith;                                                                                                \
		}                                                                                                              \
	}

/**
 * @brief handle errors returned from function of type err_t
 *
 * @param exp an expression that evaluate to err_t(only used once).
 * @param handleWith code used to handle the error with
 *
 * @see err_t
 * @see CHECK
 */
#define RETHROW_BASE_NOTRACE(exp, handleWith) RETHROW_BASE(exp, NONE, handleWith)
