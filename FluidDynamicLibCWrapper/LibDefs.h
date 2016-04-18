#ifndef _LIB_DEFS_H_
#define _LIB_DEFS_H_
#include <crtdbg.h>
#include <stdio.h>
#include <crtdefs.h>
//global defines
//#define UPPERCASE 0x1
#define LOWERCASE 0x2


// SIMD ARCH defines
#if defined (_MSC_VER_)
#include <intrin.h>
#elif defined (__INTEL_COMPILER)

#if defined (__AVX__) || defined (__AVX2__)
#include <immintrin.h>
#elif defined (__SSE4_2__)
#include <nmmintrin.h>
#elif defined (__SSE4_1__)
#include <smmintrin.h>
#elif defined (__SSSE3__)
#include <tmmintrin.h>
#elif defined (__SSE3__)
#include <pmmintrin.h>
#elif defined (__SSE2__)
#include <emmintrin.h>
#elif defined (__SSE__)
#include <xmmintrin.h>
#elif defined (__MMX__)
#include <mmintrin.h>
#else
//#error UNSUPPORTED PROCESSOR
#endif
#endif

// Return values definitions
#define FDLIB_ERROR 0xFFFFFFFF
#define FDLIB_SUCCESS 0x0
#define FDLIB_ERROR_MEM_ALLOC 0xFFFFFFFE
#define FDLIB_ERROR_INVALID_PARAM 0xFFFFFFFD
#define FDLIB_ERROR_RDRAND_FAIL 0xFFFFFFFC
#define FDLIB_ERROR_FUNC_CALL_FAIL 0xFFFFFFFB
#ifndef FDLIB_INT
#define FDLIB_INT int
#endif
// Default size for fortran arrays as in FDLIB source.
#ifndef FDLIB_ARRAY_10
#define FDLIB_ARRAY_10 10
#endif
#ifndef FDLIB_ARRAY_100 
#define FDLIB_ARRAY_100 100
#endif
#ifndef FDLIB_ARRAY_128
#define FDLIB_ARRAY_128 128
#endif
#ifndef ALIGN_32
#define ALIGN_32 (32)
#endif
#ifndef ALIGN_16
#define ALIGN_16 (16)
#endif

#ifndef PERF_TEST
#define PERF_TEST 0x1
#endif
#ifndef PRINT_TO_FILE
#define PRINT_TO_FILE 0x0
#endif
#ifndef PRINT_TO_SCREEN
#define PRINT_TO_SCREEN 0x1
#endif
#endif /*_LIB_DEFS*/