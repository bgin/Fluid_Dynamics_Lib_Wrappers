#include "lin_alg_chol_r.h"
#include <numeric>

fdlibcppwrapper::CholeskyR::CholeskyR(const int n)
{
#if defined _DEBUG
	std::printf("CholeskyR::CholeskyR(const int %d) - executed at address: 0x%x, on LOC: %d\n", n, __FUNCTIONW__, __LINE__);
#endif
	init_vector(n);
}

fdlibcppwrapper::CholeskyR::CholeskyR(const int n, REAL lo_bound, REAL up_bound) 
{
#if defined _DEBUG
	std::printf("CholeskyR::CholeskyR(const int %d,REAL %.15f,REAL %.15f) - executed at address: 0x%x, on LOC: %d\n",n,lo_bound,up_bound, __FUNCTIONW__, __LINE__);
#endif
	init_vector(n, lo_bound, up_bound);
}

fdlibcppwrapper::CholeskyR::CholeskyR(const std::vector<REAL>& rhs) 
{

#if defined _DEBUG
	std::printf("CholeskyR::CholeskyR(const std::vector<REAL>& rhs at: 0x%p) - executed at address: 0x%x, on LOC: %u\n", &rhs, __FUNCTIONW__, __LINE__);
#endif
	copy_vector(rhs);
}

fdlibcppwrapper::CholeskyR::CholeskyR(REAL (*functor)(REAL),const std::vector<REAL>& values) 
{

	copy_vector(functor, values);
}

fdlibcppwrapper::CholeskyR::CholeskyR(const CholeskyR& rhs)
{
	copy_ctor(rhs);
}

fdlibcppwrapper::CholeskyR::~CholeskyR()
{
#if defined _DEBUG
	std::printf("CholeskyR::~CholeskyR() - executed at address: 0x%x, on LOC: %d\n", __FUNCTIONW__, __LINE__);
#endif
}

FDLIB_INT fdlibcppwrapper::CholeskyR::get_m_N() const
{
	return this->m_N;
}


std::vector<REAL> fdlibcppwrapper::CholeskyR::get_m_a() const
{
	return this->m_a;
}


std::vector<REAL> fdlibcppwrapper::CholeskyR::get_m_l() const
{
	return this->m_l;
}


void fdlibcppwrapper::CholeskyR::operator()( CholeskyR& rhs)
{
	fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(rhs);
}

/*void fdlibcppwrapper::CholeskyR::operator()(bool(CholeskyR::*ptr_mem)(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines),
	const double m, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG

	_ASSERTE(ptr_mem != nullptr);
#else
	if(ptr_mem == nullptr)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::operator()() - NULL POINTER \n"));
	}
#endif
	ptr_mem = &CholeskyR::student_distr_fill;
	bool b_result = ptr_mem->CholeskyR::student_distr_fill(m, engine);
}*/

fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator()(CholeskyR * ptr, fdlibcppwrapper::CholeskyR::Ptr_to_func ptr_function,const double m,
	fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if(ptr == nullptr)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::operator()() - NULL POINTER \n"));
	}
#endif

	bool b_result = (ptr->*ptr_function)(m, engine);
	if (!b_result)
	{
#if defined _DEBUG
		std::cerr << " (ptr->*ptr_function)(m,engine) - retuned false " << std::endl;
#endif
		//if failed return unmodified object
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(*this);
		return *this;
	}
	
		

}

fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator()(CholeskyR * ptr, fdlibcppwrapper::CholeskyR::Ptr_to_func2 ptr_function2, const double m,
	const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if(ptr == nullptr)
	{
		throw std::runtime(std::string("ERROR in CholeskyR::operator()() - NULL POINTER\n"));
	}
#endif

	bool b_result = (ptr->*ptr_function2)(m, n, engine);
	if (!b_result)
	{
#if defined _DEBUG
		std::cerr << __FUNCTIONW__ << "()() executing indirect call to ptr->*ptr_function2)(m,n,engine) - returned false\n" << std::endl;
#endif		
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(*this);
		return *this;
	}
}


fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator()(CholeskyR * ptr, fdlibcppwrapper::CholeskyR::Ptr_to_func3 ptr_function, const double m,
	fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if(ptr == nullptr)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::operator()() - NULL POINTER\n"));
	}
#endif

	bool b_result = (ptr->*ptr_function)(m, engine);
	if (!b_result)
	{
#if defined _DEBUG
		std::cerr <<__FUNCTIONW__ << "()() executing indirect call to ptr->*ptr_function(m,engine) - failed with bool False\n" << std::endl;
#endif
		return *this;
	}
	else
	{
		
		fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(*this);
		
		return *this;
	}
}


fdlibcppwrapper::CholeskyR &  fdlibcppwrapper::CholeskyR::operator()(CholeskyR * ptr, fdlibcppwrapper::CholeskyR::Ptr_to_func4 ptr_function2, const double m,
	const double n, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if(ptr == nullptr)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::operator()() - NULL POINTER\n"));
	}
#endif
	bool b_result = (ptr->*ptr_function2)(m, n, engine);
	if (!b_result)
	{
		std::cerr << __FUNCTIONW__ << "()() executing indirect call to (ptr->*ptr_function2(m,n,engine) - failed with bool False\n" << std::endl;
	}
	else
	{
		
		fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(*this);
		
		return *this;

	}
	
}

fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator=(const CholeskyR& rhs)
{
	if (this != &rhs)
	{

		// Remove the current content.
		this->m_a.erase(this->m_a.begin(), this->m_a.end());
		this->m_l.erase(this->m_l.begin(), this->m_l.end());

		this->m_N = rhs.m_N;
		
		// copy rhs to this
		std::copy(rhs.m_a.begin(), rhs.m_a.end(), this->m_a.begin());
		std::copy(rhs.m_l.begin(), rhs.m_l.end() , this->m_l.begin());
#if defined _DEBUG
		std::printf("CholeskyR::operator=(const CholeskyR& rhs: 0x%p) - executed at address: 0x%x, on LOC: %d\n", &rhs, __FUNCTIONW__, __LINE__);
#endif
		return *this;
	}
}

fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator+=(const CholeskyR& rhs)
{
	if (this != &rhs)
	{
		if (this->m_N == rhs.m_N)
		{
			std::plus<double> p;
			
			for (int i = 0; i != this->m_N; ++i)
			{
				for (int j = 0; j != this->m_N; ++j)
				{
					//this->m_a[j * this->m_N + i] += rhs.m_a[j * this->m_N + i];
					//this->m_l[j * this->m_N + i] += rhs.m_l[j * this->m_N + i];
					this->m_a[j * this->m_N + i] = p(this->m_a[j * this->m_N + i], rhs.m_a[j * this->m_N + i]);
					this->m_l[j * this->m_N + i] = p(this->m_l[j * this->m_N + i], rhs.m_l[j * this->m_N + i]);
				}
			}
			return *this;
		}
	}
}

fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator-=(const CholeskyR& rhs)
{
	if (this != &rhs)
	{
		if (this->m_N == rhs.m_N)
		{
			std::minus<double> p;
			for (int i = 0; i != this->m_N; ++i)
			{
				for (int j = 0; j != this->m_N; ++j)
				{
					//this->m_a[j * this->m_N * i] -= rhs.m_a[j * this->m_N * i];
					//this->m_l[j * this->m_N * i] -= rhs.m_l[j * this->m_N * i];
					this->m_a[j * this->m_N + i] = p(this->m_a[j * this->m_N + i], rhs.m_a[j * this->m_N + i]);
					this->m_l[j * this->m_N + i] = p(this->m_l[j * this->m_N + i], rhs.m_l[j * this->m_N + i]);
				}
			}
			return *this;
		}
	}
}

std::unique_ptr<fdlibcppwrapper::CholeskyR> fdlibcppwrapper::operator*(const fdlibcppwrapper::CholeskyR& a, const fdlibcppwrapper::CholeskyR& b)
{
	if (a.m_N == b.m_N)
	{
		CholeskyR  * c = new CholeskyR(a.m_N * a.m_N);
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = std::inner_product(a.m_a.begin(), a.m_a.end(), b.m_a.begin(), double(0.0L));
			}
			//c->m_a[i] = std::inner_product(a.get_m_a().begin(), a.get_m_a().end(), b.get_m_a().begin(), 0.0);
		}
		std::unique_ptr<CholeskyR> ret_ptr{ c };
		return ret_ptr;
		
	}

}
		
std::unique_ptr<fdlibcppwrapper::CholeskyR> fdlibcppwrapper::operator+(const fdlibcppwrapper::CholeskyR& a, const fdlibcppwrapper::CholeskyR& b)
{
	if (a.m_N == b.m_N)
	{
		std::plus<double> p;
		CholeskyR * c = new CholeskyR(a.m_N * a.m_N);
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = p.operator()(a.m_a[j * c->m_N + i], b.m_a[j * c->m_N + i]);
				c->m_l[j * c->m_N + i] = p.operator()(a.m_l[j * c->m_N + i], b.m_l[j * c->m_N + i]);
			}
		}
		std::unique_ptr<fdlibcppwrapper::CholeskyR> ret_ptr{ c };
		return ret_ptr;
	}
}
		
std::unique_ptr<fdlibcppwrapper::CholeskyR> fdlibcppwrapper::operator-(const fdlibcppwrapper::CholeskyR& a, const fdlibcppwrapper::CholeskyR& b)
{
	if (a.m_N == b.m_N)
	{
		std::minus<double> p;
		CholeskyR * c = new CholeskyR(a.m_N * a.m_N);
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = p.operator()(a.m_a[j * c->m_N + i], b.m_a[j * c->m_N + i]);
				c->m_l[j * c->m_N + i] = p.operator()(a.m_l[j * c->m_N + i], b.m_l[j * c->m_N + i]);
			}
		}
		std::unique_ptr<fdlibcppwrapper::CholeskyR> ret_ptr{ c };
		return ret_ptr;
	}
}

/*template<typename Function> std::unique_ptr<fdlibcppwrapper::CholeskyR> fdlibcppwrapper::apply(Function f)
{
	fdlibcppwrapper::CholeskyR * ret_type = new fdlibcppwrapper::CholeskyR(f());
	std::unique_ptr<fdlibcppwrapper::CholeskyR> ret_ptr( ret_type );
	return ret_ptr;
}*/

// Operates on created CholeskyR object. Lambda argument passes pointer to object
// of CholeskyR type which contains the result of call to wrapped CHOL_R routine.
  fdlibcppwrapper::CholeskyR & fdlibcppwrapper::CholeskyR::operator()(std::unique_ptr<fdlibcppwrapper::CholeskyR> up)
{
#if defined _DEBUG
	_ASSERTE(up->m_N == this->m_N);
#else
	if (up->m_N != this->m_N)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::operator()() - Invalid up->m_N size\n"));
	}

#endif
	for (int i = 0; i != up->m_N; ++i)
	{
		for (int j = 0; j != up->m_N; ++j)
		{
			this->m_a[j * up->m_N + i] = up->m_a[j * up->m_N + i];
			this->m_l[j * up->m_N + i] = up->m_l[j * up->m_N + i];
		}
	}
	return *this;
}

std::unique_ptr<fdlibcppwrapper::CholeskyR> fdlibcppwrapper::CholeskyR::apply3(std::unique_ptr<fdlibcppwrapper::CholeskyR> up)
{
	fdlibcppwrapper::CholeskyR * ret_type = new fdlibcppwrapper::CholeskyR(up->get_m_a());
	std::unique_ptr<fdlibcppwrapper::CholeskyR> ret_ptr (ret_type);
	return ret_ptr;
}

bool fdlibcppwrapper::exp_dist_fill(std::vector<REAL>& arg, const double m, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::exponential_distribution(arg, m,seed, engine);
	return true;
}


void fdlibcppwrapper::CholeskyR::rand_fill(std::vector<REAL>& v, const REAL lo_bound, const REAL up_bound)
{
#if defined (_DEBUG)
	_ASSERTE(fabs(up_bound - lo_bound) > FdlibCPPWrappUtils::get_epsilon());
#else
	if(fabs(up_bound - lo_bound) > std::numeric_limits<REAL>::epsilon())
	{
		throw std::runtime_error(std::basic_string<TCHAR>("ERROR in CholeskyR::rand_fill() - bound lower or almost equal to epsilon\n"));
	}
#endif

	size_t seed(clock());
	std::default_random_engine rand_engine( seed);
	std::uniform_real_distribution<REAL> distribution( lo_bound, up_bound );
	for (auto &elems : v)
		elems = distribution(rand_engine);

}

void fdlibcppwrapper::CholeskyR::copy_vector(const std::vector<REAL>& rhs)
{
#if defined (_DEBUG)
	std::printf("rhs.size() = %d\n", rhs.size());
	_ASSERTE(rhs.size() == (FDLIB_ARRAY_10 * FDLIB_ARRAY_10));
#else
	if(rhs.size() != FDLIB_ARRAY_10)
	{
		throw std::runtime_error(std::basic_string<TCHAR>("ERROR in CholeskyR::copy_vector() - Invalid Argument Size\n"));
	}
#endif

	this->m_N = rhs.size()/10;
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	this->m_a = std::vector<REAL>(rhs);
	/*for (auto i = 0; i != this->m_N; ++i)
	{
		for (auto j = 0; j != this->m_N ; ++i)
		{
			this->m_a[j * this->m_N + i] = rhs[j * this->m_N + i];
		}
	}*/
}

void fdlibcppwrapper::CholeskyR::init_vector(const int n, const REAL lo_bound, const REAL up_bound)
{
#if defined (_DEBUG)
	_ASSERTE((n == FDLIB_ARRAY_10) && (fabs(up_bound - lo_bound) > FdlibCPPWrappUtils::get_epsilon()));
#else
	if((n != FDLIB_ARRAY_10) && (fabs(up_bound - lo_bound) <= FdlibCPPWrappUtils::get_epsilon()))
	{
		throw std::runtime_error(std::basic_string<TCHAR>("ERROR in CholeskyR::init_vector() - Invalid argument or bound are less that epsilon\n"));
	}
#endif
	
	this->m_N = n;
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
	rand_fill(this->m_a, lo_bound, up_bound);
}

void fdlibcppwrapper::CholeskyR::init_vector(const int n)
{
#if defined _DEBUG
	_ASSERTE(n == FDLIB_ARRAY_10);
#else
	if(n != FDLIB_ARRAY_10)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyR::init_vector(const int) - Invalid argument size\n"));
	}
#endif
	
	this->m_N = n;
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
}


void fdlibcppwrapper::CholeskyR::copy_vector(REAL (*functor)(REAL), const std::vector<REAL>& values)
{
#if defined (_DEBUG)
	_ASSERTE((functor != nullptr) || (values.size() == (FDLIB_ARRAY_10 * FDLIB_ARRAY_10)));
#else
	if ((functor == nullptr) || (values.size() != FDLIB_ARRAY_10))
	{
		throw std::runtime_error<TCHAR>("ERROR in CholeskyR::CholeskyR() - Null Pointer or Invalid Argument Size\n"));
	}
#endif

	this->m_N = values.size()/FDLIB_ARRAY_10;
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
	for (auto i = 0; i != this->m_N; ++i)
	{
		for (auto j = 0; j != this->m_N; ++j)
		{

			this->m_a[j * this->m_N + i] = functor(values[j * this->m_N + i]);
		}
	}
}

void fdlibcppwrapper::CholeskyR::copy_ctor(const CholeskyR& rhs)
{
	this->m_N = rhs.m_N;
	this->m_l = std::vector<REAL>(rhs.m_l);
	this->m_a = std::vector<REAL>(rhs.m_a);
}

void fdlibcppwrapper::CholeskyR::set_m_l(std::vector<REAL>& result)
{
	this->m_l = std::vector<REAL>(result);
}

void fdlibcppwrapper::CholeskyR::set_m_N(FDLIB_INT n)
{
	this->m_N = n;
}

void fdlibcppwrapper::CholeskyR::set_m_a(std::vector<REAL>& vec)
{
	this->m_a = std::vector<REAL>(vec);
}


void fdlibcppwrapper::CholeskyR::debug_print()
{
	std::printf("Array a\n");
	for (int i = 0; i != this->m_N; ++i)
	{
		for (int j = 0; j != this->m_N; ++j)
		{
			std::printf("Array a[%2d %2d %2d] = %2.15f\n", j, i, this->m_N, this->m_a[j * this->m_N + i]);
		}
		std::printf("\n");
	}
	std::printf("\n");

	std::printf("Array l\n");
	for (int i = 0; i != this->m_N; ++i)
	{
		for (int j = 0; j != this->m_N; ++j)
		{
			std::printf("Array l[%2d %2d %2d] = %2.15f\n", j, i, this->m_N, this->m_l[j * this->m_N + i]);
		}
		std::printf("\n");
	}
	std::printf("\n");
}


void fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(CholeskyR& cholesky)
{
	std::vector<REAL> temp(cholesky.get_m_N() * cholesky.get_m_N());
	auto n = cholesky.get_m_N();
	CHOL_R(&temp[0], &cholesky.get_m_a()[0], &n);
	cholesky.set_m_l(temp);
	
}

void fdlibcppwrapper::CholeskyRWrapper::fdlib_chol_r(std::vector<REAL> l, std::vector<REAL> a, FDLIB_INT n)
{
	
	CHOL_R(&l[0], &a[0], &n);

}