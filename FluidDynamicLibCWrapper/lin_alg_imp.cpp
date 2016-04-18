
// This is an implementation of C interface to FDLIB 14.0 f77 source
#include "lin_alg_imp.h"
#include "../FluidDynamicLibCWrapper/LibUtilities.h"
#include "../FluidDynamicsLibCPPWrapper/StatDistributionWrapper.h"

// TO DO:
// Remove exit() and insert int error_info returned from high and mid level wrappers.

// Implementation of high-level wrapper interface for chol_c subroutine
FDLIB_INT fdlib_chol_c(double * l, double * a, FDLIB_INT n)
{
#if defined (_DEBUG)
	_ASSERTE((l != NULL) && (a != NULL) && (n == 10));
#else
	if((l == NULL) || (a == NULL) || (n != 10))
	{
		printf("ERROR in fdlib_chol_c() wrapper procedure - Null Pointer or Invalid Array Size....returning\n");
		return FDLIB_ERROR;
	}
#endif

	CHOL_C(&a[0], &l[0], &n);
	return FDLIB_SUCCESS;
}

// Implementation of high-level wrapper interface for chol_r subroutine
FDLIB_INT fdlib_chol_r(double * l, double * a, FDLIB_INT n)
{
#if defined (_DEBUG)
	_ASSERTE((l != NULL) && (a != NULL) && (n == 10));
#else

	printf("ERROR in fdlib_chol_r() wrapper procedure - Null Pointer or Invalid Array Size.... exiting\n");
	return FDLIB_ERROR;
#endif

	CHOL_R(&l[0], &a[0], &n);
	return FDLIB_SUCCESS;
}

// Implementaion of high level wrapper interface for det_hess_l subroutine
FDLIB_INT fdlib_det_hess_l(int  n, double * l, double  det)
{
#if defined (_DEBUG)
	_ASSERTE((l != NULL) && (n == FDLIB_ARRAY_10));
#else
	if (l == NULL || n != 10)
	{
		printf("ERROR in fdlib_det_hess_l() wrapper procedure - Null Pointer or Invalid Array Size.... exiting\n");
		return FDLIB_ERROR
	}
#endif

	DET_HESS_L(&n, &l[0], &det);
	return FDLIB_SUCCESS;
}

// Implementation of high level wrapper interface for det_hess_u subroutine
FDLIB_INT fdlib_det_hess_u(int n, double * l, double det)
{
#if defined (_DEBUG)
	_ASSERTE((l != NULL) && (n == FDLIB_ARRAY_10));
#else
	if((l == NULL ) && (n != 10))
	{
		printf("ERROR in fdlib_det_hess_u() wrapper procedure - NULL Pointer or Invalid Array Size.... exit\n");
		return FDLIB_ERROR;
	}
#endif

	DET_HESS_U(&n, &l[0], &det);
	return FDLIB_SUCCESS;
}

 // Implementation of high level wrapper interface for Det_33c() subroutine.
FDLIB_INT fdlib_det_33c(double * AR , double * AI, double DetR, double DetI)
{
#if defined (_DEBUG)
	_ASSERTE((AR != NULL) && (AI != NULL));
#else
	if((AR == NULL) && (AI == NULL))
	{
		printf("ERROR in fdlib_det_33c() wrapper procedure - Null Pointer.... exiting\n");
		return FDLIB_ERROR;
	}
#endif

	DET_33C(&AR[0], &AI[0], &DetR, &DetI);
	return FDLIB_SUCCESS;
}

// Implementation of high level wrapper interface for Det_33c() subroutine.
FDLIB_INT fdlib_det_44c(double * AR, double * AI, double DetR, double DetI)
{
#if defined (_DEBUG)
	_ASSERTE((AR != NULL) && (AI != NULL));
#else
	if ((AR == NULL) && (AI == NULL))
	{
		printf("ERROR in fdlib_det_44c() wrapper procedure - Null Pointer.... exiting\n");
		return FDLIB_ERROR;
	}
#endif

	DET_44C(&AR[0], &AI[0], &DetR, &DetI);
	return FDLIB_SUCCESS;
}

// Implementation of high level wrapper interface for inv_l subroutine.
FDLIB_INT fdlib_inv_l(FDLIB_INT n, double * a, double * b)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (b != NULL));
#else
	if((a == NULL) && (b == NULL))
	{
		printf("ERROR in fdlib_inv_l() wrapper procedure - Null Pointer... exiting\n");
		return FDLIB_ERROR;
	}
#endif

	INV_L(&n, &a[0], &b[0]);
	return FDLIB_SUCCESS;
}

 // Implementation of high level wrapper interface for inv_u subroutine.
FDLIB_INT fdlib_inv_u(FDLIB_INT n, double * a, double * b)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (b != NULL));
#else
	if((a == NULL) && (b == NULL))
	{
		printf("ERROR in fdlib_inv_u() wrapper procedure - Null Pointer... exiting\n");
		return FDLIB_ERROR;
	}
#endif

	INV_U(&n, &a[0], &b[0]);
	return FDLIB_SUCCESS;
}

 // Implementation of high level wrapper interface for ldu subroutine.
FDLIB_INT fdlib_ldu(FDLIB_INT n, double * a, double * l, double * d, double * u)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (l != NULL) && (d != NULL) && (u != NULL));
#else
	if((a == NULL) && (l == NULL) && (d == NULL) && (u == NULL))
	{
		return FDLIB_ERROR;
	}
#endif

	LDU(&n, &a[0], &l[0], &d[0], &u[0]);
	return FDLIB_SUCCESS;
}

 // Implementation of high level wrapper interface for crout subroutine.
FDLIB_INT fdlib_crout(FDLIB_INT n, double * a, double * l, double * u)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_100) && (a != NULL) && (l != NULL) && (u != NULL));
#else
	 
	if ((n != 100) && (a == NULL) && (l == NULL ) && (u == NULL))
	{
		printf("ERROR in fdlib_crout() wrapper routine - Null Pointer or Invalid Array Size... exiting\n");
		return FDLIB_ERROR;
	}
	     
#endif

	CROUT(&n, &a[0], &l[0], &u[0]);
	return FDLIB_SUCCESS;
}

 // Implementation of high level wrapper interface for lu_d_t subroutine.
FDLIB_INT fdlib_lu_d_t(FDLIB_INT n, double * c, double * a, double * b, double * l, double * u)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (c != NULL) && (a != NULL) && (b != NULL) && (l != NULL) && (u != NULL));
#else
	if((n != FDLIB_ARRAY_10) && (c == NULL) && (a == NULL) && (b == NULL) && (l == NULL)
		|| (u == NULL))
	{
		printf("FATAL ERROR in fdlib_lu_d_t() wrapper routine in FILE: %s, in FUNCTION: %s at LINE# %d",
			__FILE__, __FUNCTIONW__, __LINE__);
	}
#endif

	LU_D_T(&n, &c[0], &a[0], &b[0], &l[0], &u[0]);
	return FDLIB_SUCCESS;
}
 
 // Implementation of high level wrapper interface for qr_gs subroutine.
FDLIB_INT fdlib_qr_gs(double * a, FDLIB_INT n, FDLIB_INT index, double * q, double * r)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (n == FDLIB_ARRAY_128) && (index >= 1 && index <= 2) && (q != NULL)
		&& (r != NULL));
#else

	if ((a == NULL) && (n != FDLIB_ARRAY_128) && (index < 1 || index > 2) && (q == NULL)
		&& (r == NULL))
	{
		printf("FATAL ERROR in fdlib_qr_gs() wrapper routine in FILE: %s, in FUNCTION: %s at LINE# %d",
			__FILEW__, __FUNCTIONW__, __LINE__);
	}
#endif

	QR_GS(&a[0], &n, &index, &q[0], &r[0]);
	return FDLIB_SUCCESS;
}

 // Implementation of High level interface for QR_REFLEX subroutine.
FDLIB_INT fdlib_qr_reflex(double * a, FDLIB_INT n, double * q, double * r)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (n == FDLIB_ARRAY_128) && (q != NULL) && (r != NULL));
#else
	if((a == NULL) && (n != FDLIB_ARRAY_128) && ( q == NULL) && (r != NULL))
	{
		printf("FATAL ERROR in fdlib_qr_reflex() wrapper routine in FILE: %s, in FUNCTION: %s at LINE# %d", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM | FDLIB_ERROR_MEM_ALLOC;
	}
#endif

	QR_REFLEX(&a[0], &n, &q[0], &r[0]);
	return FDLIB_SUCCESS;
}

  // Implementation of High Level interface for QR_ROT subroutine.
FDLIB_INT fdlib_qr_rot(double * a, FDLIB_INT n, double * q, double * r)
{
#if defined (_DEBUG)
	_ASSERTE((a != NULL) && (n == FDLIB_ARRAY_128) && (q != NULL) && (r != NULL));
#else
	if((a == NULL) && (n != FDLIB_ARRAY_128) && ( q == NULL) && (r != NULL))
	{
		printf("FATAL ERROR in fdlib_qr_rot() wrapper routine in FILE: %s, in FUNCTION: %s at LINE# %d", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM | FDLIB_ERROR_MEM_ALLOC;
	}
#endif

	QR_ROT(&a[0], &n, &q[0], &r[0]);
	return FDLIB_SUCCESS;
}
 //
 //TO DO
 // Implement medium level wrappers

 /*  FDLIB_INT fdlib_lm_chol_c(FDLIB_INT n, int range_min, int range_max)
  *  Implementation of medium-level wrapper for chol_c subroutine.
  *  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
  *  Processes and encapsultes possible implementation of chol_c driver.
  *  Parameters: FDLIB_INT n, int range_min, int range_max
  *  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
  */
 
FDLIB_INT fdlib_ml_chol_c(FDLIB_INT n, int range_min, int range_max)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (range_min < range_max));
#else
	if((n != FDLIB_ARRAY_10) && (range_min >= range_max))
	{
		printf("FATAL ERROR in fdlib_ml_chol_c() wrapper routine in FILE: %s, in FUNCTION: %s at LINE# %d",__FILEW__, __FUNCTIONW__, __LINE__);
			
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif

	
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tMemory allocation failed in fdlib_ml_chol_c(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]",a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tMemory allocation failed in fdlib_ml_chol_c(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]",l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	
#if defined (__INTEL_COMPILER)
	unsigned int status = 0xFFFFFFFF;
	const  unsigned	long long MAX_VALUE = 4294967295ULL * 100;
	const double INV_RAND_MAX = ((double)1.0 / MAX_VALUE);
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			unsigned int rand = 0;
			status = _rdrand32_step(&rand);
			if (status == 0)
			{
				_mm_free(a);
				_mm_free(l);
				return FDLIB_ERROR_RDRAND_FAIL;
			}
			else
			{

				a[j * n + i] = (double)rand * INV_RAND_MAX * (range_max - range_min) + range_max;
				
			

			} 
		}
	}
#elif defined (_MSC_VER_)

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_max;
		}
	}
#endif

	

	CHOL_C(&l[0], &a[0], &n);
#if defined (_DEBUG)
	
	PRINT(a, n, n);
	PRINT(l, n, n);
#endif
	_mm_free(a);
	_mm_free(l);

	return FDLIB_SUCCESS;



}

/*  FDLIB_INT fdlib_lm_chol_car(FDLIB_INT n, double * values)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Parameters: FDLIB_INT n, double * values, const int _size.
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_car(FDLIB_INT n, double * __restrict   values, const int _size)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (values != NULL));
	_ASSERTE((n - _size) == 0);
#else
	if((n != FDLIB_ARRAY_10) && (values == NULL) && ((n - _size) != 0))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_car() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif

	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_car(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_car(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = values[j * n + i];
			
		}
	}

	CHOL_C(&l[0], &a[0], &n);

#if defined (_DEBUG)

	PRINT(a, n, n);
	PRINT(l, n, n);
#endif
	_mm_free(a);
	_mm_free(l);

	return FDLIB_SUCCESS;
}

/*  FDLIB_INT fdlib_lm_chol_cran(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to UniformDistributionWrapper<double>::uniform_real_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/

FDLIB_INT fdlib_ml_chol_cran(FDLIB_INT n, const int num_of_engine) //TO DO Implement tomorrow.
{
#if defined _DEBUG
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((n != FDLIB_ARRAY_10) || (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif

	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined  __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	
	bool b_result = false;
	//b_result = fdlibcppwrapper::UniDistributions<double>::uni_real_distribution
	b_result = fdlibcppwrapper::UniformDistributionWrapper<double>::uniform_real_distribution_wrapper(&a[0], length, num_of_engine);
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	
#endif
	CHOL_C(&l[0], &a[0], &n);

#if PERF_TEST

	clock_stop = _rdtsc();
#if PRINT_TO_FILE
	FILE * fp;
	
	const char *fname = "CHOL_C_Timing.csv";
	const char  clock_start_value[] = "clock_start_value";
	const char  clock_stop_value[] = "clock_stop_value";
	const char  timing_result[] = "F77 CHOL_C executed in:";
	const char   neg_wall_clock[] = "ERROR: Negative Wall Clock Value!!";
	if (fopen_s(&fp, fname, "wt") != 0)
		printf("ERROR failed to open %s\n", fname);
	else
	{
		
		fprintf(fp,"%s: %2lu \n",clock_start_value, clock_start);
		fprintf(fp,"%s: %2lu \n",clock_stop_value, clock_stop);
		
		if (clock_stop > clock_start){
			fprintf(fp,"%s: %2.9f ns\n\n",timing_result, (double)(clock_stop - clock_start) / (get_cpu_freq2() * 1.0e-6));
		}
		else
		{
			fprintf(fp,"%s\n",neg_wall_clock);
		}
	}
#endif //PRINT_TO_FILE
#endif //PERF_TEST
#if defined (_DEBUG)

	//PRINT(a, n, n);
	//PRINT(l, n, n);
	//FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	//if (result < 0)
		//printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	_mm_free(a);
	_mm_free(l);

	return FDLIB_SUCCESS;
}

/*  FDLIB_INT fdlib_lm_chol_cran_pd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to PoissonDistributionWrapper<double>::poisson_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_pd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8)  );
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_pd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif

	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_pd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_pd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	
	
	
			  bool b_result = false;
			  // temporal workaround to convert int num_of_engine to enum class RandomNumberEngines.
			  b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::exponential_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
			  if (!b_result)
			  {
				  printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_pd(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
				  _mm_free(a);
				  _mm_free(l);
				  return FDLIB_ERROR_FUNC_CALL_FAIL;
			  }
#if PERF_TEST
			  unsigned long long clock_start = 0ULL;
			  unsigned long long clock_stop = 0ULL;
			  clock_start = _rdtsc();
			  printf("Precise timing of CHOL_C subroutine started\n\n");
			  printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
			  CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
			  clock_stop = _rdtsc();
			  printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
			  printf("Precise timing of CHOL_C subroutine ended\n\n");
			  if (clock_stop > clock_start){
				  printf("F77 CHOL_C executed in %2.9fnanoseconds\n\n", (double)(clock_stop - clock_start) / (get_cpu_freq2() * 1e-6));
			  }
			  else
			  {
				  printf("ERROR: Negative Wall Clock!! \n");
			  }
#endif
#if defined (_DEBUG)
			//  printf(" Results of call to F77 CHOL_C subroutine\n");
			//  printf("Content of array a(%d,%d) \n\n",length,length);
			//  PRINT(a, n, n);
			 // printf("Content of array l(%d,%d)\n\n",length,length);
			 // PRINT(l, n, n);
			  FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
			  if (result < 0)
				  printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
			  _mm_free(a);
			  _mm_free(l);

			  return FDLIB_SUCCESS;
}

/*  FDLIB_INT fdlib_lm_chol_cran_ed(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to PoissonDistributionWrapper<double>::gamma_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_gd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_ed() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_ed(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	     if (l == NULL)
		 {
		    printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_pd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		    return FDLIB_ERROR_MEM_ALLOC;
	     }
	    bool b_result = false;
	    b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::gamma_distribution_wrapper(&a[0], length, static_cast < fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	    if (!b_result)
	    {
			printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_gd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
			_mm_free(a);
			_mm_free(l);
			return FDLIB_ERROR_FUNC_CALL_FAIL;
	    }
#if PERF_TEST
		unsigned long long clock_start = 0ULL;
		unsigned long long clock_stop = 0ULL;
		clock_start = _rdtsc();
		printf("Precise timing of CHOL_C subroutine started\n\n");
		printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
		CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
		clock_stop = _rdtsc();
		printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
		printf("Precise timing of CHOL_C subroutine ended\n\n");
		if (clock_stop > clock_start)
		{
			printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
		}
		else
		{
			printf("ERROR: Negative Wall Clock!!\n");
		}
#endif
#if defined (_DEBUG)
		//printf(" Results of call to F77 CHOL_C subroutine\n");
		//printf("Content of array a(%d,%d) \n\n", length, length);
		//PRINT(a, n, n);
		//printf("Content of array l(%d,%d)\n\n", length, length);
		//PRINT(l, n, n);
		FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
		if (result < 0)
			printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
		_mm_free(a);
		_mm_free(l);

		return FDLIB_SUCCESS;

}

/*  FDLIB_INT fdlib_lm_chol_cran_wd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to PoissonDistributionWrapper<double>::weibull_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_wd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_ed() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_wd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{

		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_wd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::weibull_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_wd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}
	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_evd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to PoissonDistributionWrapper<double>::extreme_value_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_evd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_evd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_evd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_evd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::extreme_value_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_evd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}
	return FDLIB_SUCCESS;
}

/*  FDLIB_INT fdlib_lm_chol_cran_nd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::normal_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_nd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_nd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_nd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_nd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::normal_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_nd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start)
	{
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_lnd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::lognormal_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_lnd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_lnd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_lnd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_lnd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::lognormal_distribution_wrapper(&a[0], length, static_cast < fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_lnd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif

	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}
	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_csd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::chi_squared_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_csd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_csd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_csd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_csd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::chi_squared_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_csd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else

	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}
	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_cd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::cauchy_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_cd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_cd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{

		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::cauchy_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_csd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}

	if (l)
	{
		_mm_free(l);
	}
	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_fd(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::fisher_f_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_fd(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_cd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16); 
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_fd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_fd(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::fisher_f_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_fd(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	clock_start = _rdtsc();
	printf("Precise timing of CHOL_C subroutine started\n\n");
	printf("clock_start value: %2lu CPU cycles\n", clock_start);
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9f nanoseconds\n\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	if (result < 0)
		printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}

/*  FDLIB_INT fdlib_lm_chol_cran_std(FDLIB_INT n, const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::fisher_f_distribution_wrapper() function.
*  Parameters: FDLIB_INT n,  const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_cran_std(FDLIB_INT n, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if ((n != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_cd() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined __AVX__
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else 
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_std(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined __AVX__
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_std(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::student_t_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_std(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
#if PERF_TEST
	unsigned long long clock_start = 0ULL;
	unsigned long long clock_stop = 0ULL;
	//printf("Precise timing of CHOL_C subroutine started\n\n");
	clock_start = _rdtsc();
	
	
#endif
	CHOL_C(&l[0], &a[0], &n);
#if PERF_TEST
	clock_stop = _rdtsc();
	/*printf("clock_start value: %2lu CPU cycles\n", clock_start);
	printf("clock_stop value: %2lu CPU cycles\n", clock_stop);
	printf("Precise timing of CHOL_C subroutine ended\n\n");
	if (clock_stop > clock_start){
		printf("F77 CHOL_C executed in %2.9fnanoseconds\n", (double)(clock_stop - clock_start) / 2.4);
	}
	else
	{
		printf("ERROR Negative Wall Clock!!\n");
	}*/
#endif
#if defined (_DEBUG)
	/*printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);*/
	//FDLIB_INT result = test_chol_c_alg_correctnes(n, &l[0], &a[0]);
	//if (result < 0)
		//printf("test_chol_c_alg_correctnes failed with the error: %d\n\n", result);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_pd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::fisher_f_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_pd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != nullptr) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_pd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_pd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_pd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::exponential_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_pd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}

	CHOL_C(&l[0], &a[0], &n);
	// Copy l(n,n) to user passed array data.
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", n, n);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", n, n);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_gd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::fisher_f_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_gd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != nullptr) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_gd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_gd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_gd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::gamma_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_gd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}

	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}

#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_wd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::weibull_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_wd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != nullptr) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_wd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_wd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined  (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_gd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::weibull_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_wd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}

	// calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_evd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::extreme_value_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_evd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != nullptr) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_evd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_wd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_wd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::PoissonDistributionsWrapper<double>::extreme_value_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_evd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling CHOL_C F77 subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_nd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::normal_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_nd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_nd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_nd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_nd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::normal_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_nd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_lnd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::lognormal_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_lnd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_nd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_lnd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_lnd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::lognormal_distribution_wrapper(&a[0], length, static_cast < fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result) // if b_result == false
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_lnd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_csd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::chi_squared_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_csd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_nd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_csd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_csd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::chi_squared_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines > (num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_csd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling  F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_cd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::cauchy_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_cd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_cd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::cauchy_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_cd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;

	}
	// Calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_fd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::fisher_f_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_lm_chol_cran_fd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_fd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_cd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::fisher_f_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_fd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_lm_chol_cran_sd_user(FDLIB_INT n, double * __restrict data, const int data_length ,const int num_of_engine)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Array a initialized by call to NormalDistributionWrapper<double>::student_t_distribution_wrapper() function.
*  Parameters: FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success, Array data is filled by the result of call to CHOL_C subroutine.
*  Array l(100,100) is copied to double * data.
*/
FDLIB_INT fdlib_ml_chol_cran_sd_user(FDLIB_INT n, double * __restrict data, const int data_length, const int num_of_engine)
{
#if defined (_DEBUG)
	_ASSERTE((data != NULL) && (n == FDLIB_ARRAY_10) && (data_length == FDLIB_ARRAY_10) && (num_of_engine >= 0 && num_of_engine <= 8));
#else
	if((data == nullptr) && (n != FDLIB_ARRAY_10) && (data_length != FDLIB_ARRAY_10) && (num_of_engine < 0 || num_of_engine > 8))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_cran_sd_user() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
#if defined (__AVX__)
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_sd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__AVX__)
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
#else
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_16);
#endif
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_cran_sd_user(%p) wrapper routine \tFILE: [%2s], \tLINE: [%2d],\tLINE: [%2d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	bool b_result = false;
	b_result = fdlibcppwrapper::NormalDistributionsWrapper<double>::student_t_distribution_wrapper(&a[0], length, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(num_of_engine));
	if (!b_result)
	{
		printf("\tERROR!! Failed to call external wrapper function in fdlib_ml_chol_cran_sd_user(%d) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", b_result, __FILEW__, __FUNCTIONW__, __LINE__);
		_mm_free(a);
		_mm_free(l);
		return FDLIB_ERROR_FUNC_CALL_FAIL;
	}
	// Calling F77 CHOL_C subroutine.
	CHOL_C(&l[0], &a[0], &n);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			data[j * data_length + i] = l[j * data_length + i];
		}
	}
#if defined (_DEBUG)
	printf(" Results of call to F77 CHOL_C subroutine\n");
	printf("Content of array a(%d,%d) \n\n", length, length);
	PRINT(a, n, n);
	printf("Content of array l(%d,%d)\n\n", length, length);
	PRINT(l, n, n);
#endif
	if (a)
	{
		_mm_free(a);
	}
	if (l)
	{
		_mm_free(l);
	}

	return FDLIB_SUCCESS;
}
/*  FDLIB_INT fdlib_ml_chol_r(FDLIB_INT n, int range_min, int range_max)
*  Implementation of medium-level wrapper for chol_r subroutine.
*  Memory allocation aligned either on 32-byte  boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Parameters: FDLIB_INT n, int range_min, int range_max.
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/

FDLIB_INT fdlib_ml_chol_r(FDLIB_INT n, int range_min, int range_max)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (range_min < range_max));
#else
	if((n != FDLIB_ARRAY_10) && (range_min >= range_max))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_r() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif


	double * a = NULL;
	double * l = NULL;
	const int length = n * n;
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_r(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]",a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_r(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

#if defined (__INTEL_COMPILER)
	unsigned int status = 0xFFFFFFFF;
	const  unsigned	long long MAX_VALUE = 4294967295ULL * 100;
	const double INV_RAND_MAX = ((double)1.0 / MAX_VALUE);
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			unsigned int rand = 0;
			status = _rdrand32_step(&rand);
			if (status == 0)
			{
				_mm_free(a);
				_mm_free(l);
				return FDLIB_ERROR_RDRAND_FAIL;

			}
			else
			{
				a[j * n + i] = (double)rand * INV_RAND_MAX * (range_max - range_min) + range_max;
			}
		}
	}
#elif defined (_MSC_VER_)
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + 1] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_max;
		}
	}
#endif
	
	CHOL_R(&l[0], &a[0], &n);
#if defined (_DEBUG)
	PRINT(&l[0], n, n);
	PRINT(&a[0], n, n);
#endif

	_mm_free(l);
	_mm_free(a);
	return FDLIB_SUCCESS;


}

/*  FDLIB_INT fdlib_lm_chol_rar(FDLIB_INT n, double * values, const int _size)
*  Implementation of medium-level wrapper for chol_c subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  Parameters: FDLIB_INT n, double * values, const int _size.
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_chol_rar(FDLIB_INT n, double * __restrict values, const int _size)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (values != NULL) && ((n - _size) == 0));
#else
	if((n != FDLIB_ARRAY_10) && (values == NULL) && ((n - _size) != 0))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_chol_car() wrapper routine \tFILE: [%2s], \tLINE: [%2s],\tLINE: [%2d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}
#endif
	const int length = n * n;
	double * a = NULL;
	double * l = NULL;
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	if (a == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_rar(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	l = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	if (l == NULL)
	{
		printf("\tERROR!! Failed to allocate memory in fdlib_ml_chol_rar(%p) wrapper routine \tFILE: [%s], \tLINE: [%s],\tLINE: [%d]", l, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = values[j * n + i];
		}
	}
	
	CHOL_R(&l[0], &a[0], &n);
#if defined (_DEBUG)
	PRINT(&a[0], n, n);
	PRINT(&l[0], n, n);
#endif

	
		_mm_free(a);
		_mm_free(l);

		return FDLIB_SUCCESS;
	
		
}


/*  FDLIB_INT fdlib_ml_det_hess_l(FDLIB_INT n,int range_min, int range_max)
*  Implementation of medium-level wrapper for DET_HESS_L subroutine.
*  Memory allocation aligned either on 32-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  If Intel Compiler is defined rdrand intrinsic is used, otherwise
*  stdlib.h rand() is called to fill the array.
*  Parameters: FDLIB_INT n
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_det_hess_l(FDLIB_INT n, int range_min, int range_max)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (range_min < range_max));
#else
	if((n != FDLIB_ARRAY_10) && (range_min >= range_max))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_det_hess_l() wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM
	}
#endif


	
	double det = 0.0;
	const unsigned int length = n * n;
	double * a = (double *)_mm_malloc(length * sizeof(double), 32);
	if (a == NULL)
	{
		printf("\tERROR Failed to allocate memory in fdlib_ml_det_hess_l(%p) wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]",a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
#if defined (__INTEL_COMPILER)
	int status = 0xFFFFFFFF;
	
    const  unsigned	long long MAX_VALUE = 4294967295ULL * 100;
	const double INV_RAND_MAX = ((double)1.0 / MAX_VALUE);
	//unsigned int count = -1;
	
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			unsigned int rand = 0;
		    int status = 	_rdrand32_step(&rand);
			
			//printf("status = %5d, count = %5d\n", status,++count);
			if (status == 0)
			{
				_mm_free(a);
				return FDLIB_ERROR_RDRAND_FAIL;
			}
			else{
				a[j * n + i] = (double)rand * INV_RAND_MAX  * (range_max - range_min) + range_min;
			}
			
			
		}
	}
#elif defined (_MSC_VER_)

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j  * n + i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_max;
		}
	}
#endif


	DET_HESS_L(&n, &a[0], &det);
#if defined (_DEBUG)
	PRINT(a, n, n);
	printf("Determinant det = %5.16f\n", det);
#endif


	_mm_free(a);
	return FDLIB_SUCCESS;


}

/*  FDLIB_INT fdlib_ml_det_hess_l_ar(FDLIB_INT n,double * __restrict values, const int _size)
*  Implementation of medium-level wrapper for DET_HESS_L subroutine.
*  Memory allocation aligned either on 32-byte boundaries.
*  Processes and encapsultes possible implementation of DET_HESS_L driver.
*  User pre-alocated array is passed as an argument.
*  
*  Parameters: FDLIB_INT n, double * __restrict values, const int _size.
*  Returns: FDLIB_ERROR or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_det_hess_l_ar(FDLIB_INT n, double * __restrict values, const int _size)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (values != NULL) && ((n - _size) == 0));
#else
	if((n != FDLIB_ARRAY_10) && (values == NULL) && ((n - _size) != 0))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_det_hess_l_ar() wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}

#endif
	const int length = n * n;
	double * a = NULL; double det = 0.0;
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	if (a == NULL)
	{
		printf("\tERROR Failed to allocate memory in fdlib_ml_det_hess_l_ar(%p) wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	// Test only
	const int llength = 100;
	unsigned int * data = (unsigned int *)_mm_malloc(llength * sizeof(unsigned int), 32);
	unsigned int * data2 = (unsigned int *)_mm_malloc(llength * sizeof(unsigned int), 32);
	double * data3 = (double *)_mm_malloc(length * sizeof(double), 32);
	//fdlibcppwrapper::test_binomial_distribution_wrapper(&data[0], llength);
	fdlibcppwrapper::BernoulliDistributionsWrapper<unsigned int>::binomial_distribution_wrapper(&data2[0], llength, 0);
	fdlibcppwrapper::NormalDistributionsWrapper<double>::normal_distribution_wrapper(data3, llength, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::KNUTH_B);

	// End of Test only.
	//Testing data array.
	for (int i = 0; i != llength; ++i)
	{
		printf("std::binominal_distribution filled vector data[%d] = %2d\n", i, data[i]);
		printf("StatsDistributionsWrapper::binomial_distribution_wrapper() - executed, data2[%d] = %2d\n", i, data2[i]);
		printf("StatsDistributionsWrapper::normal_distribution_wrapper() - executed, data3[%d] = %2.15f\n", i, data3[i]);
	}
	// End of test
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = values[j * n + i];
		}
	}

	DET_HESS_L(&n, &a[0], &det);
#if defined (_DEBUG)
	PRINT(&a[0], n, n);
	printf("Determinant det = %5.16f\n", det);
#endif

	_mm_free(a);
	return FDLIB_SUCCESS;

}

/*  FDLIB_INT fdlib_ml_det_hess_u(FDLIB_INT n, int range_min, int range_max)
*  Implementation of medium-level wrapper for DET_HESS_L subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
* If Intel Compiler is defined rdrand intrinsic is used, otherwise
*  stdlib.h rand() is called to fill the array.
*  Parameters: FDLIB_INT n ,int range_min, int range_max.
*  Returns: FDLIB_ERROR_RDRAND_FAIL or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_det_hess_u(FDLIB_INT n, int range_min, int range_max)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (range_min < range_max));
#else
	if((n != FDLIB_ARRAY_10) && (range_min >= range_max))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_det_hess_U() wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM
	}
#endif


	
	double * a = NULL, det = 0.0;
	const int length = n * n;
	a = (double *)_mm_malloc(length * sizeof(double), 32);
	if (a == NULL)
	{
		printf("\tERROR Invalid parameter in fdlib_ml_det_hess_u(%p) wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	
#if defined (__INTEL_COMPILER)
	int status = 0xFFFFFFFF;
	const unsigned	long long MAX_VALUE = 4294967295ULL * 100;
	const double INV_RAND_MAX = ((double)1.0 / MAX_VALUE);
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			unsigned int rand = 0;
			status = _rdrand32_step(&rand);
			if (status == 0)
			{
				_mm_free(a);
				return FDLIB_ERROR_RDRAND_FAIL;
			}
			else
			{

				a[j * n + i] = (double)rand * INV_RAND_MAX  * (range_max - range_min) + range_min;
			}
		}
	}
#elif defined (_MSC_VER_)
	for(int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_max;
		}
	}
#endif

	DET_HESS_U(&n, &a[0], &det);
#if defined (_DEBUG)
	PRINT(&a[0], n, n);
	printf("Determinant of matrix a is: %5.16f\n", det);
#endif


	_mm_free(a);
	return FDLIB_SUCCESS;

}

/*  FDLIB_INT fdlib_ml_det_hess_u_ar(FDLIB_INT n, double * __restrict values, const int _size)
*  Implementation of medium-level wrapper for DET_HESS_L subroutine.
*  Memory allocation aligned either on 32-byte  or 16-byte boundaries.
*  Processes and encapsultes possible implementation of chol_c driver.
*  User pre-allocated array is passed as an argument.
*  Parameters: FDLIB_INT n ,double * __restrict values, const int _size
*  Returns: FDLIB_ERROR_RDRAND_FAIL or FDLIB_ERROR_MEM_ALLOC on failure and FDLIB_SUCCESS on success.
*/
FDLIB_INT fdlib_ml_det_hess_u_ar(FDLIB_INT n, double * __restrict values, const int _size)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (values != NULL) && ((n - _size) == 0));
#else
	if ((n != FDLIB_ARRAY_10) && (values == NULL) && ((n - _size) != 0))
	{
		printf("\tERROR Invalid parameter in fdlib_ml_det_hess_u_ar() wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_INVALID_PARAM;
	}

#endif
	const int length = n * n;
	double * a = NULL; double det = 0.0;
	a = (double *)_mm_malloc(length * sizeof(double), ALIGN_32);
	if (a == NULL)
	{
		printf("\tERROR Failed to allocate memory in fdlib_ml_det_hess_u_ar(%p) wrapper routine \tFILE: [%4s], \tLINE: [%4s],\tLINE: [%4d]", a, __FILEW__, __FUNCTIONW__, __LINE__);
		return FDLIB_ERROR_MEM_ALLOC;
	}

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			a[j * n + i] = values[j * n + i];
			
		}
	}

	DET_HESS_U(&n, &a[0], &det);
#if defined (_DEBUG)
	PRINT(&a[0], n, n);
	printf("Determinant det = %4.15f\n", det);
#endif

	_mm_free(a);
	return FDLIB_SUCCESS;
}

#if defined _DEBUG

FDLIB_INT test_chol_c_alg_correctnes(FDLIB_INT n, double * __restrict _l, double * __restrict _a)
{
	printf("Cholesky C algorithm correctness check:\n\n");
	const int length = n * n;
	const char *func_name = "test_chol_c_alg_correctnes";
	const unsigned int equal = 1U;
	const unsigned int not_equal = 0U;
	double * v = NULL;
	//unsigned int * c = NULL;
	 char**pp = NULL;
	 pp = (char **)_mm_malloc(length * sizeof(char *), 32);
	 if (pp == NULL)
	 {
		 printf("_mm_malloc(%d,%d) - failed to allocate memory inside %s() for an array pp: = %p\n\n", length * sizeof(char *), 32, func_name, &pp);
		 return FDLIB_ERROR_MEM_ALLOC;
	 }

	 for (int i = 0; i < length; ++i)
		 pp[i] = (char *)_mm_malloc(length * sizeof(char), 32);

	const double epsilon = 1.0E-15;
	v = (double *)_mm_malloc(length * sizeof(double), 32);
	if (v == NULL)
	{
		printf("_mm_malloc(%d,%d) - failed to allocate memory inside %s() for an array v: = %p\n\n", length * sizeof(double), 32,func_name, &v[0]);
		return FDLIB_ERROR_MEM_ALLOC;
	}
	/*c = (unsigned int *)_mm_malloc(length * sizeof(unsigned int), 32);
	if (c == NULL)
	{
		printf("_mm_malloc(%d,%d) - failed to allocate memory inside %s() for an array c: = %p\n\n", length * sizeof(unsigned int), 32, func_name, &c[0]);
		return FDLIB_ERROR_MEM_ALLOC;
	}*/

	printf("Calculating l transpose, A = L*LT:\n");

	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			v[j * n + i] = 0.0;
			for (int k = 0; k != n; ++k)
			{
				v[j * n + i] = v[j * n + i] + (_l[k * n + i] * _l[k * n + j]);
			}
		}
	}
	printf("Displaying the result and checking the algorithm correctness\n\n");
	printf("    array l:,                       array a:,                          array c: \n");
	printf("--------------------------------------------------------------------------------\n");
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			if (fabs(v[j * n + i] - _a[j * n + i]) <= epsilon)
			{
				//c[j * n + i] = equal;
				pp[j * n + i] = "equal";
			}
			else
			{
				//c[j * n + i] = not_equal;
				pp[j * n + i] = "not_equal";
			}

			printf(" %14.15f |  %25.15f  | %27s | \n", v[j * n + i], _a[j * n + i], pp[j * n + i]); //printf("  %45.15f \n", _a[j * n + i]);	printf(" %75s    \n", pp[j * n + i]);
			
		
		}
	}

	// Handle resources deallocation.
	if (v)
		_mm_free(v);

	if (pp)
		_mm_free(pp);
		
		
	

	return FDLIB_SUCCESS;
}
#endif
/*void testfun(double **a, double**l, int *n)
{
	int nn;
	chol_c(a, l, &nn);
}*/


