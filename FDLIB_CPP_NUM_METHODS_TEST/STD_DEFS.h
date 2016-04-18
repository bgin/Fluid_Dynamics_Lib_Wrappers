
#ifndef _STD_DEFS_H_
#define _STD_DEFS_H_

#if defined (_DEBUG) && defined (__INTEL_COMPILER)


#ifndef PRECISE_TIMING
#define PRECISE_TIMING 0x1
#include <immintrin.h>
#endif
#ifndef COARSE_TIMING
#define COARSE_TIMING 0x2
#include <Windows.h>
#endif
#elif defined _MSC_VER 

#ifndef PRECISE_TIMING
#define PRECISE_TIMING 0x1
#include <intrin.h>
#endif
#ifndef COARSE_TIMING 
#define COARSE_TIMING 0x2
#include <Windows.h>
#endif
#endif




#define SMALL_NUM_OF_ITERATIONS  (0)
#define MEDIUM_NUM_OF_ITERATIONS (100)
#define LARGE_NUM_OF_ITERATIONS  (1000)
#define COLLECT_TIMING_RESULTS_AS_ARRAY 0x1
#define PRINT_DATA 0x1
#define PRINT_TO_FILE 0x0
#define GEOMETRIC_MEDIAN 0x1
#endif /*_STD_DEFS_H_*/