//#include "lin_alg_imp.h"
#include "NumMethodsTests.h"
int main(int argc, char *argv[])
{
	/*const int ten = 10;
	FDLIB_INT result = fdlib_ml_det_hess_l(ten,-1,1);
	//double * a = (double *)_mm_malloc(10 * sizeof(double), 32);
	//if (a != NULL) printf("succeeded\n");*/
	RunTests();
	/*double * aa = (double *)_mm_malloc(100 * sizeof(double), 32);
	for (int i = 0; i != 100; ++i) aa[i] = (double)i;
	const int data_size = 100;
	FDLIB_INT result2 = fdlib_ml_det_hess_l_ar(10, aa, data_size);*/
	getchar();
	return 0;
}
	