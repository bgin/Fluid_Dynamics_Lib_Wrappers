
#include "stats_functions.h"
#include "CHOL_C_TEST.h"
#include <Windows.h>

int main(int argc, char *argv[])
{
	/*const int mask = 0x1;
	HANDLE ThreadHandle = GetCurrentThread();
    DWORD_PTR prev_mask =	SetThreadAffinityMask(ThreadHandle, mask);
	if (prev_mask == 0)
		printf(" prev_mask = %d SetThreadAffinityMask failed with an error: 0x%x\n", prev_mask,GetLastError());*/
	set_cpu_affinity();
	//Run_fdlib_ml_chol_c_gnr_tests();
	//Run_fdlib_ml_chol_c_inv_tests();
	
	//Run_fdlib_ml_chol_c_alg_tests();
	//Test_fdlib_ml_chol_cran_perf();
	//Run_fdlib_ml_chol_c_timing_test();
	//Test_fdlib_ml_chol_cran_std_perf();
	Test_skew_wf();
	getchar();
	return 0;
}