#ifndef _LIN_ALG_IMP_H_
#define _LIN_ALG_IMP_H_
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <Windows.h>
#include <immintrin.h>
#include <stdio.h>
#include "linear_algebra.h"
//#include "../FluidDynamicsLibCPPWrapper/StatDistributionWrapper.h"

#if defined __cplusplus
extern "C"
{
	/*
	*  High level interface will provide simple and shallow encapsulation
	*  of C-to-F77 translation.
	*/

	//High-level wrapper interface for chol_c subroutine
	FDLIB_INT fdlib_chol_c(double *, double *, FDLIB_INT);

	//High-level wrapper interface for chol_r subroutine
	FDLIB_INT fdlib_chol_r(double *, double *, FDLIB_INT);

	//High level wrapper interface for det_hess_l subroutine
	FDLIB_INT fdlib_det_hess_l(FDLIB_INT, double *, double);

	//High level wrapper interface for det_hess_u subroutine
	FDLIB_INT fdlib_det_hess_u(FDLIB_INT, double *, double);

	//High level wrapper interface for Det_33c subroutine
	FDLIB_INT fdlib_det_33c(double *, double *, double, double);

	//High level wrapper interface for Det_44c subroutine
	FDLIB_INT fdlib_det_44c(double *, double *, double, double);

	//High level wrapper inteface for inv_l subroutine
	FDLIB_INT fdlib_inv_l(FDLIB_INT, double *, double *);

	//High level wrapper interface for inv_u subroutine.
	FDLIB_INT fdlib_inv_u(FDLIB_INT, double *, double *);

	//High level wrapper interface for ldu subroutine
	FDLIB_INT fdlib_ldu(FDLIB_INT, double *, double *, double *, double *);

	//High level wrapper interface for crout subroutine
	FDLIB_INT fdlib_crout(FDLIB_INT, double *, double *, double *);

	//High level wrapper interface for lu_d_t subroutine
	FDLIB_INT fdlib_lu_d_t(FDLIB_INT, double *, double *, double *, double *, double *);

	//High level wrapper interface for qr_gs subroutine
	FDLIB_INT fdlib_qr_gs(double *, FDLIB_INT, FDLIB_INT, double *, double *);

	//High level wrapper interface for qr_reflex subroutine
	FDLIB_INT fdlib_qr_reflex(double *, FDLIB_INT, double *, double *);

	//High level wrapper intrface for qr_rot subroutine
	FDLIB_INT fdlib_qr_rot(double *, FDLIB_INT, double *, double *);

	// Medium-level wrapper interface for FDLIB subroutines.
	/*
	*  Medium level interface will encapsulate memory and parameter related operations
	*  thus isolating calling client code from need to deal with C-to-F77 translation.
	*/

	
	// Medium level wrapper interface for CHOL_C subroutine.
	FDLIB_INT fdlib_ml_chol_c(FDLIB_INT, int, int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Pre-allocate array passed as an argument.
	FDLIB_INT fdlib_ml_chol_car(FDLIB_INT, double *__restrict, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array. Calls fdlibcppwrapper::UniformDistributionsWrapper<double>::binomial_distribution_wrapper();
	FDLIB_INT fdlib_ml_chol_cran(FDLIB_INT, const int);

	//Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array. Calls fdlibcppwrapper::PoissonDistributionWrapper<double>::poisson_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_pd(FDLIB_INT, const int);

	//Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::PoissonDistributionWrapper<double>::gamma_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_gd(FDLIB_INT, const int);

	//Medium level wrapper interfce for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::PoissonDistributionWrapper<double>::weibull_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_wd(FDLIB_INT, const int);

	//Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::PoissonDistributionWrapper<double>::extreme_value_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_evd(FDLIB_INT, const int);

	//Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to flibcppwrapper::NormalDistributionWrapper<double>::normal_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_nd(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::lognormal_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_lnd(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::chi_squared_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_csd(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::cauchy_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_cd(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::fisher_f_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_fd(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::student_t_distribution_wrapper().
	FDLIB_INT fdlib_ml_chol_cran_std(FDLIB_INT, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::poisson_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l array).
	FDLIB_INT fdlib_ml_chol_cran_pd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::gamma_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l array).
	FDLIB_INT fdlib_ml_chol_cran_gd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::weibull_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l array).
	FDLIB_INT fdlib_ml_chol_cran_wd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::extreme_value_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l array).
	FDLIB_INT fdlib_ml_chol_cran_evd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::normal_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_nd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::lognormal_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_lnd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::chi_squared_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_csd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::cauchy_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_cd_user(FDLIB_INT, double * __restric, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::fisher_f_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_fd_user(FDLIB_INT, double * __restrict, const int, const int);

	// Medium level wrapper interface for CHOL_C subroutine.
	// Random-fill array by call to fdlibcppwrapper::NormalDistributionWrapper<double>::fisher_f_distribution_wrapper().
	// Returns through the argument user passed array filled with the result of Cholesky C decomposition(l(100,100) array).
	FDLIB_INT fdlib_ml_chol_cran_sd_user(FDLIB_INT, double * __restrict, const int, const int);


	// Medium level wrapper interface for CHOL_R subroutine.
	FDLIB_INT fdlib_ml_chol_r(FDLIB_INT, int, int);

	// Medium level wrapper interface for CHOL_R subroutine.
	// Pre-allocate array passed as an argument.
	FDLIB_INT fdlib_ml_chol_rar(FDLIB_INT, double *__restrict, const int);

	// Medium level wrapper inteface for DET_HESS_L subroutine.
	FDLIB_INT fdlib_ml_det_hess_l(FDLIB_INT, int, int);

	// Medium level wrapper interface for DET_HESS_L subroutine.
	// Pre-allocated array passed as an argument.
	FDLIB_INT fdlib_ml_det_hess_l_ar(FDLIB_INT , double * __restrict, const int);

	// Medium level wrapper interface for DET_HESS_U subroutine.
	FDLIB_INT fdlib_ml_det_hess_u(FDLIB_INT, int, int);

	// Medium level wrapper interface for DET_HESS_U subroutine.
	// Pre-allocated array passed as an argument.
	FDLIB_INT fdlib_ml_det_hess_u_ar(FDLIB_INT, double * __restrict, const int);

	// Global inline functions:
	inline long long get_cpu_freq2()
	{

		//Crude approximate of CPU frequency.
		long long ts0 = 0LL;
		long long ts1 = 0LL;
		ts0 = _rdtsc();
		Sleep(1);
		ts1 = _rdtsc();
		return ts1 - ts0;
	}
	//Algorythmic correctness check routines.
#if defined _DEBUG

	FDLIB_INT test_chol_c_alg_correctnes(FDLIB_INT, double * __restrict, double * __restrict);
#endif // _DEBUG
}
#endif //extern "C"

#endif