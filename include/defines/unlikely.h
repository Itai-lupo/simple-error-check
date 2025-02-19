/**
 * @file unlikely.h
 * @author itai lupo
 * @brief cpp 20 added [[unlikely]] before it there was something else which is platform dependent and less code, if I
 * can I wan to use the new unlikely
 * @version 0.1
 * @date 2023-12-17
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#if __cplusplus >= 202002L
/**
 * @brief if with the [[unlikely]] attr, if it is less then cpp20 then it will be unlikely(exp) instead
 */
#define unlikelyIf(exp) if (exp) [[unlikely]]
#else
#define unlikely(x) __builtin_expect(!!(x), 0)
#define unlikelyIf(exp) if (unlikely(exp))
#endif
