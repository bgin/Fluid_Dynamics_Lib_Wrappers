#ifndef _NUM_METHODS_TESTS_H_
#define _NUM_METHODS_TESTS_H_
#include <assert.h>
#include <Windows.h>
#include "lin_alg_imp.h"



// Simple test methods.

/*
 * Test_fdlib_ml_det_hess_l() simple test wrapper which
 * calls fdlib_ml_det_hess_l function. Only return value is tested by using assert statement.
 * Arguments for tested functions are hardcoded.
 */
void Test_fdlib_ml_det_hess_l();

/*
* Test_fdlib_ml_det_hess_u() simple test wrapper which
* calls fdlib_ml_det_hess_() function. Only return value is tested by using assert statement.
* Arguments for tested functions are hardcoded.
*/
void Test_fdlib_ml_det_hess_u();

/*
* Test_fdlib_ml_chol_c() simple test wrapper
* which call fdlib_ml_chol_c() function. Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
void Test_fdlib_ml_chol_c();

/*
* Test_fdlib_ml_chol_car() simple test wrapper
* which call fdlib_ml_chol_car() function. Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
void Test_fdlib_ml_chol_car();

/*
* Test_fdlib_ml_chol_cran() simple test wrapper
* which call fdlib_ml_chol_cran() function.Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
  
void Test_fdlib_ml_chol_cran();

/*
* Test_fdlib_ml_chol_cran_pd() simple test wrapper
* which call fdlib_ml_chol_cran() function.Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
void Test_fdlib_ml_chol_cran_pd();

/*
* Test_fdlib_ml_chol_cran_gd() simple test wrapper
* which call fdlib_ml_chol_cran() function.Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
void Test_fdlib_ml_chol_cran_gd();

/*
* Test_fdlib_ml_chol_cran_gd_user() simple test wrapper
* which call fdlib_ml_chol_r() function. Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/
void Test_fdlib_ml_chol_cran_gd_user();

/*
* Test_fdlib_ml_chol_r() simple test wrapper
* which call fdlib_ml_chol_r() function. Only return value is tested by using assert statement.
* Arguments for tested function are hardcoded.
*/



void Test_fdlib_ml_chol_r();

// Runs all simple tests.
void RunTests();
#endif /*_NUM_METHODS_TESTS_H_*/