
#include "CHOL_C_TESTS.h"
#include <immintrin.h>


void test::TestCholeskyC::Test_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int)\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(size);
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Object initialization with call to statistical distribution functions\n");
	test_obj.cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("test_obj - initialized with call to cauchy_distr_fill() wrapper function\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif

	/*	std::printf("test_obj initialized with indirect call through pointer to member function: student_distr_fill\n");
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		fdlibcppwrapper::CholeskyC::PTR_ND1 ptr_nd1 = &fdlibcppwrapper::CholeskyC::student_distr_fill;
		test_obj.operator()(ptr, ptr_nd1, a, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
		#if PRINT_DATA
		test_obj.debug_print();
		#endif*/
	std::printf("Finished single Test of CholeskyC::CholeskyC(const int)\n");
}

fdlibcppwrapper::CholeskyC test::TestCholeskyC::Test_Ret_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and object return by value\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(size);
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Object initialization with call to statistical distribution functions\n");
	test_obj.cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning test_obj by value\n");
	return test_obj;
}

fdlibcppwrapper::CholeskyC & test::TestCholeskyC::Test_Ref_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and object return by reference\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	fdlibcppwrapper::CholeskyC & test_obj = *new fdlibcppwrapper::CholeskyC(size);
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	test_obj.cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning test_obj by reference to heap allocation\n");
	return test_obj;
}

fdlibcppwrapper::CholeskyC * test::TestCholeskyC::Test_Ptr_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and object return by pointer to heap allocation\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(size);
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	test_obj->cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning test_obj by pointer to heap allocation\n");
	return test_obj;
}

std::unique_ptr<fdlibcppwrapper::CholeskyC> test::TestCholeskyC::Test_SPtr_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and object return by std::unique_ptr \n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(size);
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	test_obj->cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning test_obj by wrapping into std::unique_ptr smart pointer\n");
	std::unique_ptr<fdlibcppwrapper::CholeskyC> ret_ptr{ test_obj };
	return ret_ptr;
}

std::function<fdlibcppwrapper::CholeskyC(const int)> test::TestCholeskyC::Test_Lambda_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and object return by std::function\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::printf("Object creation and default initialization\n");
	std::function<fdlibcppwrapper::CholeskyC(const int)> functor = [=](const int n)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
#if PRINT_DATA
		test_obj.debug_print();
#endif
		std::printf("object initialization with call to statistical distribution functions\n");
		test_obj.cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
		std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
		test_obj.debug_print();
#endif
		std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning test_obj by wrapping it into std::function object\n");
		return test_obj;
	};
	
	
	return functor;

}
	
std::vector<fdlibcppwrapper::CholeskyC *> test::TestCholeskyC::Test_Vec_Ctor()
{
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) object creation and objects return by std::vector\n");
	const int size = 10;
	const double a = 2.5L;
	const double b = 10.5L;
	std::vector<fdlibcppwrapper::CholeskyC *> vec(size);
	
	std::printf("Object creation and default initialization\n");
	for (auto i = 0; i != size; ++i)
	{
		vec.push_back(new fdlibcppwrapper::CholeskyC(size));
		//t.push_back(0.5L);
		
	}
#if PRINT_DATA
	for (auto i = 0; i != vec.size(); ++i)
	{
		vec[i]->debug_print();
	}
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	for (auto i = 0; i != vec.size(); ++i)
	{
		vec[i]->cauchy_distr_fill(a, b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
#if PRINT_DATA
		vec[i]->debug_print();
#endif
	}
	std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
	std::printf("Finished Test of CholeskyC::CholeskyC(const int) - returning std::vector<CholeskyC *> \n");
	return vec;
}
	

void test::TestCholeskyC::Test_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	std::printf(" void test::TestCholeskyC::Test_Ctor(const int, const double, const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_result = test_obj.cauchy_distr_fill(a, b, engine);
	if (!b_result)
		std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
	else
	    std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");

#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
}


fdlibcppwrapper::CholeskyC test::TestCholeskyC::Test_Ret_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines
	engine)
{
	std::printf(" CholeskyC test::TestCholeskyC::Test_Ret_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "test_obj_default_initialization.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_result = test_obj.cauchy_distr_fill(a, b, engine);
	if (!b_result)
		std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
	else
		std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");

#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname2 = "test_obj_cauchy_distribution_init.csv";
	test_obj.print_to_file(fname2);
	delete fname2;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	return test_obj;
}


fdlibcppwrapper::CholeskyC & test::TestCholeskyC::Test_Ref_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines
	engine)
{
	std::printf(" CholeskyC & test::TestCholeskyC::Test_Ref_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC & test_obj = *new fdlibcppwrapper::CholeskyC(n);
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ref_Ctor_obj_default_initialization.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_result = test_obj.cauchy_distr_fill(a, b, engine);
	if (!b_result)
	    std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
	else
		std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");

#if PRINT_DATA
		test_obj.debug_print();
#endif
#if PRINT_TO_FILE
		const char *fname2 = "Test_Ref_Ctor_obj_cauchy_distribution_init.csv";
		test_obj.print_to_file(fname2);
		delete fname2;
#endif
		std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
		return test_obj;
}


fdlibcppwrapper::CholeskyC * test::TestCholeskyC::Test_Ptr_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines
	engine)
{
	std::printf(" CholeskyC & test::TestCholeskyC::Test_Ptr_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(n);
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ptr_Ctor_obj_default_init.csv";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_result = test_obj->cauchy_distr_fill(a, b, engine);
	if (!b_result)
		std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
	else
		std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname2 = "Test_Ptr_Ctor_obj_cauchy_distr_init.csv";
	test_obj->print_to_file(fname2);
	delete fname2;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	return test_obj;
}


std::unique_ptr<fdlibcppwrapper::CholeskyC> test::TestCholeskyC::Test_SPtr_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines
	engine)
{
	std::printf(" CholeskyC & test::TestCholeskyC::Test_SPtr_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(n);
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_SPtr_Ctor_obj_default_init";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_result = test_obj->cauchy_distr_fill(a, b, engine);
	if (!b_result)
		std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
	else
		std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname2 = "Test_SPtr_Ctor_obj_cauchy_distr_init";
	test_obj->print_to_file(fname2);
	delete fname2;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	std::unique_ptr<fdlibcppwrapper::CholeskyC> ret_ptr{ test_obj };
	return ret_ptr;
}

/*std::function<fdlibcppwrapper::CholeskyC(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines)> 
test::TestCholeskyC::Test_Lambda_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	std::printf(" CholeskyC & test::TestCholeskyC::Test_Lambda_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	std::function<fdlibcppwrapper::CholeskyC(const int, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines)> functor;
	functor = [](const int n, const double a, const double b,fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
#if PRINT_DATA
		test_obj.debug_print();
#endif
#if PRINT_TO_FILE
		const char *fname = "Test_Lambda_Ctor_default_init.csv";
		test_obj.print_to_file(fname);
		delete fname;
#endif
		std::printf("object initialization with call to statistical distribution functions\n");
		bool b_result = test_obj.cauchy_distr_fill(a, b, engine);
		if (!b_result)
			std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_result);
		else
			std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
#if PRINT_DATA
		test_obj.debug_print();
#endif
#if PRINT_TO_FILE
		const char *fname2 = "Test_Lambda_Ctor_cauchy_distr_init.csv";
		test_obj.print_to_file(fname2);
		delete fname2;
#endif
		std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");


	               };
	
	return functor;
}*/

std::vector<fdlibcppwrapper::CholeskyC *> test::TestCholeskyC::Test_Vec_Ctor(const int n, const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines
	engine)
{
	std::printf(" CholeskyC & test::TestCholeskyC::Test_Vec_Ctor(const int, const double,const double, NormalDistributionImpl::RandomNumberEngine) - Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	std::vector<fdlibcppwrapper::CholeskyC *> vec(n);
	for (auto i = 0; i != vec.size(); ++i)
	{
		// unnamed object is pushed into vector, hence move constructor is called.
		vec.push_back(new fdlibcppwrapper::CholeskyC(n));
	}
	std::printf("Object creation and default initialization\n");
#if PRINT_DATA
	for (auto i = 0; i != vec.size(); ++i)
	{
		vec[i]->debug_print();
	}
#endif
	std::printf("object initialization with call to statistical distribution functions\n");
	bool b_results[10] = { false };
	for (auto i = 0; i != vec.size(); ++i)
	{
		b_results[i] = vec[i]->cauchy_distr_fill(a, b, engine);
		if (!b_results[i])
			std::printf("CholeskyC::cauchy_distr_fill() failed with an error value: %d\n", b_results[i]);
		else
			std::printf("test_obj - initialized with call to cauchy_distr_fill() with DEFAULT_RANDOM_ENGINE\n");
	}
#if PRINT_DATA
	for (auto i = 0; i != vec.size(); ++i)
	{
		vec[i]->debug_print();
	}
#endif
#if PRINT_TO_FILE
	const char *fnames[] = { "Test_Vec_Ctor_obj_cauchy_distr_init1.csv", "Test_Vec_Ctor_obj_cauchy_distr_init2.csv",
		"Test_Vec_Ctor_obj_cauchy_distr_init3.csv", "Test_Vec_Ctor_obj_cauchy_distr_init4.csv",
		"Test_Vec_Ctor_obj_cauchy_distr_init5.csv", "Test_Vec_Ctor_obj_cauchy_distr_init6.csv",
		"Test_Vec_Ctor_obj_cauchy_distr_init7.csv", "Test_Vec_Ctor_obj_cauchy_distr_init8.csv",
		"Test_Vec_Ctor_obj_cauchy_distr_init9.csv", "Test_Vec_Ctor_obj_cauchy_distr_init10.csv" };
	for (auto i = 0; i != vec.size(); ++i) vec[i]->print_to_file(fnames[i]);
	delete []fnames;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int) and CholeskyC::cauchy_distr_fill() wrapper function\n");
	return vec;

}

void    test::TestCholeskyC::Test_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" void test::TestCholeskyC::Test_Vec_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n,lo,hi);
	
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Object initialization with call to HW RDRAND wrapper function\n");
#if PRINT_TO_FILE
	const char *fname = "Test_Ctor_obj_rdrand_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL, REAL) and CholeskyC::rand_fill() wrapper function\n");

}

fdlibcppwrapper::CholeskyC test::TestCholeskyC::Test_Ret_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" CholeskyC test::TestCholeskyC::Test_Ret_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n,lo,hi);

#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Object initialization with the call to HW RDRAND wrapper functions\n");
#if PRINT_DATA
	const char *fname = "Test_Ret_Ctor_obj_rdrand_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL, REAL) and CholeskyC::rand_fill() wrapper function\n");
	return test_obj;
}

fdlibcppwrapper::CholeskyC & test::TestCholeskyC::Test_Ref_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" CholeskyC  & test::TestCholeskyC::Test_Ref_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC & test_obj = *new fdlibcppwrapper::CholeskyC(n,lo,hi);
#if PRINT_DATA
	test_obj.debug_print();
#endif
	std::printf("Object initialization with the call to HW RDRAND wrapper functions\n");
#if PRINT_TO_FILE
	const char *fname = "Test_Ref_Ctor_obj_rdrand_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL, REAL) and CholeskyC::rand_fill() wrapper function\n");
	return test_obj;
}


fdlibcppwrapper::CholeskyC * test::TestCholeskyC::Test_Ptr_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" CholeskyC  * test::TestCholeskyC::Test_Ref_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(n, lo, hi);
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("Object initialization with the call to HW RDRAND wrapper functions\n");
#if PRINT_TO_FILE
	const char *fname = "Test_Ptr_Ctor_obj_rdrand_init.csv";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL,REAL) and CholeskyC::rand_fill() wrapper function\n");
	return test_obj;


}

std::unique_ptr<fdlibcppwrapper::CholeskyC> test::TestCholeskyC::Test_SPtr_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" std::unique_ptr<CholeskyC>   test::TestCholeskyC::Test_Ref_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(n, lo, hi);
#if PRINT_DATA
	test_obj->debug_print();
#endif
	std::printf("Object initialization with the call to HW RDRAND wrapper functionality\n");
#if PRINT_TO_FILE
	const char *fname = "Test_SPtr_Ctor_obj_rdrand_init.csv";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL,REAL) and CholeskyC::rand_fill() wrapper function\n");
	std::unique_ptr<fdlibcppwrapper::CholeskyC> ret_ptr{ test_obj };
	return ret_ptr;
}


std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> test::TestCholeskyC::Test_Lambda_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" std::function<fdlibcppwrapper::CholeskyC(const int, REAL,REAL)>   test::TestCholeskyC::Test_Ref_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> functor;
	functor = [](const int n, REAL lo, REAL hi)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n, lo, hi);
#if PRINT_DATA
		test_obj.debug_print();
#endif
		std::printf("Object initialization with the call to HW RDRAND wrapper functionality\n");
#if PRINT_TO_FILE
		const char *fname = "Test_Lambda_Ctor_rdrand_init.csv";
		test_obj.print_to_file(fname);
		delete fname;
#endif
		std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL,REAL) and CholeskyC::rand_fill() wrapper function\n");
		return test_obj;
	};
	return functor;
}

std::vector<fdlibcppwrapper::CholeskyC *> test::TestCholeskyC::Test_Vec_Ctor(const int n, REAL lo, REAL hi)
{
	std::printf(" std::function<fdlibcppwrapper::CholeskyC(const int, REAL,REAL)>   test::TestCholeskyC::Test_Ref_Ctor(const int, REAL, REAL)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(const int, REAL,REAL) and rand_fill() wrapper function\n");
	std::vector<fdlibcppwrapper::CholeskyC *> vec(n);
	for (auto i = 0; i != vec.size(); ++i) vec.push_back(new fdlibcppwrapper::CholeskyC(n, lo, hi));

	std::printf("Object initialization with the call to HW RDRAND wrapper functionality\n");
#if PRINT_DATA
	for (auto i = 0; i != vec.size(); ++i) vec[i]->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fnames[] = { "Test_Vec_Ctor_obj_rdrand_init1.csv", "Test_Vec_Ctor_obj_rdrand_init2.csv",
		"Test_Vec_Ctor_obj_rdrand_init3.csv", "Test_Vec_Ctor_obj_rdrand_init4.csv",
		"Test_Vec_Ctor_obj_rdrand_init5.csv", "Test_Vec_Ctor_obj_rdrand_init6.csv",
		"Test_Vec_Ctor_obj_rdrand_init7.csv", "Test_Vec_Ctor_obj_rdrand_init8.csv",
		"Test_Vec_Ctor_obj_rdrand_init9.csv", "Test_Vec_Ctor_obj_rdrand_init10.csv" };
	for (auto i = 0; i != vec.size(); ++i) vec[i]->print_to_file(fnames[i]);

	delete[] fnames;
#endif
	std::printf("Finished single test of CholeskyC::CholeskyC(const int, REAL,REAL) and CholeskyC::rand_fill() wrapper function\n");

	return vec;

}
 
void test::TestCholeskyC::Test_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" void test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) \n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(rhs);
	std::printf("Object already initialized by Ctor argument: std::vector<REAL>& rhs\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ctor_obj_std::vector_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
}

fdlibcppwrapper::CholeskyC test::TestCholeskyC::Test_Ret_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" fdlibcppwrapper::CholeskyC test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test. \n");
	fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(rhs);
	std::printf("Object already initialized by Ctor argument: std::vector<REAL>& rhs\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ret_Ctor_obj_std::vector_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
	return test_obj;
}

fdlibcppwrapper::CholeskyC & test::TestCholeskyC::Test_Ref_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" fdlibcppwrapper::CholeskyC &  test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test. \n");
	fdlibcppwrapper::CholeskyC & test_obj =  * new fdlibcppwrapper::CholeskyC(rhs);
	std::printf("Object already initialized by Ctor argument: std::vector<REAL>& rhs\n");
#if PRINT_DATA
	test_obj.debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ref_obj_std::vector_init.csv";
	test_obj.print_to_file(fname);
	delete fname;
#endif
	std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
	return test_obj;
	
}

fdlibcppwrapper::CholeskyC * test::TestCholeskyC::Test_Ptr_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" fdlibcppwrapper::CholeskyC *  test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test. \n");
	// Although not recommended created heap object inside local scope, for sake of test this is here created.
	// Exception can be thrown here leaving object initialized to non-existant memory.
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(rhs);
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_Ptr_obj_std::vector_init.csv";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
	return test_obj;
}

std::unique_ptr<fdlibcppwrapper::CholeskyC> test::TestCholeskyC::Test_SPtr_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" std::unique_ptr<fdlibcppwrapper::CholeskyC>   test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test. \n");
	fdlibcppwrapper::CholeskyC * test_obj = new fdlibcppwrapper::CholeskyC(rhs);
#if PRINT_DATA
	test_obj->debug_print();
#endif
#if PRINT_TO_FILE
	const char *fname = "Test_SPtr_obj_std::vector_init.csv";
	test_obj->print_to_file(fname);
	delete fname;
#endif
	std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
	std::unique_ptr<fdlibcppwrapper::CholeskyC> ret_ptr{ test_obj };
	return ret_ptr;
}


std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> test::TestCholeskyC::Test_Lambda_Ctor(std::vector<REAL>& rhs)
{
	std::printf(" std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)>   test::TestCholeskyC::Test_Ctor(std::vector<REAL>&)- Executing Now\n");
	std::printf("Beginning single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test. \n");
	std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> functor;
	functor = [](std::vector<REAL>& rhs)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(rhs);
#if PRINT_DATA
		test_obj.debug_print();
#endif
#if PRINT_TO_FILE
		const char *fname = "Test_Lambda_Ctor_obj_std::vector_init.csv";
		test_obj.print_to_file(fname);
		delete fname;
#endif
		std::printf("Finishing single Test of CholeskyC::CholeskyC(std::vector<REAL>&) - object construction test.\n");
		return test_obj;
	};
	return functor;
}



void test::TestCholeskyC::LambdasTest()
{
	std::printf("Begining of CholeskyC based Lambda functor tests\n");
	std::printf("Simple named lambda creation test\n");
	auto test_lambda1 = [](const int n)
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
		test_obj.debug_print();
		std::printf("Default initialization\n");
		
	};
	test_lambda1(10);
	std::printf("Finished testing named lambda: test_lambda1 \n");
	
	auto test_lambda2 = [](const int n, const double a, const double b,  fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n);
		std::printf("Initializng std::vector<REAL> m_a by the call to cauchy distribution function\n");
		std::printf("Arguments: a = %2.15f, b = %2.15f, no. engine = %d\n", a, b, engine);
		test_obj.cauchy_distr_fill(a, b, engine);
#if PRINT_DATA
		test_obj.debug_print();
#endif
		std::printf("Calling CHOL_C F77 subroutine\n");
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
		
#if PRINT_DATA
		test_obj.debug_print();
#endif
	};
	test_lambda2(10, 0.5, 2.5, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::DEFAULT_RANDOM_ENGINE);
	std::printf("Finished testing named lambda: test_lambda2\n");
	
	const auto iters = 10;
	double a = 0.0L;
	double b = 1.0L;
	std::printf("Beginning: %d iterations  of test_lambda2 functor\n",iters);
	std::printf("Initial arguments: a = %2.15f, b = %2.15f", a, b);
	for (auto i = 0; i != 10; ++i)
		test_lambda2(10, a += 0.1, b += 0.1, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(i));

	std::printf("Finished:  %d iterations   of test_lambda2 functor\n",iters);
	

		auto test_lambda3 = [](double a, double b)
		{
			fdlibcppwrapper::CholeskyC::PTR_ND1 ar_ptr_nd1[2];
			fdlibcppwrapper::CholeskyC::PTR_ND2 ar_ptr_nd2[4];
			fdlibcppwrapper::CholeskyC::PTR_PD1 ar_ptr_pd1[1];
			fdlibcppwrapper::CholeskyC::PTR_PD2 ar_ptr_pd2[3];
			ar_ptr_nd1[0] = &fdlibcppwrapper::CholeskyC::student_distr_fill;
			ar_ptr_nd1[1] = &fdlibcppwrapper::CholeskyC::chisquared_distr_fill;
			ar_ptr_nd2[0] = &fdlibcppwrapper::CholeskyC::cauchy_distr_fill;
			ar_ptr_nd2[1] = &fdlibcppwrapper::CholeskyC::fisher_distr_fill;
			ar_ptr_nd2[2] = &fdlibcppwrapper::CholeskyC::lognorm_distr_fill;
			ar_ptr_nd2[3] = &fdlibcppwrapper::CholeskyC::norm_distr_fill;
			ar_ptr_pd1[0] = &fdlibcppwrapper::CholeskyC::exp_distr_fill;
			ar_ptr_pd2[0] = &fdlibcppwrapper::CholeskyC::extr_val_distr_fill;
			ar_ptr_pd2[1] = &fdlibcppwrapper::CholeskyC::gamma_distr_fill;
			ar_ptr_pd2[2] = &fdlibcppwrapper::CholeskyC::weibull_distr_fill;
			fdlibcppwrapper::CholeskyC test_obj1 = fdlibcppwrapper::CholeskyC(10);
			fdlibcppwrapper::CholeskyC test_obj2 = fdlibcppwrapper::CholeskyC(10);
			fdlibcppwrapper::CholeskyC test_obj3 = fdlibcppwrapper::CholeskyC(10);
			fdlibcppwrapper::CholeskyC test_obj4 = fdlibcppwrapper::CholeskyC(10);
			fdlibcppwrapper::CholeskyC * ptr = &test_obj1;
			fdlibcppwrapper::CholeskyC * ptr2 = &test_obj2;
			fdlibcppwrapper::CholeskyC * ptr3 = &test_obj3;
			fdlibcppwrapper::CholeskyC * ptr4 = &test_obj4;
			//double a = 0.0L;
			//double b = 1.0L;
			for (auto i = 0; i != 2; ++i)
			{
				for (auto j = 0; j != 10; ++i)
				{
					test_obj1.operator()(ptr, ar_ptr_nd1[i], a += 0.1, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));

					fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj1);
					//test_obj1.operator*=(test_obj1).operator+=(test_obj1);
#if PRINT_DATA
					test_obj1.debug_print();
#endif
				}
			}

			for (auto i = 0; i != 5; ++i)
			{
				for (auto j = 0; j != 10; ++j)
				{
					test_obj2.operator()(ptr2, ar_ptr_nd2[i], a += 0.1, b += 0.1, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));
					fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj2);
#if PRINT_DATA
					test_obj2.debug_print();
#endif
				}
			}

			for (auto j = 0; j != 10; ++j)
			{
				test_obj3.operator()(ptr3, ar_ptr_pd1[0], a += 0.1, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(j));
				fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj3);
#if PRINT_DATA
				test_obj3.debug_print();
#endif
			}
				

			for (auto i = 0; i != 3; ++i)
			{
				for (auto j = 0; j != 10; ++j)
				{
					test_obj4.operator()(ptr4, ar_ptr_pd2[i], a += 0.1, b += 0.1, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(j));
					fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj4);
#if PRINT_DATA
					test_obj4.debug_print();
#endif
				}
			}
		};
		
		test_lambda3(2.5, 5.5);
}

void test::TestCholeskyC::Run_Ctor1_Tests()
{
	
		std::printf("Begining CholeskyC::CholeskyC(const int) Constructor Tests\n\n");
		test::TestCholeskyC::Test_Ctor();
		fdlibcppwrapper::CholeskyC test_obj = test::TestCholeskyC::Test_Ret_Ctor();
		std::printf("test_obj.debug_print()\n");
		test_obj.debug_print();
		fdlibcppwrapper::CholeskyC & test_obj2 = test::TestCholeskyC::Test_Ref_Ctor();
		std::printf("test_obj2.debug_print()\n");
		test_obj2.debug_print();
		fdlibcppwrapper::CholeskyC * test_obj3 = test::TestCholeskyC::Test_Ptr_Ctor();
		std::printf("test_obj3->debug_print()\n");
		test_obj3->debug_print();
		std::unique_ptr<fdlibcppwrapper::CholeskyC> test_ptr = test::TestCholeskyC::Test_SPtr_Ctor();
		std::printf("test_ptr.operator->()->debug_print()\n");
		test_ptr.operator->()->debug_print();
		std::function<fdlibcppwrapper::CholeskyC(const int)> test_functor = test::TestCholeskyC::Test_Lambda_Ctor();
		auto test_obj4 = test_functor(10);
		std::printf("test_functor(10)\n");
		test_obj4.debug_print();
		std::printf("Finished CholeskyC::CholeskyC(const int) Constructor Tests\n\n");
		std::printf("Calling CholeskyC::~CholeskyC() Destructors\n");
	
}

void  test::TestCholeskyC::Run_Ctor1_Funct_Tests()
{
	std::printf("Beginning series of functionality tests\n");
	fdlibcppwrapper::CholeskyC test_obj = test::TestCholeskyC::Test_Ret_Ctor();
	std::printf("Calling F77 CHOL_C subroutine on test_obj at address: %p\n", &test_obj );
	fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
	std::printf("Displaying results of fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj)\n\n");
	test_obj.debug_print();
	fdlibcppwrapper::CholeskyC & test_obj2 = test::TestCholeskyC::Test_Ref_Ctor();
	std::printf("Calling F77 CHOL_C subroutine on test_obj2 at address: %p\n", &test_obj2);
	fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj2);
	std::printf("Displaying results of fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj2)\n\n");
	test_obj2.debug_print();
	fdlibcppwrapper::CholeskyC * test_obj3 = test::TestCholeskyC::Test_Ptr_Ctor();
	std::printf("Calling F77 CHOL_C subroutine on test_obj3 at address: %p\n", test_obj3);
	fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*test_obj3);
	std::printf("Displaying results of fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj3)\n\n");
	test_obj3->debug_print();
	std::unique_ptr<fdlibcppwrapper::CholeskyC> test_ptr = test::TestCholeskyC::Test_SPtr_Ctor();
	std::printf("Calling F77 CHOL_C subroutine on test_obj \n");
	fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_ptr->get_m_l(), test_ptr->get_m_a(), test_ptr->get_m_N());
	std::printf("Displaying results of fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj3)\n\n");
	test_ptr->debug_print();
	std::function<fdlibcppwrapper::CholeskyC(const int)> test_functor = test::TestCholeskyC::Test_Lambda_Ctor();
	std::printf("Calling F77 CHOL_C subroutine on test_functor(const int)->test_obj \n");
	auto lambda = test_functor(10);
	fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(lambda);
	std::printf("Displaying results of fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(lambda)\n\n");
	lambda.debug_print();
	std::printf("Finished functionality tests\n");
}


void  test::TestCholeskyC::Run_Ctor1_Assert_Tests()
{
	std::printf("Beginning Assertion Tests\n\n");
	std::printf("Assert::Equal Tests\n\n");
	
	
	fdlibcppwrapper::CholeskyC actual = test::TestCholeskyC::Test_Ret_Ctor();
	fdlibcppwrapper::CholeskyC unexpected = test::TestCholeskyC::Test_Ret_Ctor();
	
	double * running_difference = new double[actual.get_m_N() * actual.get_m_N()];
	double * running_difference2 = new double[actual.get_m_N() * actual.get_m_N()];
	
	double result = 0.0L;
	double result2 = 0.0L;
	if (actual.get_m_N() == unexpected.get_m_N())
	{
		
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				if ((result = actual.get_m_a()[j * actual.get_m_N() + i] - unexpected.get_m_a()[j * actual.get_m_N() + i]) <=
					std::numeric_limits<double>::epsilon())
				{
					running_difference[j * actual.get_m_N() + i] = result;
					
#if PRINT_DATA
					std::printf("actual.get_m_a()[%d * %d + %d] = %.15f |  unexpected.get_m_a()[%d * %d + %d] = %.15f\n",j,actual.get_m_N(),i,actual.get_m_a()[j * actual.get_m_N() + i],
						j, unexpected.get_m_N(), i, unexpected.get_m_a()[j * unexpected.get_m_N() + i]);
					std::printf("Equality Test of a(10,10):%s, at index j=%d, index i=%d, value=%.15f\n",test::Assertion_Succeded,j,i,running_difference[j * actual.get_m_N() + i]);
					std::printf("-----------------------------------------------------------------------------\n");
#endif
				}
				else
				{
					running_difference[j * actual.get_m_N() + i] = result;
					
					std::printf("actual.get_m_a()[%d * %d + %d] = %.15f |  unexpected.get_m_a()[%d * %d + %d] = %.15f\n", j, actual.get_m_N(), i, actual.get_m_a()[j * actual.get_m_N() + i],
						j, unexpected.get_m_N(), i, unexpected.get_m_a()[j * unexpected.get_m_N() + i]);
					std::printf("Equality Test of a(10,10):%s, at index j=%d, index i=%d, value=%.15f\n", test::Assertion_Failed, j, i, running_difference[j * actual.get_m_N() + i]);
					std::printf("-----------------------------------------------------------------------------\n");
				}
				
			}
		}

		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(actual);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(unexpected);
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				if ((result2 = actual.get_m_l()[j * actual.get_m_N() + i] - unexpected.get_m_l()[j * actual.get_m_N() + i]) <=
					std::numeric_limits<double>::epsilon())
				{
					running_difference2[j * actual.get_m_N() + i] = result2;
					
#if PRINT_DATA
					//std::printf("EQUALITY:difference=%.15f\n", result2);
					std::printf("actual.get_m_l()[%d * %d + %d]=%.15f |  unexpected.get_m_l()[%d * %d + %d]=%.15f\n",j,actual.get_m_N(),i,actual.get_m_l()[j * actual.get_m_N() + i],
						j, unexpected.get_m_N(), i, unexpected.get_m_l()[j * unexpected.get_m_N() + i]);
					std::printf("Equality Test of l(10,10):%s, at index j=%d, index i=%d, value=%.15f\n", test::Assertion_Succeded, j, i, running_difference2[j * actual.get_m_N() + i]);
					std::printf("----------------------------------------------------------------------\n");
					
#endif
				}
				else
				{
				
					running_difference2[j * actual.get_m_N() + i] = result2;
#if PRINT_DATA
					//std::printf("INEQUALITY:difference=%.15f\n", result2);
					std::printf("NOT_EQUAL_VALUES: actual.get_l()[%d * %d + %d]=%.15f | unexpected.get_m_l()[%d * %d + %d]=%.15f\n", j, actual.get_m_N(), i, actual.get_m_l()[j * actual.get_m_N() + i],
						j, unexpected.get_m_N(), i, unexpected.get_m_l()[j * unexpected.get_m_N() + i]);
					std::printf("Equality Test of l(10,10):%s, at index j=%d, index i=%d, value=%.15f\n", test::Assertion_Failed, j, i, running_difference2[j * actual.get_m_N() + i]);
					std::printf("----------------------------------------------------------------------\n");
					
#endif
					
				}
			}
		}
	}
	delete[] running_difference;
	
	delete[] running_difference2;
	
}
// class private functions implementation.

void  test::TestCholeskyC::AssertEqual( fdlibcppwrapper::CholeskyC& actual,  fdlibcppwrapper::CholeskyC& expect,  std::vector<std::pair<double,double>>& vec_eq_vals,
	std::vector<std::pair<double,double>>& vec_eq_vals2, const double eps, const char *msg, const char *msg2)
{
	std::printf("AssertEqual Test\n");
	
	if (actual.get_m_N() == expect.get_m_N())
	{
		std::printf("Equality Test of arrays a\n");
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(actual);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(expect);
		//double difference = 0.0L;
		std::pair<double, double> equal_vals; std::pair<double, double> equal_vals2;
		std::printf("test_obj: actual     ||            test_obj: expected\n\n"   );
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				//Variable precision epsilon
				if ((std::fabs( actual.get_m_a()[j * actual.get_m_N() + i] - expect.get_m_a()[j * actual.get_m_N() + i])) <= eps)
				{
					equal_vals.first = actual.get_m_a()[j * actual.get_m_N() + i];
					equal_vals.second = expect.get_m_a()[j * actual.get_m_N() + i];
					vec_eq_vals.push_back(equal_vals);
#if PRINT_DATA
					std::printf("a(%d,%d)=%.15f  ||  a(%d,%d)=%.15f\n", j,i, actual.get_m_a()[j * actual.get_m_N() + i],
						j,i,expect.get_m_a()[j * expect.get_m_N() + i]);
					std::printf("Equal Values of a(10,10):%s, at index j=%d, index i=%d, \n", msg, j, i);
					std::printf("------------------------------------------------------------------------------\n");
#endif
				}
				else
				{
					equal_vals.first = actual.get_m_a()[j * actual.get_m_N() + i];
					equal_vals.second = expect.get_m_a()[j * actual.get_m_N() + i];
					vec_eq_vals.push_back(equal_vals);
#if PRINT_DATA
					std::printf("a(%d,%d)=%.15f ||  a(%d,%d)=%.15f\n", j, i, actual.get_m_a()[j * actual.get_m_N() + i],
						j,i, expect.get_m_a()[j * expect.get_m_N() + i]);
					std::printf("InEqual Values of a(10,10):%s, at index j=%d, index i=%d\n", msg2, j, i);
					std::printf("------------------------------------------------------------------------------\n");
#endif
				}
			}
		}
		std::printf("Equality Test of arrays l \n");
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				if ((std::fabs(actual.get_m_l()[j * actual.get_m_N() + i] - expect.get_m_l()[j * actual.get_m_N() + i])) <= eps)
				{
					equal_vals2.first = actual.get_m_l()[j * actual.get_m_N() + i];
					equal_vals2.second = expect.get_m_l()[j * actual.get_m_N() + i];
					vec_eq_vals2.push_back(equal_vals2);
#if PRINT_DATA
					std::printf("l(%d,%d)=%.15f ||  l(%d,%d)=%.15f\n", j, i, actual.get_m_l()[j * actual.get_m_N() + i],
						j, i, expect.get_m_l()[j * expect.get_m_N() + i]);
					std::printf("Equal Values of l(10,10):%s, at index j=%d, index i=%d, \n", msg, j, i);
					std::printf("------------------------------------------------------------------------------\n");
#endif
				}
				else
				{
					equal_vals2.first = actual.get_m_l()[j * actual.get_m_N() + i];
					equal_vals2.second = expect.get_m_l()[j * actual.get_m_N() + i];
					vec_eq_vals2.push_back(equal_vals2);
					std::printf("l(%d,%d)=%.15f ||  l(%d,%d)=%.15f\n", j, i, actual.get_m_l()[j * actual.get_m_N() + i],
						j, i, expect.get_m_l()[j * expect.get_m_N() + i]);
					std::printf("InEqual Values of l(10,10):%s, at index j=%d, index i=%d\n", msg2, j, i);
					std::printf("------------------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		std::printf("Length of arguments does not match: %d\n", actual.get_m_N() - expect.get_m_N());
		return;
	}
}

void  test::TestCholeskyC::AssertNotEqual(fdlibcppwrapper::CholeskyC & actual, fdlibcppwrapper::CholeskyC & unexpect, std::vector<std::pair<double, double>>& vec1,
	std::vector<std::pair<double, double>>& vec2, const double eps, const char *msg1, const char *msg2)
{
	std::printf("AssertNotEqual Tests\n");
	if (actual.get_m_N() == unexpect.get_m_N())
	{
		std::printf("InEquality Test of array a\n");
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(actual);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(unexpect);
		std::pair<double, double> equal_vals; std::pair<double, double> equal_vals2;
		std::printf("test_obj: actual     ||            test_obj: unexpected\n\n");
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				if ((std::fabs(actual.get_m_a()[j * actual.get_m_N() + i] - unexpect.get_m_a()[j * unexpect.get_m_N() + i])) > eps)
				{
					equal_vals.first = actual.get_m_a()[j * actual.get_m_N() + i];
					equal_vals.second = unexpect.get_m_a()[j * unexpect.get_m_N() + i];
					vec1.push_back(equal_vals);
#if defined PRINT_DATA
					std::printf(" a(%d,%d)=%.15f     ||        a(%d,%d)=%.15f\n", j, i, actual.get_m_a()[j * actual.get_m_N() + i], j, i,
						unexpect.get_m_a()[j * unexpect.get_m_N() + i]);
					std::printf("InEqual Values of a(10,10):%s, at index j=%d, index i=%d\n", msg1, j, i);
					std::printf("-----------------------------------------------------------------------\n");
#endif
				}
				else
				{
					equal_vals.first = actual.get_m_a()[j * actual.get_m_N() + i];
					equal_vals.second = unexpect.get_m_a()[j * unexpect.get_m_N() + i];
					vec1.push_back(equal_vals);
#if defined PRINT_DATA
					std::printf(" a(%d,%d)=%.15f     ||        a(%d,%d)=%.15f\n", j, i, actual.get_m_a()[j * actual.get_m_N() + i], j, i,
						unexpect.get_m_a()[j * unexpect.get_m_N() + i]);
					std::printf("Equal Values of a(10,10):%s, at index j=%d, index i=%d\n", msg2, j, i);
					std::printf("------------------------------------------------------------------------\n");
#endif
				}
			}
		}
		std::printf("InEquality test of an array l\n");
		for (auto i = 0; i != actual.get_m_N(); ++i)
		{
			for (auto j = 0; j != actual.get_m_N(); ++j)
			{
				if ((std::fabs(actual.get_m_l()[j * actual.get_m_N() + i] - unexpect.get_m_l()[j * unexpect.get_m_N() + i])) > eps)
				{
					equal_vals2.first = actual.get_m_l()[j * actual.get_m_N() + i];
					equal_vals2.second = unexpect.get_m_l()[j * unexpect.get_m_N() + i];
					vec2.push_back(equal_vals2);
#if PRINT_DATA
					std::printf(" l(%d,%d)=%.15f     ||        l(%d,%d)=%.15f\n", j, i, actual.get_m_l()[j * actual.get_m_N() + i], j, i,
						unexpect.get_m_l()[j * unexpect.get_m_N() + i]);
					std::printf("InEqual Values of l(10,10):%s, at index j=%d, index i=%d\n", msg1, j, i);
					std::printf("-----------------------------------------------------------------------\n");
#endif

				}
				else
				{
					equal_vals2.first = actual.get_m_l()[j * actual.get_m_N() + i];
					equal_vals2.second = unexpect.get_m_l()[j * unexpect.get_m_N() + i];
					vec2.push_back(equal_vals2);
					std::printf(" l(%d,%d)=%.15f     ||        l(%d,%d)=%.15f\n", j, i, actual.get_m_l()[j * actual.get_m_N() + i], j, i,
						unexpect.get_m_l()[j * unexpect.get_m_N() + i]);
					std::printf("Equal Values of l(10,10):%s, at index j=%d, index i=%d\n", msg2, j, i);
					std::printf("------------------------------------------------------------------------\n");
				}
			}
		}
	}
	else
	{
		std::printf("Length of arguments does not match: %d\n", actual.get_m_N() - unexpect.get_m_N());
		return;
	}
}


void   test::TestCholeskyC::Run_Ctor1_Ref_Assert_Tests()
{
	
	
	fdlibcppwrapper::CholeskyC & actual = test::TestCholeskyC::Test_Ref_Ctor();
	fdlibcppwrapper::CholeskyC & expect = test::TestCholeskyC::Test_Ref_Ctor();
	if (actual.get_m_N() == expect.get_m_N())
	{
		const char *msg = "EQUAL_VALUES_FOUND";
		const char *msg2 = "UNEQUAL_VALUES_FOUND";
		std::printf("Beginning Assertion Tests of references to CholeskyC objects\n\n");
		std::vector<std::pair<double, double>>   v1(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>   v2(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>   v3(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>   v4(actual.get_m_N() * actual.get_m_N());
		const double EPS = std::numeric_limits<double>::epsilon();
		std::printf("EQUALITY TEST\n\n");
		test::TestCholeskyC::AssertEqual(actual, expect, v1, v2, EPS, msg, msg2);
		std::printf("INEQUALITY TEST\n\n");
		test::TestCholeskyC::AssertNotEqual(actual, expect, v3, v4, EPS, msg, msg2);
		std::printf("Finished Assertion Tests of references to CholeskyC objects\n\n");
		delete msg; delete msg2;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR: Inequal test_object length arguments\n"));
	}
}

void  test::TestCholeskyC::Run_Ctor1_Ptr_Assert_Tests()
{
	
	fdlibcppwrapper::CholeskyC * actual = test::TestCholeskyC::Test_Ptr_Ctor();
	fdlibcppwrapper::CholeskyC * expect = test::TestCholeskyC::Test_Ptr_Ctor();
	if (actual->get_m_N() == expect->get_m_N())
	{
		const char *msg = "EQUAL_VALUES_FOUND";
		const char *msg2 = "UNEQUAL_VALUES_FOUND";
		std::printf("Beginning Assertion Tests of pointers to CholeskyC objects\n\n");
		std::vector<std::pair<double, double>>    v1(actual->get_m_N() * actual->get_m_N());
		std::vector<std::pair<double, double>>    v2(actual->get_m_N() * actual->get_m_N());
		std::vector<std::pair<double, double>>    v3(actual->get_m_N() * actual->get_m_N());
		std::vector<std::pair<double, double>>    v4(actual->get_m_N() * actual->get_m_N());
		const double EPS = std::numeric_limits<double>::epsilon();
		std::printf("EQUALITY TEST\n\n");
		test::TestCholeskyC::AssertEqual(*actual, *expect, v1, v2, EPS, msg, msg2);
		std::printf("INEQUALITY TEST\n\n");
		test::TestCholeskyC::AssertNotEqual(*actual, *expect, v3, v4, EPS, msg, msg2);
		std::printf("Finished Assertion Tests of pointers to CholeskyC objects\n\n");
		delete msg; delete msg2;
		delete actual; delete expect;
	}
	else
	{
		delete actual; delete expect;
		throw std::runtime_error(std::string("FATAL ERROR: Inequal test_object length arguments\n"));
	}
}

void   test::TestCholeskyC::Run_Ctor1_SPtr_Assert_Tests()
{
	std::unique_ptr<fdlibcppwrapper::CholeskyC> uptr1 = test::TestCholeskyC::Test_SPtr_Ctor();
	std::unique_ptr<fdlibcppwrapper::CholeskyC> uptr2 = test::TestCholeskyC::Test_SPtr_Ctor();
	if (uptr1.operator->()->get_m_N() == uptr2.operator->()->get_m_N())
	{
		const char *msg = "EQUAL_VALUES_FOUND";
		const char *msg2 = "UNEQUAL_VALUES_FOUND";
		std::printf("Beginning Assertion Tests of smart pointers to CholeskyC objects\n");
		std::vector<std::pair<double, double>>  v1(uptr1.operator->()->get_m_N() * uptr1.operator->()->get_m_N());
		std::vector<std::pair<double, double>>   v2(uptr1.operator->()->get_m_N() * uptr1.operator->()->get_m_N());
		std::vector<std::pair<double, double>>   v3(uptr1.operator->()->get_m_N() * uptr1.operator->()->get_m_N());
		std::vector<std::pair<double, double>>    v4(uptr1.operator->()->get_m_N() * uptr1.operator->()->get_m_N());
		const double EPS = std::numeric_limits<double>::epsilon();
		std::printf("EQUALITY TEST\n\n");
		test::TestCholeskyC::AssertEqual(*uptr1, *uptr2, v1, v2, EPS, msg, msg2);
		std::printf("INEQUALITY TEST\n\n");
		test::TestCholeskyC::AssertNotEqual(*uptr1, *uptr2, v3, v4, EPS, msg, msg2);
		std::printf("Finished Assertion Tests of smart pointers to CholeskyC objects\n\n");
		delete msg; delete msg2;

	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR: Inequal test_object length arguments\n"));
	}
}

void   test::TestCholeskyC::Run_Ctor1_Lambda_Assert_Tests()
{
	std::function<fdlibcppwrapper::CholeskyC(const int)> functor = test::TestCholeskyC::Test_Lambda_Ctor();
	std::function<fdlibcppwrapper::CholeskyC(const int)> functor2 = test::TestCholeskyC::Test_Lambda_Ctor();
	if (functor(10).get_m_N() == functor2(10).get_m_N())
	{
		const char *msg = "EQUAL_VALUES_FOUND";
		const char *msg2 = "UNEQUAL_VALUES_FOUND";
		std::printf("Beginning Assertion Tests of lambda functors returning CholeskyC objects\n");
		std::vector<std::pair<double, double>>   v1(functor(10).get_m_N() * functor(10).get_m_N());
		std::vector<std::pair<double, double>>    v2(functor(10).get_m_N() * functor(10).get_m_N());
		std::vector<std::pair<double, double>>    v3(functor(10).get_m_N() * functor(10).get_m_N());
		std::vector<std::pair<double, double>>     v4(functor(10).get_m_N() * functor(10).get_m_N());
		const double EPS = std::numeric_limits<double>::epsilon();
		std::printf("EQUALITY TEST\n\n");
		test::TestCholeskyC::AssertEqual(functor(10), functor2(10), v1, v2, EPS, msg, msg2);
		std::printf("INEQUALITY TEST\n\n");
		test::TestCholeskyC::AssertNotEqual(functor(10), functor2(10), v3, v4, EPS, msg, msg2);
		std::printf("Finished Assertion Tests of lambda functors returning CholeskyC objects\n\n");
		delete msg; delete msg2;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR: Inequal test_object length arguments\n"));
	}
}

void   test::TestCholeskyC::Run_Ctor1_EPS_Accuracy_Tests()
{
	fdlibcppwrapper::CholeskyC actual = test::TestCholeskyC::Test_Ret_Ctor();
	fdlibcppwrapper::CholeskyC expect = test::TestCholeskyC::Test_Ret_Ctor();
	if (actual.get_m_N() == expect.get_m_N())
	{
		const char *msg = "EQUAL_VALUES_FOUND";
		const char *msg2 = "UNEQUAL_VALUES_FOUND";
		std::printf("Beginning Sliding Value of Epsilon Accuracy Test\n");
		double eps = 1.0e-12L;
		const double tenth = (0.1L);
		const double one = (1.0L);
		std::vector<std::pair<double, double>>  v1(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>  v2(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>  v3(actual.get_m_N() * actual.get_m_N());
		std::vector<std::pair<double, double>>   v4(actual.get_m_N() * actual.get_m_N());
		
		while ((eps /= tenth) < one)
		{
			std::printf("EQUALITY TEST - SLIDING WINDOW EPSILON\n\n");
			test::TestCholeskyC::AssertEqual(actual, expect, v1, v2, eps, msg, msg2);
			std::printf("INEQUALITY TEST- SLIDING WINDOW EPSILON\n\n");
			test::TestCholeskyC::AssertNotEqual(actual, expect, v3, v4, eps, msg, msg2);
		}
		std::printf("Finished Sliding Value of Epsilon Accuracy Test\n");
		delete msg; delete msg2;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR: Inequal test_object length arguments\n"));
	}
}
// Return lambda object which contains CholeskyC object with "default" initialization.
std::function<fdlibcppwrapper::CholeskyC()> test::TestCholeskyC::Ret_Lambda_UnInit()
{
	std::function<fdlibcppwrapper::CholeskyC()> functor = []()->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized by the call to uniform real distribution wrapper.
std::function<fdlibcppwrapper::CholeskyC()> test::TestCholeskyC::Ret_Lambda_Init()
{
	std::function<fdlibcppwrapper::CholeskyC()> functor = []()->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		test_obj.uni_real_distr_fill(0.0, 1.0, 0);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized with the results of F77 CHOL_C call.
std::function<fdlibcppwrapper::CholeskyC()> test::TestCholeskyC::Ret_Lambda_Chol_c()
{
	std::function<fdlibcppwrapper::CholeskyC()> functor = []()->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		test_obj.uni_real_distr_fill(0.0, 1.0, 0);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object which was initialized by the call to HW RDRAND wrapper.
std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> test::TestCholeskyC::Ret_Lambda_Init(const int n, REAL lo, REAL hi)
{
	std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> functor = [](const int n, REAL lo, REAL hi)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n,lo,hi);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized with the results of F77 CHOL_C call.
std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> test::TestCholeskyC::Ret_Lambda_Chol_c(const int n, REAL lo, REAL hi)
{
	std::function<fdlibcppwrapper::CholeskyC(const int, REAL, REAL)> functor = [](const int n, REAL lo, REAL hi)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(n, lo, hi);
		test_obj.uni_real_distr_fill(0.0, 1.0, 0.0);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized by the std::vector<REAL> &.
std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> test::TestCholeskyC::Ret_Lambda_Init(std::vector<REAL> &rhs)
{
	std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> functor = [](std::vector<REAL> &rhs)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(rhs);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized with the results of F77 CHOL_C call.
std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> test::TestCholeskyC::Ret_Lambda_Chol_c(std::vector<REAL> &rhs)
{
	std::function<fdlibcppwrapper::CholeskyC(std::vector<REAL>&)> functor = [](std::vector<REAL> &rhs)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(rhs);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized by the CholeskyC Copy-Ctor.
std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC&)> test::TestCholeskyC::Ret_Lambda_Init(const fdlibcppwrapper::CholeskyC &cholesky)
{
	std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC &)> functor = [](const fdlibcppwrapper::CholeskyC &cholesky)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(cholesky);
		return test_obj;
	};
	return functor;
}

// Return lambda object which contains CholeskyC object initialized with the results of F77 CHOL_C call.
std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC &)> test::TestCholeskyC::Ret_Lambda_Chol_c(const fdlibcppwrapper::CholeskyC &cholesky)
{
	std::function<fdlibcppwrapper::CholeskyC(const fdlibcppwrapper::CholeskyC &)> functor = [](const fdlibcppwrapper::CholeskyC &cholesky)->fdlibcppwrapper::CholeskyC
	{
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(cholesky);
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(test_obj);
		return test_obj;
	};

	return functor;
}

// Return lambda object which contains std::vector of pointers to CholeskyC objects which were initialized by the call to HW RDRAND wrapper.
std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int,const int, REAL, REAL)> test::TestCholeskyC::Ret_Lambda_Vec_Init(const int n,const int m, REAL lo, REAL hi)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int, const int, REAL, REAL)> functor = [](const int n, const int m, REAL lo, REAL hi)->std::vector < fdlibcppwrapper::CholeskyC *> 
	{
		//std::vector<fdlibcppwrapper::CholeskyC *>::iterator iter;
		std::vector<fdlibcppwrapper::CholeskyC *> vec(m);
		for (auto i = 0; i != vec.size(); ++i)
		{
			vec.push_back(new fdlibcppwrapper::CholeskyC(n, lo, hi));
		}
		//for (iter = vec.begin(); iter != vec.end(); ++iter)
			//(*iter.operator->())->
		return vec;
	};

	
	return functor;
}

// Return lambda object which contains std::vector of pointers to CholeskyC objects initialized with the results of F77 CHOL_C call.
std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int, const int, REAL, REAL)> test::TestCholeskyC::Ret_Lambda_Vec_Chol_c(const int n, const int m, REAL lo, REAL hi)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int, const int, REAL, REAL)> functor = [](const int n, const int m, REAL lo, REAL hi)->std::vector<fdlibcppwrapper::CholeskyC*>
	{
		std::vector<fdlibcppwrapper::CholeskyC *> vec(m);
		for (auto i = 0; i != vec.size(); ++i)
		{
			vec.push_back(new fdlibcppwrapper::CholeskyC(n, lo, hi));
		}
		for (auto i = 0; i != vec.size(); ++i)
		{
			fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*vec[i]);
		}
		return vec;
	};
	return functor;
}

// Return lambda object which contains std::vector of pointers to CholeskyC objects which were initialized by the call to uniform real distribution wrapper.
std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> test::TestCholeskyC::Ret_Lambda_Vec_Init(const int m)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> functor = [](const int m)->std::vector<fdlibcppwrapper::CholeskyC *>
	{
		std::vector<fdlibcppwrapper::CholeskyC *> vec(m);
		for (auto i = 0; i != vec.size(); ++i) vec.push_back(new fdlibcppwrapper::CholeskyC(10));
		
		for (auto i = 0; i != vec.size(); ++i) vec[i]->uni_real_distr_fill(0.0, 1.0, 0);
		
		return vec;
	};
	return functor;
}

std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> test::TestCholeskyC::Ret_Lambda_Vec_Chol_c(const int m)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC *>(const int)> functor = [](const int m)->std::vector<fdlibcppwrapper::CholeskyC *>
	{
		std::vector<fdlibcppwrapper::CholeskyC *> vec(m);
		std::vector<fdlibcppwrapper::CholeskyC *>::iterator iter,iter2;
		for (auto i = 0; i != vec.size(); ++i) vec.push_back(new fdlibcppwrapper::CholeskyC(10));

		for (iter = vec.begin(); iter != vec.end(); ++iter) (*iter.operator->())->uni_real_distr_fill(0.0, 1.0, 0);

		for (iter2 = vec.begin(); iter2 != vec.end(); ++iter2) fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*(*iter2));

		return vec;
	};
	
	return functor;
}

std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_ND1(const double a)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> functor = [](const int b)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_ND1 ar_ptr_nd1[2];
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		ar_ptr_nd1[0] = &fdlibcppwrapper::CholeskyC::student_distr_fill;
		ar_ptr_nd1[1] = &fdlibcppwrapper::CholeskyC::chisquared_distr_fill;
		const auto length = 18U; const auto num_of_funcs = 2U; const auto num_of_engines = 10U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_funcs; ++i)
		{
			for (auto j = 0; j != num_of_engines; ++j)
			{
				fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_nd1[i], b, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;
	};
	return functor;

}

std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_ND1_Chol_c(const double a)
{
	
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> functor = [](const double a)->std::vector < fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_ND1 ar_ptr_nd1[2];
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		ar_ptr_nd1[0] = &fdlibcppwrapper::CholeskyC::student_distr_fill;
		ar_ptr_nd1[1] = &fdlibcppwrapper::CholeskyC::chisquared_distr_fill;
		const auto length = 18U; const auto num_of_funcs = 2U; const auto num_of_engines = 10U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_funcs; ++i)
		{
			for (auto j = 0; j != num_of_engines; ++j)
			{
				fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_nd1[i], a, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));
				fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(temp);
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;
	};
	return functor;
}

std::function< std::vector< fdlibcppwrapper::CholeskyC>(const double, const double)>  test::TestCholeskyC::Ret_Lambda_Vec_PTR_ND2(const double a, const double b)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> functor = [](const double a, const double b)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_ND2 ar_ptr_nd2[4];
		ar_ptr_nd2[0] = &fdlibcppwrapper::CholeskyC::cauchy_distr_fill;
		ar_ptr_nd2[1] = &fdlibcppwrapper::CholeskyC::fisher_distr_fill;
		ar_ptr_nd2[2] = &fdlibcppwrapper::CholeskyC::norm_distr_fill;
		ar_ptr_nd2[3] = &fdlibcppwrapper::CholeskyC::lognorm_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_func = 4U; const auto num_of_eng = 10U; const auto length = 36U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length, fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_func; ++i)
		{
			for (auto j = 0; j != num_of_eng; ++j)
			{
				fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_nd2[i], a, b, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;

	};
	return functor;
}


std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_ND2_Chol_c(const double a, const double b)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> functor = [](const double a, const double b)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_ND2 ar_ptr_nd2[4];
		ar_ptr_nd2[0] = &fdlibcppwrapper::CholeskyC::cauchy_distr_fill;
		ar_ptr_nd2[1] = &fdlibcppwrapper::CholeskyC::fisher_distr_fill;
		ar_ptr_nd2[2] = &fdlibcppwrapper::CholeskyC::norm_distr_fill;
		ar_ptr_nd2[3] = &fdlibcppwrapper::CholeskyC::lognorm_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_func = 4U; const auto num_of_eng = 10U; const auto length = 36U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_func; ++i)
		{
			for (auto j = 0; j != num_of_eng; ++j)
			{
				fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_nd2[i], a, b, static_cast<fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines>(j));
				fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(temp);
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;
	};
	return functor;
}

std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_PD1(const double a)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> functor = [](const double a)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_PD1 ar_ptr_pd1[1];
		ar_ptr_pd1[0] = &fdlibcppwrapper::CholeskyC::exp_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_eng = 10U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(num_of_eng,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_eng; ++i)
		{
			fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_pd1[0], a, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(i));
			vec.push_back(temp);
		}
		delete ptr;
		return vec;
	};
	return functor;
}

std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_PD1_Chol_c(const double a)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double)> functor = [](const double a)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_PD1 ar_ptr_pd1[1];
		ar_ptr_pd1[0] = &fdlibcppwrapper::CholeskyC::exp_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_eng = 10U;
		std::vector<fdlibcppwrapper::CholeskyC> vec(num_of_eng,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_eng; ++i)
		{
			fdlibcppwrapper::CholeskyC temp = test_obj.operator()(ptr, ar_ptr_pd1[0], a, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(i));
			fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(temp);
			vec.push_back(temp);
		}
		delete ptr;
		return vec;
	};
	return functor;
}


std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_PD2(const double a, const double b)
{
	std::function <std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> functor = [](const double a, const double b)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_PD2 ar_ptr_pd2[3];
		ar_ptr_pd2[0] = &fdlibcppwrapper::CholeskyC::extr_val_distr_fill;
		ar_ptr_pd2[1] = &fdlibcppwrapper::CholeskyC::gamma_distr_fill;
		ar_ptr_pd2[2] = &fdlibcppwrapper::CholeskyC::weibull_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_eng = 10;
		const auto num_of_func = 3;
		const auto length = 27;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_func; ++i)
		{
			for (auto j = 0; j != num_of_eng; ++j)
			{
				auto temp = test_obj.operator()(ptr, ar_ptr_pd2[i], a, b, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(j));
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;
	};
	return functor;
}


std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> test::TestCholeskyC::Ret_Lambda_Vec_PTR_PD2_Chol_c(const double a, const double b)
{
	std::function<std::vector<fdlibcppwrapper::CholeskyC>(const double, const double)> functor = [](const double a, const double b)->std::vector<fdlibcppwrapper::CholeskyC>
	{
		fdlibcppwrapper::CholeskyC::PTR_PD2 ar_ptr_pd2[3];
		ar_ptr_pd2[0] = &fdlibcppwrapper::CholeskyC::extr_val_distr_fill;
		ar_ptr_pd2[1] = &fdlibcppwrapper::CholeskyC::gamma_distr_fill;
		ar_ptr_pd2[2] = &fdlibcppwrapper::CholeskyC::weibull_distr_fill;
		fdlibcppwrapper::CholeskyC test_obj = fdlibcppwrapper::CholeskyC(10);
		fdlibcppwrapper::CholeskyC * ptr = &test_obj;
		const auto num_of_eng = 10;
		const auto num_of_func = 3;
		const auto length = 27;
		std::vector<fdlibcppwrapper::CholeskyC> vec(length,fdlibcppwrapper::CholeskyC());
		for (auto i = 0; i != num_of_func; ++i)
		{
			for (auto j = 0; j != num_of_eng; ++j)
			{
				auto temp = test_obj.operator()(ptr, ar_ptr_pd2[i], a, b, static_cast<fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines>(j));
				fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(temp);
				vec.push_back(temp);
			}
		}
		delete ptr;
		return vec;
	};
	return functor;
}