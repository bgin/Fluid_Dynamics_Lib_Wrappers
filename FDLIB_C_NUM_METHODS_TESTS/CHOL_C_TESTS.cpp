
#include <cstdlib>
#include <stdio.h>
#include "CHOL_C_TEST.h"

// General Test of fdlib_ml_chol_c() functionality.
FDLIB_INT *Test_fdlib_ml_chol_c_gnr(FDLIB_INT(*pFunc)(FDLIB_INT, const int), FDLIB_INT n, const int num_of_engine)
{
	const int length = n;
	const int random_engine = num_of_engine;
	const int num_of_iters = 9;
	
	static FDLIB_INT result_array[num_of_iters] = { 0 };
	

	//printf("Starting general functionality Test of fdlib_ml_chol_cran_xxx() wrapper functions\n");
	//printf("Called %s() wrapper function\n", func_name);
	for (int i = 0; i < num_of_iters; ++i)
	{

		result_array[i] = pFunc(length, i);
		printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
		if (result_array[i] > 0)
		{
			 printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);
		    
		}
		
	}

	return result_array ;
}

FDLIB_INT *Test_fdlib_ml_chol_c_alg(FDLIB_INT(*pFunc)(FDLIB_INT, const int), FDLIB_INT n, const int num_of_engine)
{
	const int length = n;
	const int num_of_iters = 9;
	static FDLIB_INT result_array[num_of_iters] = { 0 };
	long long start_clock[9] = { 0LL };
	long long stop_clock[9] = { 0LL };
	
	for (int i = 0; i < num_of_iters; ++i)
	{
		
		start_clock[i] = _rdtsc();
		result_array[i] = pFunc(length, i);
		stop_clock[i] = _rdtsc();
		

		
		printf("Executing %d calls of wrapper function at address:%p\n", i, &pFunc);
		if (result_array[i] > 0)
		{
			printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);
		}
	}

	return result_array;
}

 void  Test_fdlib_ml_chol_c_inv(FDLIB_INT(*pFunc)(FDLIB_INT, const int), FDLIB_INT n, const int num_of_test)
{
	// Valid arguments.
	const int num_of_iters = 9;
	const int length = n;
	//Invalid arguments.
	const int inv_length0 = 0;
	const int inv_length11 = 11;
	const double inv_lengthfp = 10.5;
	const int inv_length_neg = -1;
	 int inv_counter_off_byone = -2;
	 int inv_counter_neg = 0;
	 int inv_counter_hi_than8 = 9;
	 int inv_counter_off_byone_hi = 8;
	 double inv_counter_fp = 0.0;
	 double inv_counter_fp_neg = 0.0;

	static FDLIB_INT result_array[num_of_iters] = { 0 };
	switch (num_of_test)
	{
	case 0:
	{
			  printf("case: 0 \n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {    
				  result_array[i] = pFunc(inv_length0, i);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
			 
			 
	}
		break;
	case 1:
	{         
			  printf("case: 1\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {
				  result_array[i] = pFunc(inv_length11, i);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 2:
	{
			  printf("case: 2\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {
				  result_array[i] = pFunc(inv_lengthfp, i);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 3:
	{
			  printf("case: 3\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {
				  result_array[i] = pFunc(inv_length_neg, i);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 4:
	{
			  printf("case: 4\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {
				
				  result_array[i] = pFunc(length, ++inv_counter_off_byone);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 5:
	{
			  printf("case: 5\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {

				  result_array[i] = pFunc(length, --inv_counter_neg);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 6:
	{
			  printf("case 6: \n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {

				  result_array[i] = pFunc(length, ++inv_counter_hi_than8);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 7:
	{
			  printf("case 7:\n\n");
			  for (int i = 0; i < num_of_iters; ++i)
			  {

				  result_array[i] = pFunc(length, ++inv_counter_off_byone_hi);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
     
	}
		break;
	case 8:
	{            printf("case 8: \n\n");
			  double incr = 0.1;
			  for (int i = 0; i < num_of_iters; ++i)
			  {

				  result_array[i] = pFunc(length, inv_counter_fp += incr);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 9:
	{
			  printf("case 9: \n\n");
			  double decr = 0.1;
			  for (int i = 0; i < num_of_iters; ++i)
			  {

				  result_array[i] = pFunc(length, inv_counter_fp_neg -= decr);
				  printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				  if (result_array[i] > 0)
				  {
					  printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				  }
			  }
	}
		break;
	case 10:
	{
			   printf("case 10: \n\n");
			   for (int i = 0; i < num_of_iters; ++i)
			   {
				   // both invalid arguments
				   result_array[i] = pFunc(inv_length0, ++inv_counter_hi_than8);
				   printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				   if (result_array[i] > 0)
				   {
					   printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				   }
			   }
	}
		break;
	case 11:
	{
			   printf("case 11: \n\n");
			   for (int i = 0; i < num_of_iters; ++i)
			   {
				   // both invalid arguments
				   result_array[i] = pFunc(inv_length11, ++inv_counter_hi_than8);
				   printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				   if (result_array[i] > 0)
				   {
					   printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				   }
			   }
	}
		break;
	case 12:
	{
			   printf("case 12: \n\n");
			   for (int i = 0; i < num_of_iters; ++i)
			   {
				   // both invalid arguments
				   result_array[i] = pFunc(inv_lengthfp, ++inv_counter_hi_than8);
				   printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				   if (result_array[i] > 0)
				   {
					   printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				   }
			   }
	}
		break;
	case 13:
	{
			   printf("case 13: \n\n");
			   for (int i = 0; i < num_of_iters; ++i)
			   {
				   // both invalid arguments
				   result_array[i] = pFunc(inv_length_neg, ++inv_counter_hi_than8);
				   printf("Executing %d calls  of wrapper function  at address:%p\n", i, &pFunc);
				   if (result_array[i] > 0)
				   {
					   printf("Test no: %d failed with the error no: %d\n", i, result_array[i]);

				   }
			   }
	}
		break;
	default:
	{
			   printf("default: \n\n");
			   printf("Invalid switch variable %d\n\n", num_of_test);
			  
	}

		
	}

}
	// TO DO Implement tomorrow 10/06/2015: - Done.
	/*typedef FDLIB_INT(*fptr)(FDLIB_INT, const int);
	fptr ar_of_ptrs[9] = { NULL };
	ar_of_ptrs[0] = pFunc;
	for(int i = 0; i < 9; ++i)
	{
	    Test_fdlib_ml_chol_c_gnr(ar_of_ptrs[i](length,i));
	}*/

    // Test driver.
	void Run_fdlib_ml_chol_c_gnr_tests()
	{
		typedef FDLIB_INT(*fptr)(FDLIB_INT, const int);
		fptr func_pointers[11] = { NULL };
		func_pointers[0] = &fdlib_ml_chol_cran;
		func_pointers[1] = &fdlib_ml_chol_cran_cd;
		func_pointers[2] = &fdlib_ml_chol_cran_csd;
		func_pointers[3] = &fdlib_ml_chol_cran_evd;
		func_pointers[4] = &fdlib_ml_chol_cran_fd;
		func_pointers[5] = &fdlib_ml_chol_cran_lnd;
		func_pointers[6] = &fdlib_ml_chol_cran_nd;
		func_pointers[7] = &fdlib_ml_chol_cran_pd;
		func_pointers[8] = &fdlib_ml_chol_cran_std;
		func_pointers[9] = &fdlib_ml_chol_cran_wd;
		func_pointers[10] = &fdlib_ml_chol_cran_gd;

		// Array of results
		FDLIB_INT test_results[11][9] = { 0 };
		FDLIB_INT* temp = NULL;
		// array of pointers to string function names. Moved to Global space.
		//const char *names[] = { "fdlib_ml_chol_cran", "fdlib_ml_chol_cran_cd", "fdlib_ml_chol_cran_csd", "fdlib_ml_chol_evd",
			//"fdlib_ml_chol_cran_fd", "fdlib_ml_chol_cran_lnd", "fdlib_ml_chol_cran_nd", "fdlib_ml_chol_cran_pd",
			//"fdlib_ml_chol_cran_std", "fdlib_ml_chol_cran_wd","fdlib_ml_chol_cran_gd" };
		const int length = 10;
		const int num_of_iters = 11;
		printf("Beginning functional Test of fdlib_ml_chol_cran_xxx() function calls\n\n");
		for (int i = 0; i < num_of_iters; ++i)
		{
			printf("Executed %s() function wrapper at address:%p \n\n", names[i], func_pointers[i]);
			temp = Test_fdlib_ml_chol_c_gnr(func_pointers[i],length,i);
			for (int j = 0; j < 9; ++j)
			{
				test_results[i][j] = temp[j];
			}
		}

		printf("Finishing functional Test of fdlib_ml_chol_cran_xxx() function calls\n\n");
		printf("Results\n\n");
		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("Function: %s() called: %d times returned following results: %d\n", names[i], j, test_results[i][j]);
			}
			printf("\n");
		}
	}

	// Test driver.
	void Run_fdlib_ml_chol_c_alg_tests()
	{
		typedef FDLIB_INT(*fptrs)(FDLIB_INT, const int);
		fptrs functions_pointers[11] = { NULL };
		functions_pointers[0] = &fdlib_ml_chol_cran;
		functions_pointers[1] = &fdlib_ml_chol_cran_cd;
		functions_pointers[2] = &fdlib_ml_chol_cran_csd;
		functions_pointers[3] = &fdlib_ml_chol_cran_evd;
		functions_pointers[4] = &fdlib_ml_chol_cran_fd;
		functions_pointers[5] = &fdlib_ml_chol_cran_gd;
		functions_pointers[6] = &fdlib_ml_chol_cran_lnd;
		functions_pointers[7] = &fdlib_ml_chol_cran_nd;
		functions_pointers[8] = &fdlib_ml_chol_cran_pd;
		functions_pointers[9] = &fdlib_ml_chol_cran_std;
		functions_pointers[10] = &fdlib_ml_chol_cran_wd;

		FDLIB_INT test_results[11][9] = { 0 };
		FDLIB_INT* temp = NULL;
		const int length = 10;
		const int num_of_iters = 11;
		printf("Beginning Test of algorythmical correctnes \n\n");
		for (int i = 0; i < num_of_iters; ++i)
		{
			printf("Calling %s() function wrapper at address:%p \n", names[i], functions_pointers[i]);
			temp = Test_fdlib_ml_chol_c_alg(functions_pointers[i], length, i);
			for (int j = 0; j < 9; ++j)
			{
				test_results[i][j] = temp[j];
			}
		}

		printf("Finishing  Test of algorythmical correctnes\n\n");
		printf("Results\n\n");
		for (int i = 0; i < 11; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("Function: %s() called: %d times returned following results: %d\n", names[i], j, test_results[i][j]);
			}
			printf("\n");
		}
	}
	// Test driver.
	void Run_fdlib_ml_chol_c_inv_tests()
	{
		typedef FDLIB_INT(*fptrs)(FDLIB_INT, const int);
		fptrs function_pointers[11] = { NULL };
		function_pointers[0] = &fdlib_ml_chol_cran;
		function_pointers[1] = &fdlib_ml_chol_cran_cd;
		function_pointers[2] = &fdlib_ml_chol_cran_csd;
		function_pointers[3] = &fdlib_ml_chol_cran_evd;
		function_pointers[4] = &fdlib_ml_chol_cran_fd;
		function_pointers[5] = &fdlib_ml_chol_cran_gd;
		function_pointers[6] = &fdlib_ml_chol_cran_lnd;
		function_pointers[7] = &fdlib_ml_chol_cran_nd;
		function_pointers[8] = &fdlib_ml_chol_cran_pd;
		function_pointers[9] = &fdlib_ml_chol_cran_std;
		function_pointers[10] = &fdlib_ml_chol_cran_wd;
		// Array of results
		FDLIB_INT test_results[11][9] = { 0 };
		FDLIB_INT* temp = NULL;
		const int length = 10;
		const int num_of_iters = 11;
		const int num_of_cases = 15;
		printf("Beginning destructive Test of fdlib_ml_chol_cran_xxx() function calls\n\n");
		for (int i = 0; i < num_of_iters; ++i)
		{
			printf("Executing %s() function wrapper at address:%p \n\n", names[i], function_pointers[i]);
			for (int j = 0; j < num_of_cases; ++j)
			{
				printf("Called %s() function with invalid argument(s): %s\n", names[i], invalid_arguments[j]);
				 Test_fdlib_ml_chol_c_inv(function_pointers[i], length, j);
			}
			

		}

		printf("Finishing destructive Test of fdlib_ml_chol_cran_xxx() function calls\n\n");
	}

	void    Test_fdlib_ml_chol_cran_perf()
	{
		// Coarse grained performance test.
		long long start_clock = 0LL;
		long long stop_clock = 0LL;
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		const int engine = 3;
		printf("Beginning coarse grain performance test of fdlib_ml_chol_cran() wrapper function\n\n");
#if defined PRECISE_TIMING
		start_clock = _rdtsc();
#else
		start_clock = GetTickCount64();
#endif
#pragma noinline
		test_result = fdlib_ml_chol_cran(n, engine);
#if defined PRECISE_TIMING
		stop_clock = _rdtsc();
#else
		stop_clock = GetTickCount64();
#endif
		printf(" start_clock value: %2llu\n", start_clock);
		printf("  stop_clock value: %2llu\n", stop_clock);
		if (stop_clock > start_clock)
		{
			
			printf(" #nanoseconds: %2.9f\n\n", (double)(stop_clock - start_clock) / 2.4);
		}
		else
		{
			printf("ERROR Negative Wall Clock Value!!\n");
		}
		printf("Finished coarse grain performance test of fdlib_ml_chol_cran() wrapper function\n\n");
		// Fine grained performance test 10 iterations.
#if SMALL_NUM_OF_ITERATIONS

		const int iters = 10;
		long long clock_ticks_start[iters] = { 0LL };
		long long clock_ticks_stop[iters] = { 0LL };
		double nanoseconds[iters] = { 0.0L };
		FDLIB_INT test_result2 = 0;
		FDLIB_INT n2 = 10;
		//const int range_min = 0; const int range_max = 8;
		const int rand_eng = 3;
		double avg = 0.0L;
#pragma noinline
		printf("Beginning %d iterations of fine grain performance test of fdlib_ml_chol_cran() wrapper function\n\n",iters);
		
		for (int i = 0; i < iters; ++i)
		{
#if defined PRECISE_TIMING
			clock_ticks_start[i] = _rdtsc();
#else
			clock_ticks_start[i] = GetTickCount64();
#endif
			//unsigned int random = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
			// Using rand() here will increase or skew the results of fdlib_ml_chol_cran timing.
			// Possible solution:
			// Perform 1000 iterations of rand() call and take average of _rdtsc() measurement , next subtract those
			// result from fdlib_ml_chol_cran timing where number of random generator is choosen by the result of call
			// to rand().
			test_result2 = fdlib_ml_chol_cran(n2, 3);
#if defined PRECISE_TIMING
			clock_ticks_stop[i] = _rdtsc();
#else
			clock_ticks_stop[i] = GetTickCount64();
#endif
			printf("   clock_ticks_start[%d] = %2llu\n", i, clock_ticks_start[i]);
			printf("   clock_ticks_stop[%d]  = %2llu\n", i, clock_ticks_stop[i]);
			
			if (clock_ticks_stop[i] > clock_ticks_start[i])
			{
				printf("  clock_ticks_delta    = %2llu\n ", clock_ticks_stop[i] - clock_ticks_start[i]);
				printf("  nanoseconds[%d]      =  %2.9f\n\n", i,nanoseconds[i] = (double)(clock_ticks_stop[i] - clock_ticks_start[i]) / 2.4);
				avg += nanoseconds[i];
			}
			else
			{
				printf("ERROR Invalid Wall Clock Value!!\n");
			}
		}
		printf("Average number of nanoseconds per %d iterations: = %.9f\n", iters, avg / (double)iters);
#endif


		const int iters2 = 100;
		const int max_engines = 9;
		const int data_length = iters2;
		long long clock_ticks_start2[data_length][max_engines];
		long long clock_ticks_stop2[data_length][max_engines];
		double nanoseconds2[data_length][max_engines];
		
		FDLIB_INT test_result3 = 0;
		FDLIB_INT n3 = 10;
		double avg2 = 0.0L;
		double std_dev = 0.0L;
		
		
		
#pragma noinline
		printf("Beginning %d iterations of fine grain performance test of fdlib_ml_chol_cran() wrapper function\n\n",iters2 * max_engines);
		
		for (int i = 0; i < data_length; ++i)
		{
			for (int j = 0; j < max_engines; ++j)
			{
#if PRECISE_TIMING
				clock_ticks_start2[i][j] = _rdtsc();
#else
				clock_ticks_start2[i][j] = GetTickCount64();
#endif
				test_result3 = fdlib_ml_chol_cran(n3, j);
#if PRECISE_TIMING
				clock_ticks_stop2[i][j] = _rdtsc();
#else
				clock_ticks_stop2[i][j] = GetTickCount64();
#endif
#if PRINT_DATA
				printf("clock_ticks_start2[%d][%d] = %2llu CPU cycles\n",i,j, clock_ticks_start2[i][j]);
				printf("clock_ticks_stop2[%d][%d]  = %2llu  CPU cycles\n",i,j,  clock_ticks_stop2[i][j]);
#endif
				if (clock_ticks_stop2[i][j] > clock_ticks_start2[i][j])
				{
#if PRINT_DATA
					printf("clock_ticks_delta:        = %llu CPU cycles\n", clock_ticks_stop2[i][j] - clock_ticks_start2[i][j]);
					printf("nanoseconds2[%d][%d]      = %7.9f ns\n",i,j, nanoseconds2[i][j] = (double)(clock_ticks_stop2[i][j] - clock_ticks_start2[i][j]) / (get_cpu_freq() * 1.0e-6));
#endif
					avg2 += nanoseconds2[i][j];
					//printf("values = %.9f\n", nanoseconds2[i][j]);
				}
				else
				{
					printf("ERROR Invalid Wall Clock Value\n");
				}
			}
			printf("\n");
		}
		avg2 = avg2 / (iters2 * max_engines);
		double cpy_avg2 = avg2;
		printf("Computing Arithmetic Average\n");
		printf("Arithmetic Average: %2.9f ns\n", avg2);
		printf("Computing standard deviation\n");
		//printf("avg2 = %.9f\n", cpy_avg2);
		for (int i = 0; i < data_length; ++i)
		{
			for (int j = 0; j < max_engines; ++j)
			{

				nanoseconds2[i][j] = (nanoseconds2[i][j] - cpy_avg2) * (nanoseconds2[i][j] - cpy_avg2);
				std_dev += nanoseconds2[i][j];

			}
			
		}
		printf("Standard Deviation: %2.9f ns\n\n", sqrt(std_dev / (data_length * max_engines)));
		
		





/*		const int iters3 = 1000;
		const int max_engines2 = 9;
		long long clock_ticks_start3[iters3][max_engines2] = { 0LL };
		long long clock_ticks_stop3[iters3][max_engines2] = { 0LL };
		double nanoseconds3[iters3][max_engines2] = { 0.0L };
		FDLIB_INT test_result3 = 0;
		FDLIB_INT n4 = 10;
		double avg3 = 0.0L;
		double std_dev2 = 0.0L;
		//const char *fname = "fdlib_chol_cran_Timing.txt";
		char delta[] = "delta";
		char ns[] = "nanoseconds";
		char error[] = "ERROR Invalid Wall Clock Value";
		char average[] = "Arithmetic Average";
		char std_deviation[] = "Standard Deviation";
 		//FILE * fp;
		//if (fopen_s(&fp, fname, "wt") != 0)
			//printf(" File open error: %s\n", fname);
		

		for (int i = 0; i < iters3; ++i)
			{
				for (int j = 0; j < max_engines2; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start3[i][j] = _rdtsc();
#else
					clock_ticks_start3[i][j] = GetTickCount64();
#endif
					test_result3 = fdlib_ml_chol_cran(n, j);
#if PRECISE_TIMING
					clock_ticks_stop3[i][j] = _rdtsc();
#else
					clock_ticks_stop3[i][j] = GetTickCount64();
#endif
					printf(" %d,  %d, %llu,  %llu\n", i, j, clock_ticks_start3[i][j], clock_ticks_stop3[i][j]);

					if (clock_ticks_stop3[i][j] > clock_ticks_start3[i][j])
					{
						printf( "%d, %d, %s, %llu\n", i, j, delta, clock_ticks_stop3[i][j] - clock_ticks_start3[i][j]);
						printf( "%d, %d, %s, %2.f9\n", i, j, ns, nanoseconds3[i][j] = (double)(clock_ticks_stop3[i][j] - clock_ticks_start3[i][j]) / (get_cpu_freq() * 1.0e-6));
						avg3 += nanoseconds3[i][j];
					}
					else
					{
						printf( "%s\n", error);
					}


				}
			}
			avg3 = avg3 / (iters3 * max_engines2);
			double cpy_avg3 = avg3;
			printf( "%s, %2.9f\n", average, avg3);
			for (int i = 0; i < iters3; ++i)
			{
				for (int j = 0; j < max_engines; ++j)
				{

					nanoseconds3[i][j] = (nanoseconds3[i][j] - cpy_avg3) * (nanoseconds3[i][j] - cpy_avg3);
					std_dev2 += nanoseconds3[i][j];

				}

			}
			printf( "%s, %2.9f\n", std_deviation, std_dev2);
			//fclose(fp);*/
		

		
	}

	//Must be reimplemented tomorrow because of icl error 2.
	void Run_fdlib_ml_chol_c_timing_test()
	{
		const int iters3 = 1000;
		const int max_engines2 = 9;
		long long clock_ticks_start3[iters3][max_engines2] = { 0LL };
		long long clock_ticks_stop3[iters3][max_engines2] = { 0LL };
		double nanoseconds3[iters3][max_engines2] = { 0.0L };
		FDLIB_INT test_result3 = 0;
		FDLIB_INT n4 = 10;
		double avg3 = 0.0L;
		double std_dev2 = 0.0L;
		const char *fname = "fdlib_chol_cran_Timing3.txt";
		char delta[] = "delta";
		char ns[] = "TSC_cycles_to_nanoseconds:";
		char error[] = "ERROR Invalid Wall Clock Value";
		char average[] = "Arithmetic Average";
		char std_deviation[] = "Standard Deviation";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
		printf(" File open error: %s\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran() started\n");
#pragma noinline
			for (int i = 0; i < iters3; ++i)
			{
				for (int j = 0; j < max_engines2; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start3[i][j] = _rdtsc();
#else
					clock_ticks_start3[i][j] = GetTickCount64();
#endif
					test_result3 = fdlib_ml_chol_cran(n4, j);
#if PRECISE_TIMING
					clock_ticks_stop3[i][j] = _rdtsc();
#else
					clock_ticks_stop3[i][j] = GetTickCount64();
#endif
					fprintf(fp," %d,  %d, %llu,  %llu\n", i, j, clock_ticks_start3[i][j], clock_ticks_stop3[i][j]);

					if (clock_ticks_stop3[i][j] > clock_ticks_start3[i][j])
					{
						fprintf(fp,"%d, %d, %s, %llu\n", i, j, delta, clock_ticks_stop3[i][j] - clock_ticks_start3[i][j]);
						fprintf(fp,"%d, %d, %s, %2.f9\n", i, j, ns, nanoseconds3[i][j] = (double)(clock_ticks_stop3[i][j] - clock_ticks_start3[i][j]) / (get_cpu_freq() * 1.0e-6));
						avg3 += nanoseconds3[i][j];
					}
					else
					{
						fprintf(fp,"%s\n", error);
						break;
					}


				}
			}
			avg3 = avg3 / (iters3 * max_engines2);
			double cpy_avg3 = avg3;
			fprintf(fp,"%s, %2.9f\n", average, avg3);
			for (int i = 0; i < iters3; ++i)
			{
				for (int j = 0; j < max_engines2; ++j)
				{

					nanoseconds3[i][j] = (nanoseconds3[i][j] - cpy_avg3) * (nanoseconds3[i][j] - cpy_avg3);
					std_dev2 += nanoseconds3[i][j];

				}

			}
			fprintf(fp,"%s, %2.9f\n", std_deviation, sqrt(std_dev2 / (iters3 * max_engines2)));
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran() ended\n");
			printf("Results has been written to %s\n", fname);
		}
	
	}


	void Test_fdlib_ml_chol_cran_pd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_pd_timing1.txt";
		/*const char TSC_START[] = "TSC_start =";
		const char TSC_STOP[] = "TSC_end =";
		char TSC_delta[] = "TSC_delta:";
		char ns[] = "TSC_cycles_to_nanoseconds:";
		char error[] = "ERROR Invalid Wall Clock Value";
		char arithm_average[] = "Arithmetic Average:";
		char std_dev[] = "Standard Deviation:";*/
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("ERROR fopen_s failed to open file:%s\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_pd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_pd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break;
					}

				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_pd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_gd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void Test_fdlib_ml_chol_cran_cd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_cd_timing1.csv";
		/*const char TSC_START[] = "TSC_start =";
		const char TSC_STOP[] = "TSC_end =";
		char TSC_delta[] = "TSC_delta:";
		char ns[] = "TSC_cycles_to_nanoseconds:";
		char error[] = "ERROR Invalid Wall Clock Value";
		char arithm_average[] = "Arithmetic Average:";
		char std_dev[] = "Standard Deviation:";*/
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s() failed to open file: %s\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_cd() started\n");
#pragma noinline

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = _rdtsc();
#endif
					test_result = fdlib_ml_chol_cran_cd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = _rdtsc();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break;
					}
				}
			}

			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_cd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_gd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void  Test_fdlib_ml_chol_cran_gd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_gd_timing1.csv";
		
		
		
		
		
		
		
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_gd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_gd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break;
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_gd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_gd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void  Test_fdlib_ml_chol_cran_fd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_fd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance testing of fdlib_ml_chol_cran_fd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING 
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_fd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break;
					}
				}

			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_fd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_fd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}

	void Test_fdlib_ml_chol_cran_csd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_csd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_csd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_csd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_csd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_csd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void  Test_fdlib_ml_chol_cran_evd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_evd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_evd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_evd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_tick_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_evd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_evd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void	Test_fdlib_ml_chol_cran_nd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_nd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_nd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_nd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_nd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_nd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}


	void    Test_fdlib_ml_chol_cran_lnd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_lnd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_lnd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_lnd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
					
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s  %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_lnd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :

			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_lnd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}

	void    Test_fdlib_ml_chol_cran_wd_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_wd_timing1.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("fopen_s failed to open %s file\n", fname);
		else
		{
			printf("Performance Test of fdlib_ml_chol_cran_wd() started\n");
#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_wd(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);

			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}


			fprintf(fp, "%s = %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);


#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_wd() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		    less_than_epsilon:
		
			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_wd() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}

	void    Test_fdlib_ml_chol_cran_std_perf()
	{
		const int iters = 1000;
		const int max_rand_engines = 9;
		long long clock_ticks_start[iters][max_rand_engines] = { 0LL };
		long long clock_ticks_stop[iters][max_rand_engines] = { 0LL };
		double nanoseconds[iters][max_rand_engines] = { 0.0L };
#if GEOMETRIC_MEDIAN
		double xj[iters][max_rand_engines] = { 0.0L };
		double nom = 0.0L; double denom = 0.L;
		double yi = 0.0L; double oldyi = 0.0;
		
#endif
		FDLIB_INT test_result = 0;
		FDLIB_INT n = 10;
		double average = 0.0L;
		double std_deviation = 0.0L;
		const char *fname = "fdlib_ml_chol_cran_std_timing3.csv";
		FILE * fp;
		if (fopen_s(&fp, fname, "wt") != 0)
			printf("Performance Test of fdlib_ml_chol_cran_std() started\n");
		else
		{

#pragma noinline
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
#if PRECISE_TIMING
					clock_ticks_start[i][j] = _rdtsc();
#else
					clock_ticks_start[i][j] = GetTickCount64();
#endif
					test_result = fdlib_ml_chol_cran_std(n, j);
#if PRECISE_TIMING
					clock_ticks_stop[i][j] = _rdtsc();
#else
					clock_ticks_stop[i][j] = GetTickCount64();
#endif
					fprintf(fp, "#%d,  #%d,  %s  %llu, %s  %llu\n", i, j, TSC_START, clock_ticks_start[i][j], TSC_STOP, clock_ticks_stop[i][j]);
					if (clock_ticks_stop[i][j] > clock_ticks_start[i][j])
					{
						fprintf(fp, "#%d, #%d, %s %llu \n", i, j, TSC_delta, clock_ticks_stop[i][j] - clock_ticks_start[i][j]);
						fprintf(fp, "#%d, #%d, %s %.9f \n", i, j, ns, nanoseconds[i][j] = (double)(clock_ticks_stop[i][j] - clock_ticks_start[i][j]) / (get_cpu_freq2() * 1.0e-6));
#if GEOMETRIC_MEDIAN
						xj[i][j] = nanoseconds[i][j];
#endif
						average += nanoseconds[i][j];
					}
					else
					{
						fprintf(fp, "%s\n", error);
						break; // go to outer loop.
					}
				}
			}
			average = average / (iters * max_rand_engines);
			fprintf(fp, "%s, %.9f\n", arithm_average, average);
			//double cpy_average = average;
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nanoseconds[i][j] = (nanoseconds[i][j] - average) * (nanoseconds[i][j] - average);
					std_deviation += nanoseconds[i][j];
				}
			}

			fprintf(fp, "%s  %.9f\n", std_dev, sqrt(std_deviation / (iters * max_rand_engines)));
#if GEOMETRIC_MEDIAN
			printf("Attempt to calculate Geomeric Median\n");
			fprintf(fp, "%s\n", geo_med_calc_started);
			
			for (int i = 0; i < iters; ++i)
			{
				for (int j = 0; j < max_rand_engines; ++j)
				{
					nom += xj[i][j] / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					denom += 1.0 / (sqrt((xj[i][j] - oldyi) * (xj[i][j] - oldyi)));
					if ((yi = fabs(nom / denom)) > epsilon)
					{
						//yi = nom / denom;
						oldyi = yi;
					}
					else
					{
						//fprintf(fp, "Error:%s = %2.f15\n", eps_error, yi);
						printf("ERROR: nom / denom == 0.0!!\n");
						goto less_than_epsilon;
					}

				}
			}
		

			fprintf(fp, "%s = %2.15f\n", geo_median, yi);
			printf("Geometric Median = %2.15f\n", yi);

		
#endif
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_std() ended\n");
			printf("Results has been written to %s\n", fname);
#if GEOMETRIC_MEDIAN
		less_than_epsilon :
			fprintf(fp, "%s = %2.15f\n", eps_error, yi);
			fclose(fp);
			printf("Performance Test of fdlib_ml_chol_cran_std() ended\n");
			printf("Results has been written to %s\n", fname);
#endif
		}
	}