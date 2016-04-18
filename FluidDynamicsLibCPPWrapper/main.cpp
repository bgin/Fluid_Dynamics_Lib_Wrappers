
#include "lin_alg.h"
#include "lin_alg_chol_r.h"
#include "StatDistributionWrapper.h"
#include <math.h>
using namespace fdlibcppwrapper;

int main()
{

	CholeskyC test_obj1 = CholeskyC(10, 1.0, 10.0);
	
	CholeskyCWrapper::fdlib_chol_c(test_obj1);
	//test_obj1.debug_print();
	//CholeskyR test_bj3 = CholeskyR(10);
	//test_bj3.operator()(test_bj3);
	CholeskyR test_obj2 = CholeskyR(10, 1.0, 10.0);
	CholeskyRWrapper::fdlib_chol_r(test_obj2);
	test_obj2.debug_print();
	CholeskyR test_obj3 = CholeskyR(10);
	CholeskyR * pmp = &test_obj3;
	CholeskyR::Ptr_to_func pmf = &CholeskyR::student_distr_fill;
	//CholeskyR::Ptr_to_func ar_ptrs[3];
	
	test_obj3.operator()(pmp, pmf, 5.5, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines::KNUTH_B);
	CholeskyRWrapper::fdlib_chol_r(test_obj3);
	test_obj3.debug_print();
	CholeskyR test_obj4 = CholeskyR(10);
	CholeskyR * pmp2 = &test_obj4;
	CholeskyR::Ptr_to_func4 pmf4 = &CholeskyR::extr_val_distr_fill;
	test_obj4.operator()(pmp2, pmf4, 6.8,10.8, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines::KNUTH_B);
	std::cout << "test_obj4" << std::endl;
	test_obj4.debug_print();
	CholeskyR test_obj5 = test_obj3.operator+=(test_obj4);
	std::cout << "test_obj5.debug_print() called\n";
	test_obj5.debug_print();
	/*auto lambda1 = [](FDLIB_INT n, const double m, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)->std::unique_ptr<CholeskyR>{
		std::vector<REAL> vec(n);
		fdlibcppwrapper::exp_dist_fill(vec, m, engine);
		CholeskyR* ret =  new CholeskyR(vec);
		std::unique_ptr<CholeskyR> ret_ptr(ret);
		return ret_ptr;
		
	};*/
	
	//std::unique_ptr<CholeskyR> ret_ptr = CholeskyR::apply3(lambda1(10, 2.5, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines::KNUTH_B));
	// Typical lambda functor.
	auto lambda2 = [](FDLIB_INT n)->std::unique_ptr<CholeskyR>{
		CholeskyR * ptr_to_choleskyr = new CholeskyR(n);
		CholeskyR::Ptr_to_func4 pmf4 = &CholeskyR::extr_val_distr_fill;
		ptr_to_choleskyr->operator()(ptr_to_choleskyr, pmf4, 6.8, 10.5, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines::KNUTH_B);
		std::unique_ptr<CholeskyR> up(ptr_to_choleskyr);
		return up;
	};
	std::unique_ptr<CholeskyR> ret_ptr = CholeskyR::apply3(lambda2(10));
	
	// Proper WAY OF USING LAMBDA Function.
	std::unique_ptr<CholeskyR> ret_ptr2 = apply2([&](CholeskyR)->std::unique_ptr<CholeskyR>{ 
		
		std::vector<REAL> v(100);
		//fdlibcppwrapper::exp_dist_fill(temp->get_m_a(), 5.0, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines::KNUTH_B);
		for (int i = 0; i != test_obj4.get_m_N(); ++i)
		{
			for (int j = 0; j != test_obj4.get_m_N(); ++j)
			{
				v[j * test_obj4.get_m_N() + i] = test_obj4.get_m_a()[j * test_obj4.get_m_N() + i];
				//std::printf("v[] = %2.15f\n",v[j * test_obj4.get_m_N() + i]);
			}
		}
		CholeskyR * temp = new CholeskyR(v);
		std::unique_ptr<CholeskyR> sp(temp);
		return sp; }, test_obj4);
		std::printf("%.15f\n",ret_ptr2.get()->get_m_a()[25]);
	                                                                     
	//std::printf("%.15f\n",ret_ptr.operator->()->get_m_l()[25]);
	
	//Test enum class.
	BernoulliDistributionImpl<unsigned int>::test22(BernoulliDistributionImpl<unsigned int>::RanNumGenerators::KNUTH_B);
	// End of Test call.
	std::vector<unsigned int> rand_vec(100), rand_vec2(100); std::vector<double> rand_vec3(100);
	size_t seed = 0xFFFFFFFF;
	unsigned int status = _rdrand32_step(&seed);
	unsigned int minval = 10; unsigned int maxval = 65553;
	const int choose = 3;
	std::uniform_int_distribution<unsigned int> uid(10,20);
	std::knuth_b ke;
	UniformDistributions<std::uniform_int_distribution<unsigned int>,std::knuth_b,unsigned int>::uni_int_distribution(rand_vec, uid, ke);
	UniDistributions<unsigned int>::uni_int_distribution(rand_vec2, minval, maxval, seed, 3);
	for (auto i = 0; i != rand_vec.size(); ++i)
		std::cout << rand_vec2[i] << std::endl;

	UniDistributions<double>::uni_real_distribution(rand_vec3, 1.0, 10.0, seed, 1);
	std::cout << "uniform_real_distribution\n" << std::endl;
	for (auto i = 0; i != rand_vec3.size(); ++i)
		std::cout << rand_vec3[i] << std::endl;

	std::cout << "Testing operator()()" << std::endl;
	//test_obj3.debug_print();
	//CholeskyRWrapper::fdlib_chol_r(test_obj3);
	std::cout << "test_object4" << std::endl;
	test_obj4.debug_print();
	getchar();
	return 0;
}