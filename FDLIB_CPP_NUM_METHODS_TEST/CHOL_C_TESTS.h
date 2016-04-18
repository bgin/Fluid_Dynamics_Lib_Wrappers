
#ifndef _CHOL_C_TESTS_H_
#define  _CHOL_C_TESTsS_H_

#include "STD_DEFS.h"
#include "../FluidDynamicsLibCPPWrapper/lin_alg.h"
#include <memory>
#include <functional>
namespace test
{

	class TestCholeskyC
	{

	public:

		// Test Class which exercises CholeskyC implementation.

		// Generic Functionality Tests.

		// Simple single object creation test
		static void Test_Ctor();

		// Simple single object creation test. Return by value
		static fdlibcppwrapper::CholeskyC Test_Ret_Ctor();

		// Simple single object creation test. Return by reference to heap created object.
		static fdlibcppwrapper::CholeskyC & Test_Ref_Ctor();

		// Simple single object creation test. Return by pointer to heap allocation.
		static fdlibcppwrapper::CholeskyC * Test_Ptr_Ctor();

		// Simple single object creation test. Return by std::unique_ptr<CholeskyC>.
		static std::unique_ptr<fdlibcppwrapper::CholeskyC> Test_SPtr_Ctor();

		// Simple single object creation test. Return by lambda
		static std::function<fdlibcppwrapper::CholeskyC(const int)> Test_Lambda_Ctor();

		// Simple single object creation test. Return std::vector<fdlibcppwrapper::CholeskyC *>
		std::vector<fdlibcppwrapper::CholeskyC *> Test_Vec_Ctor();

		// CholeskyC::CholeskyC(const int) creation test.
		static void Test_Ctor(const int, const double, const double,fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines );

		// Simple single object creation test.Return by value
		static fdlibcppwrapper::CholeskyC Test_Ret_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		// Simple single object creation test. Return by reference to heap created object.
		static fdlibcppwrapper::CholeskyC & Test_Ref_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		// Simple single object creation test. Return by pointer to heap created object.
		static fdlibcppwrapper::CholeskyC * Test_Ptr_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);
		// Simple single object creation test. Return by std::unique_ptr<CholeskyC > smart pointer.
		static std::unique_ptr<fdlibcppwrapper::CholeskyC> Test_SPtr_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		// Simple single object creation test. Return lambda wrapped in std::function functor.
		static std::function<fdlibcppwrapper::CholeskyC(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines)>
			Test_Lambda_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		// Simple single object creation test. Returns vector of CholeskyC pointers, std::vector<CholeskyC*>
		static std::vector<fdlibcppwrapper::CholeskyC *> Test_Vec_Ctor(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

        

		// CholeskyC::CholeskyC(const int, REAL lo, REAL up) creation test.
		static void Test_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return object by value.
		static fdlibcppwrapper::CholeskyC Test_Ret_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return object by referency to heap allocated object.
		static fdlibcppwrapper::CholeskyC & Test_Ref_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return an object by raw pointer to CholeskyC
		static fdlibcppwrapper::CholeskyC * Test_Ptr_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return an object by std::unique_ptr.
		static std::unique_ptr<fdlibcppwrapper::CholeskyC> Test_SPtr_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return std::function functor containing lambda object.
		static std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> Test_Lambda_Ctor(const int, REAL, REAL);

		// Simple single object creation test. Return vector of CholeskyC pointers.
		static std::vector<fdlibcppwrapper::CholeskyC *> Test_Vec_Ctor(const int, REAL, REAL);

		// CholeskyC::CholeskyC(std::vector<REAL>&) creation test.
		static void Test_Ctor(std::vector<REAL>&);

		// Simple single object creation test. Returns object by value.
		static fdlibcppwrapper::CholeskyC Test_Ret_Ctor(std::vector<REAL>&);

		// Simple single object creation test. Returns a reference to heap allocated object.
		static fdlibcppwrapper::CholeskyC & Test_Ref_Ctor(std::vector<REAL>&);

		// Simple single object creation test. Returns a pointer to heap allocated object.
		static fdlibcppwrapper::CholeskyC * Test_Ptr_Ctor(std::vector<REAL>&);

		// Simple single object creation test. Returns smart pointer to CholeskyC object.
		static std::unique_ptr<fdlibcppwrapper::CholeskyC> Test_SPtr_Ctor(std::vector<REAL>&);

		// Simple single object creation test. Returns std::function functor initialized by lambda.
		static std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> Test_Lambda_Ctor(std::vector<REAL> &);

		// CholeskyC::CholeskyC(const CholeskyC& ) creation test.
		static void Test_Ctor(const fdlibcppwrapper::CholeskyC&);

		// CholeskyC::~CholeskyC() indirect destruction test.
		static void Test_Dtor();

		// Static array of objects type CholeskyC - creation test.
		static void Test_Chol_C_Static_Pool();

		// Dynamic array of objects type CholeskyC - creation test.
		static void Test_Chol_C_Dynamic_Pool(const int);

		// CholeskyC::operator=(const CholeskyC&) - operator assignment test.
		static void Test_Chol_C_op_assignment();

		// CholeskyC::operator=(const CholeskyC&) - operator assignment test. Running on static pool of CholeskyC objects.
		static void Test_Chol_C_op_assignment_st_pool();

		// CholeskyC::operator=(const CholeskyC&) - operator assignment test. Running on dynamic pool of CholeskyC objects.
		static void Test_Chol_C_op_assignment_dy_pool(const int);

		// CholeskyC::operator+=(const CholeskyC&) - operator plus assignment test.
		static void Test_Chol_C_op_plus();

		// CholeskyC::operator+=(const CholeskyC&) - operator plus assignment test. Running on static pool of CholeskyC objects.
		static void Test_Chol_C_op_plus_st_pool();

		// CholeskyC::operator+=(const CholeskyC&) - operator plus assignment test. Running on dynamic pool of CholeskyC objects.
		static void Test_Chol_C_op_plus_dy_pool(const int);


		// Lambdas test
		static void LambdasTest();


		// Tests of CholeskyC::CholeskyC(const int) Constructor.
		static void Run_Ctor1_Tests();

		// Tests of CholeskyC::CholeskyC(const int, REAL,REAL) Constructor.
		static void Run_Ctor2_Tests();

		// Tests of CholeskyC::CholeskyC(std::vector<REAL>&) Constructor.
		static void Run_Ctor3_Tests();

		// Tests of CholeskyC::CholeskyC(const CholeskyC& ) Constructor.
		static void Run_Ctor4_Tests();

		// Running Functionlity Tests.
		static void Run_Ctor1_Funct_Tests();

		// Running Assert Tests.
		static void Run_Ctor1_Assert_Tests();

		static void Run_Ctor1_Ref_Assert_Tests();

		static void Run_Ctor1_Ptr_Assert_Tests();

		static void Run_Ctor1_SPtr_Assert_Tests();

		static void Run_Ctor1_Lambda_Assert_Tests();

		static void Run_Ctor1_EPS_Accuracy_Tests();

		private:

			
			static void AssertEqual( fdlibcppwrapper::CholeskyC &,  fdlibcppwrapper::CholeskyC &,  std::vector<std::pair<double,double>>& , std::vector<std::pair<double,double>>&,
				const double, const char *, const char *);

		    static	void AssertNotEqual( fdlibcppwrapper::CholeskyC &, fdlibcppwrapper::CholeskyC &, std::vector<std::pair<double,double>>&, std::vector<std::pair<double,double>>&,
				const double, const char *, const char *);
			
			// class helper functions.
			std::function<fdlibcppwrapper::CholeskyC()> Ret_Lambda_UnInit();

			std::function<fdlibcppwrapper::CholeskyC()> Ret_Lambda_Init();

			std::function<fdlibcppwrapper::CholeskyC()> Ret_Lambda_Chol_c();

			std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> Ret_Lambda_Init(const int, REAL, REAL);

			std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> Ret_Lambda_Chol_c(const int, REAL, REAL);

			std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> Ret_Lambda_Init(std::vector<REAL>&);

			std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> Ret_Lambda_Chol_c(std::vector<REAL>&);

			std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC&)> Ret_Lambda_Init(const fdlibcppwrapper::CholeskyC &);

			std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC&)> Ret_Lambda_Chol_c(const fdlibcppwrapper::CholeskyC &);

			std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int,const int, REAL, REAL)> Ret_Lambda_Vec_Init(const int,const int, REAL, REAL);

			std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int, const int, REAL, REAL)> Ret_Lambda_Vec_Chol_c(const int, const int, REAL, REAL);

			std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> Ret_Lambda_Vec_Init(const int);

			std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> Ret_Lambda_Vec_Chol_c(const int);

			std::function < std::vector < fdlibcppwrapper::CholeskyC>(const double)> Ret_Lambda_Vec_PTR_ND1(const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double)> Ret_Lambda_Vec_PTR_ND1_Chol_c(const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double, const double)> Ret_Lambda_Vec_PTR_ND2(const double, const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double, const double)> Ret_Lambda_Vec_PTR_ND2_Chol_c(const double, const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double)> Ret_Lambda_Vec_PTR_PD1(const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double)> Ret_Lambda_Vec_PTR_PD1_Chol_c(const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double, const double)> Ret_Lambda_Vec_PTR_PD2(const double, const double);

			std::function< std::vector  < fdlibcppwrapper::CholeskyC>(const double, const double)> Ret_Lambda_Vec_PTR_PD2_Chol_c(const double, const double);
 	};
	static const char * const Assertion_Failed = "Assertion Failed: NOT_EQUAL_VALUES";
	static const char * const Assertion_Succeded = "Assertion Succeded: EQUAL_VALUES";
	



	class TestCh : public fdlibcppwrapper::CholeskyC
	{

	public:

		TestCh();

		

	private:

		std::vector<REAL> m_vec_a;
		std::vector<REAL> m_vec_l;
		FDLIB_INT m_N;

	};
}

#endif /*_CHOL_C_TESTS_H_*/