#pragma once

#define unlikely(x)     __builtin_expect(!!(x), 0)
#if __cplusplus >= 202002L
#define unlikelyIf(exp)    if (exp) [[unlikely]]                                                                                           
#else 
#define unlikelyIf(exp)   if(unlikely(exp))
#endif
