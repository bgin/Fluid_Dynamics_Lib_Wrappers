
#include "NumMethodsTests.h"

// Implementation of test methods.


void Test_fdlib_ml_det_hess_l()
{
	const int _length = 10;
	const int _min_range = -1; const int _max_range = 1;
	FDLIB_INT _result = fdlib_ml_det_hess_l(_length, _min_range, _max_range);
	assert(_result == 0);
	printf(" Test of fdlib_ml_det_hess_l(%d, %1d, %1d) = %1d\n", _length, _min_range, _max_range, _result);

	
}
//--------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------//
void Test_fdlib_ml_det_hess_u()
{
	const int _length = 10;
	const int _min_range = -1; const int _max_range = 1;
	FDLIB_INT _result = fdlib_ml_det_hess_u(_length, _min_range, _max_range);
	assert(_result == 0);
	printf(" Test of fdlib_ml_det_hess_u(%d, %1d, %1d) = %1d\n", _length, _min_range, _max_range, _result);


	
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
void Test_fdlib_ml_chol_c()
{
	const int _length = 10;
	const int _min_range = 1; const int _max_range = 10;
	FDLIB_INT test_result = fdlib_ml_chol_c(_length, _min_range, _max_range);
	assert(test_result == 0);
	printf("Test of fdlib_ml_chol_c(%d,%1d,%1d) = %1d\n", _length, _min_range, _max_range, test_result);
}
//------------------------------------------------------------------------------//

//------------------------------------------------------------------------------//
void Test_fdlib_ml_chol_car()
{
	const int _length = 10; const int n = 10;
	double * a = NULL;
	a = (double *)_mm_malloc(_length * _length *  sizeof(double), ALIGN_32);
	if (a == NULL)
	{
		printf("Failed to allocate memory in Test_fdlib_ml_chol_car() routine\n");
		return;
	}
	double arg = 0.01;
	for (int i = 0; i != _length ; ++i)
	{
		for (int j = 0; j != _length; ++j)
		{
			
			
			a[j * _length + i] = arg += 0.01;
		}
	}
	FDLIB_INT _test_result = fdlib_ml_chol_car(n, &a[0], _length);
	assert(_test_result == 0);
	_mm_free(a);
}
//---------------------------------------------------------------------//

//---------------------------------------------------------------------//
void Test_fdlib_ml_chol_cran()
{
	const int length = 10;
	const int num_of_engine = 0;
	FDLIB_INT test_result = fdlib_ml_chol_cran(length, num_of_engine);
	assert(test_result == 0);
	printf(" Finished Test of fdlib_ml_chol_cran(%d,%1d) = %d\n\n", length, num_of_engine, test_result);
}
//----------------------------------------------------------------------//

//-----------------------------------------------------------------------//
void Test_fdlib_ml_chol_cran_pd()
{
	const int length = 10;
	const int num_of_engine = 5;
	FDLIB_INT test_result = fdlib_ml_chol_cran_pd(length, num_of_engine);
	assert(test_result == 0);
	printf(" Finished Test of fdlib_ml_chol_cran_pd(%d,%1d) = %d\n\n", length, num_of_engine, test_result);
}
//------------------------------------------------------------------------//

//------------------------------------------------------------------------//
void Test_fdlib_ml_chol_cran_gd()
{
	const int length = 10;
	const int num_of_engine = 3;
	FDLIB_INT test_result = fdlib_ml_chol_cran_gd(length, num_of_engine);
	assert(test_result == 0);
	printf(" Finished Test of fdlib_ml_chol_cran_gd(%d,%1d) = %d\n\n", length, num_of_engine, test_result);
}
//------------------------------------------------------------------------//

//------------------------------------------------------------------------//
void Test_fdlib_ml_chol_cran_gd_user()
{
	const int n = 10;
	const int ar_length = n * n;
	const int data_length = 10;
	const int num_of_engine = 3;
	double * __restrict data = NULL;
	data = (double *)_mm_malloc(ar_length * sizeof(double), 32);
	if (data == NULL)
	{
		printf("_mm_malloc(%1d,%1d) Failed to allocate memory\n", ar_length * sizeof(double), 32);
		exit(0xFFFFFFFF);
	}
	unsigned long long start_clock = 0ULL;
	unsigned long long end_clock = 0ULL;
	// Coarse performance testing.
	start_clock = ::GetTickCount64();
	FDLIB_INT test_result = fdlib_ml_chol_cran_gd_user(n, data, data_length, num_of_engine);
	end_clock = ::GetTickCount64();
	printf("fdlib_ml_chol_cran_gd_user() executed in %lumiliseconds\n", end_clock - start_clock);
	assert(test_result == 0);
	
	printf("Finished Test of fdlib_ml_chol_cran_gd_user(%d,%p,%d,%d) = %d\n\n", n, data, data_length, num_of_engine,test_result);
	for (int i = 0; i != data_length; ++i)
	{
		for (int j = 0; j != data_length; ++j)
		{
			printf("Content of data[%d * %d + %d] = %2.15f\n", i, data_length, j, data[j * data_length + i]);
		}
		printf("\n");
	}
	if (data)
		_mm_free(data);
}

void Test_fdlib_ml_chol_r()
{
	const int _length = 10;
	const int _min_range = 1; const int _max_range = 10;
	FDLIB_INT _test_result = fdlib_ml_chol_r(_length, _min_range, _max_range);
	assert(_test_result == 0);
	printf(" Finished Test of fdlib_ml_chol_r(%d,%1d,%1d) = %1d\n\n", _length, _min_range, _max_range, _test_result);
}


// TO DO write performance tests.
void RunTests()
{
	printf(" Starting Test of fdlib_ml_det_hess_l()\n\n");
	Test_fdlib_ml_det_hess_l();
	printf(" Starting Test of fdlib_ml_det_hess_u()\n\n");
	Test_fdlib_ml_det_hess_u();
	printf(" Starting Test of fdlib_ml_chol_c()\n\n");
	Test_fdlib_ml_chol_c();
	printf(" Starting Test of fdlib_ml_chol_car()\n\n");
	Test_fdlib_ml_chol_car();
	printf("Starting Test of fdlib_ml_chol_r()\n\n");
	Test_fdlib_ml_chol_r();
	printf(" Starting Test of fdlib_ml_chol_cran()\n\n");
	Test_fdlib_ml_chol_cran();
	printf(" Starting Test of fdlib_ml_chol_cran_pd()\n\n");
	Test_fdlib_ml_chol_cran_pd();
	printf("Starting Test of fdlib_ml_chol_cran_gd()\n\n");
	Test_fdlib_ml_chol_cran_gd_user();
	printf("Starting Test of fdlib_ml_chol_cran_gd_user()\n\n");
	
}