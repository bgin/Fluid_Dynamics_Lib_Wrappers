

#include "../FluidDynamicLibCWrapper/lin_alg_imp.h"
//#include "../FluidDynamicLibCWrapper/"
#include "STD_DEFS.h"
#ifndef _CHOL_C_TESTS_H_
#define _CHOL_C_TESTS_H_


// Globals
// Tested functions names.
static const char *names[] = { "fdlib_ml_chol_cran", "fdlib_ml_chol_cran_cd", "fdlib_ml_chol_cran_csd", "fdlib_ml_chol_evd",
"fdlib_ml_chol_cran_fd", "fdlib_ml_chol_cran_lnd", "fdlib_ml_chol_cran_nd", "fdlib_ml_chol_cran_pd",
"fdlib_ml_chol_cran_std", "fdlib_ml_chol_cran_wd", "fdlib_ml_chol_cran_gd" };

// Invalid arguments
static const char *invalid_arguments[] = { "zero_array_length", "greater_than_one_array_length", "non_integer_array_length",
"negative_array_length", "switch_variable_off_by_one", "switch_variable_negative", "switch_variable_high_max",
"switch_variable_high_max_by_one", "switch_variable_non_integer_increment", "switch_variable_non_integer_decrement",
"zero_array_length_&&_switch_variable_high_max", "greater_than_one_array_length_&&_switch_variable_high_max",
"non_integer_array_length_&&_switch_variable_high_max", "negative_array_length_&&_switch_variable_high_max" };

// perf tests strings.
static const char TSC_START[] = "TSC_start =";
static const char TSC_STOP[] = "TSC_end =";
static char TSC_delta[] = "TSC_delta:";
static char ns[] = "TSC_cycles_to_nanoseconds:";
static char error[] = "ERROR Invalid Wall Clock Value";
static char arithm_average[] = "Arithmetic Average:";
static char std_dev[] = "Standard Deviation:";
static char geo_median[] = "Geometric Median:";
static char geo_med_calc_started[] = "Geometric Median computation started";
static char eps_error[] = "nom / denom ~ 0.0";
static const double epsilon = 1.0e-12;
 // CHOL_C wrappers tests.
 
 // Testing fdlib_ml_chol_cranxxx() , where xxx stands for various random values fill methods.

 //Test mathematical algorythmic correctnes of Cholesky Column decomposition.
 FDLIB_INT *Test_fdlib_ml_chol_c_alg(FDLIB_INT (*)(FDLIB_INT,const int),FDLIB_INT,const int);

 //General Test of fdlib_ml_chol_c() functionality.
FDLIB_INT *Test_fdlib_ml_chol_c_gnr(FDLIB_INT (*)(FDLIB_INT,const int), FDLIB_INT, const int);

 //Ivalid input/arguments Test.
 void     Test_fdlib_ml_chol_c_inv(FDLIB_INT (*)(FDLIB_INT,const int), FDLIB_INT, const int);

 //Performance Test.
// void Test_fdlib_ml_chol_c_perf(FDLIB_INT (*)(FDLIB_INT, const int), FDLIB_INT, const int);
 void    Test_fdlib_ml_chol_cran_perf();

 // void Test_fdlib_ml_chol_cran_pd_perf()
 void    Test_fdlib_ml_chol_cran_pd_perf();

 // void Test_fdlib_ml_chol_cran_cd_perf()
 void    Test_fdlib_ml_chol_cran_cd_perf();

 // void Test_fdlib_ml_chol_cran_gd_perf()
 void    Test_fdlib_ml_chol_cran_gd_perf();

 // void Test_fdlib_ml_chol_cran_fd_perf()
 void    Test_fdlib_ml_chol_cran_fd_perf();

 // void Test_fdlib_ml_chol_cran_csd_perf()
 void    Test_fdlib_ml_chol_cran_csd_perf();

 // void Test_fdlib_ml_chol_cran_evd_perf()
 void    Test_fdlib_ml_chol_cran_evd_perf();

 // void Test_fdlib_ml_chol_cran_nd_perf()
 void    Test_fdlib_ml_chol_cran_nd_perf();

 // void Test_fdlib_ml_chol_cran_lnd_perf()
 void    Test_fdlib_ml_chol_cran_lnd_perf();

 // void Test_fdlib_ml_chol_cran_wd_perf()
 void    Test_fdlib_ml_chol_cran_wd_perf();

 // void Test_fdlib_ml_chol_cran_std_perf()
 void    Test_fdlib_ml_chol_cran_std_perf();

 // Test timing performance.
 void Run_fdlib_ml_chol_c_perf_tests();

 void Run_fdlib_ml_chol_c_timing_test();


// Run All tests.

// Test general functionality.
void Run_fdlib_ml_chol_c_gnr_tests();

// Test invalid input/argument.
void Run_fdlib_ml_chol_c_inv_tests();

// Test correctnes of algorythmic implementation.
void Run_fdlib_ml_chol_c_alg_tests();




// Run All Tests.
void Run_All_Tests();



// helper inline functions:

 __forceinline long long get_cpu_freq()
{
	 long long tstamp0 = 0ULL;
	 long long tstamp1 = 0ULL;
	 tstamp0 = _rdtsc();
	 Sleep(1);
	 tstamp1 = _rdtsc();
	 return tstamp1 - tstamp0;
}

 __forceinline void set_cpu_affinity()
 {
	 unsigned int affinity_mask = 0x1;
	 DWORD_PTR prev_mask;
	 HANDLE thHandle = GetCurrentThread();
	 prev_mask = SetThreadAffinityMask(thHandle, affinity_mask);
	 if (prev_mask == 0)
		 printf("SetThreadAffinityMask failed with an error 0x%x\n", GetLastError());
 }
#endif /*_CHOL_C_TESTS_H_*/