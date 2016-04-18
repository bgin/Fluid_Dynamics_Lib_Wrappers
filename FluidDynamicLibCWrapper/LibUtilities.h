
#ifndef _LIBUTILITIES_H_
#define _LIBUTILITIES_H_
#include "LibDefs.h"
// ABS(x) value of x
#ifndef ABS
#define ABS(x) (((x < 0)) ? -(x) : (x))
#endif

// Max(x,y)
#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

// Min(x,y)
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef PRINT
void PRINT(const double * a, const FDLIB_INT n, const FDLIB_INT m)
{
	//fortran style
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != m; ++j)
		{
			printf("[j + n * i] = %5.15f\n", a[j * n +  i]);
		}
		printf("\n");
	}
	return;
}
#endif

FDLIB_INT COPY1D(double *__restrict dest, const double *__restrict source, const int bytes_to_copy)
{
#if defined (_DEBUG)
	_ASSERTE((dest != NULL) && (source != NULL) && (bytes_to_copy > 0));
#else

	if ((dest == NULL) && (source == NULL) && (bytes_to_copy <= 0))
	{
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif

	for (int i = 0; i != bytes_to_copy; ++i)
	{
		*dest++ = *source++;
	}

	return FDLIB_SUCCESS;
}

#endif /*_LIBUTILITIES_H_*/