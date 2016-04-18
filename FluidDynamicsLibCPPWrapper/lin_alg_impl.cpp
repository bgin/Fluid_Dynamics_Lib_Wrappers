
#include "lin_alg.h"


fdlibcppwrapper::CholeskyC::CholeskyC()
{
#if defined _DEBUG
	std::printf("CholeskyC::CholeskyC() - executed at address: 0x%x, on LOC:%d\n", __FUNCTIONW__, __LINE__);
#endif
}


fdlibcppwrapper::CholeskyC::CholeskyC(const int n)
{
#if defined (_DEBUG)
	_ASSERTE(n == FDLIB_ARRAY_10);
#else
	if(n != FDLIB_ARRAY_10)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyC::CholeskyC() - Invalid Argument Size\n"));
	}
#endif
	this->m_N = n;
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
#if defined _DEBUG
	std::printf("CholeskyC::CholeskyC(%d) - executed at address: 0x%x, on LOC:%d\n",n, __FUNCTIONW__, __LINE__);
#endif
}


fdlibcppwrapper::CholeskyC::CholeskyC( int n, const REAL lo_bound, const REAL up_bound) : m_N(n)
{
#if defined (_DEBUG)
	_ASSERTE(n == FDLIB_ARRAY_10);
#else
	if(n != FDLIB_ARRAY_10)
	{
		throw std::runtime_error(std::basic_string<TCHAR>(L"ERROR in CholeskyC::CholeskyC(const int) - invalid argument\n"));
	}
#endif
	
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	rand_fill(this->m_a, lo_bound, up_bound);
#if defined _DEBUG
	std::printf("CholeskyC::CholeskyC(%d, %.9f, %.9f) - executed at address: 0x%x, on LOC:%d\n", n,lo_bound,up_bound, __FUNCTIONW__, __LINE__);
#endif
}

fdlibcppwrapper::CholeskyC::CholeskyC(const std::vector<REAL>& v)
{
#if defined (_DEBUG)
	_ASSERTE(v.size() == (FDLIB_ARRAY_10 * FDLIB_ARRAY_10));
#else
	if (v.size() != (FDLIB_ARRAY_10 * FDLIB_ARRAY_10))
	{
		throw std::runtime_error(std::basic_string<TCHAR>(L"ERROR in CholeskyC::CholeskyC() - invalid argument\n"))
	}
#endif
	this->m_N = v.size() / FDLIB_ARRAY_10;
	this->m_l = std::vector<REAL>(this->m_N * this->m_N);
	this->m_a = std::vector<REAL>(this->m_N * this->m_N);
	for (int i = 0; i != this->m_N; ++i)
	{
		for (int j = 0; j != this->m_N; ++j)
		{
			this->m_a[j * this->m_N + i] = v[j * this->m_N + i];
		}
	}
#if defined _DEBUG
	std::printf("CholeskyC::CholeskyC(const std::vector<REAL> v: 0x%p) - executed at address: 0x%x, on LOC:%d\n", &v, __FUNCTIONW__, __LINE__);
#endif
}

fdlibcppwrapper::CholeskyC::CholeskyC(const CholeskyC& rhs) : m_N(rhs.m_N)
{
	this->m_a = std::vector<REAL>(rhs.m_a);
	this->m_l = std::vector<REAL>(rhs.m_l);
	//this->m_N = rhs.m_N;
#if defined _DEBUG
	std::printf("CholeskyC::CholeskyC(const CholeskyC& rhs: 0x%p) - executed at address: 0x%x, on LOC:%d\n", &rhs, __FUNCTIONW__, __LINE__);
#endif
}

fdlibcppwrapper::CholeskyC::~CholeskyC()
{
#if defined _DEBUG
	std::printf("CholeskyC::~CholeskyC() - executed at address: 0x%x, on LOC:%d\n", __FUNCTIONW__, __LINE__);
#endif
}

std::unique_ptr<fdlibcppwrapper::CholeskyC> fdlibcppwrapper::operator+(const fdlibcppwrapper::CholeskyC& a, const fdlibcppwrapper::CholeskyC& b)
{
	if (a.m_N == b.m_N)
	{
		CholeskyC * c = new CholeskyC(a.m_N * a.m_N);
		std::plus<double> p;
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = p.operator()(a.m_a[j * c->m_N + i], b.m_a[j * c->m_N + i]);
				c->m_l[j * c->m_N + i] = p.operator()(a.m_l[j * c->m_N + i], b.m_l[j * c->m_N + i]);
			}
		}
		std::unique_ptr<CholeskyC> ret_ptr{ c };
		return ret_ptr;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in fdlibcppwrapper::operator+( const CholeskyC& a, const CholeskyC& b) - a.m_N != b.m_N\n"));
	}
}

std::unique_ptr<fdlibcppwrapper::CholeskyC> fdlibcppwrapper::operator-(const fdlibcppwrapper::CholeskyC& a, const fdlibcppwrapper::CholeskyC& b)
{
	if (a.m_N == b.m_N)
	{
		CholeskyC * c = new CholeskyC(a.m_N * a.m_N);
		std::minus<double> p;
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = p.operator()(a.m_a[j * c->m_N + i], b.m_a[j * c->m_N + i]);
				c->m_l[j * c->m_N + i] = p.operator()(a.m_l[j * c->m_N + i], b.m_l[j * c->m_N + i]);
			}
		}
		std::unique_ptr<CholeskyC> ret_ptr{ c };
		return ret_ptr;
	}
	else
	{
		throw std::runtime_error(std::string(" FATAL ERROR in fdlibcppwrapper::operator-(const CholeskyC& a, const CholeskyC& b) - a.m_N != b.m_N\n"));
	}
}

std::unique_ptr<fdlibcppwrapper::CholeskyC> fdlibcppwrapper::operator*(const fdlibcppwrapper::CholeskyC& a, const fdlibcppwrapper::CholeskyC& b)
{
	if (a.m_N == b.m_N)
	{
		CholeskyC * c = new CholeskyC(a.m_N * a.m_N);
		
		for (int i = 0; i != c->m_N; ++i)
		{
			for (int j = 0; j != c->m_N; ++j)
			{
				c->m_a[j * c->m_N + i] = std::inner_product(a.m_a.begin(), a.m_a.end(), b.m_a.begin(), double(0.0L));
				c->m_l[j * c->m_N + i] = std::inner_product(a.m_l.begin(), a.m_l.end(), b.m_l.begin(), double(0.0L));
			}
		}
		std::unique_ptr<CholeskyC> ret_ptr{ c };
		return ret_ptr;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in fdlibcppwrapper::operator*(const CholeskyC& a, const CholeskyC& b) - a.m_N != b.m_N\n"));
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator=(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this != &rhs)
	{
		if (this->m_N == rhs.m_N)
		{

			// remove current content.
			this->m_a.erase(this->m_a.begin(), this->m_a.begin() + this->m_a.size());
			this->m_l.erase(this->m_l.begin(), this->m_l.begin() + this->m_l.size());
			this->m_N = rhs.m_N;
			// copy content.
			//std::copy(rhs.m_a.begin(), rhs.m_a.end(), this->m_a);
			//std::copy(rhs.m_l.begin(), rhs.m_l.end(), this->m_l);
			this->m_a.operator=(rhs.m_a);
			this->m_l.operator=(rhs.m_l);
#if defined _DEBUG
			std::printf("CholeskyC::operator=(const CholeskyC& rhs: 0x%p) - executed at address: 0x%x, on LOC:%d\n",&rhs, __FUNCTIONW__, __LINE__);
#endif
			return *this;
		}
		else
		{
			throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator=(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
		}
	}
	else
	{
		throw std::runtime_error(std::string(" FATAL ERROR in CholeskyC::operator=(const CholeskyC& rhs) - this == &rhs\n"));
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator+=(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this->m_N == rhs.m_N)
	{
		std::plus<double> p;
		for (int i = 0; i != this->m_N; ++i)
		{
			for (int j = 0; j != this->m_N; ++j)
			{
				this->m_a[j * this->m_N + i] = p.operator()(this->m_a[j * this->m_N + i], rhs.m_a[j * this->m_N + i]);
				this->m_l[j * this->m_N + i] = p.operator()(this->m_l[j * this->m_N + i], rhs.m_l[j * this->m_N + i]);
			}
		}
		return *this;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator+=(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator-=(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this->m_N == rhs.m_N)
	{
		std::minus<double> p;
		for (auto i = 0; i != this->m_N; ++i)
		{
			for (auto j = 0; j != this->m_N; ++j)
			{
				this->m_a[j * this->m_N + i] = p.operator()(this->m_a[j * this->m_N + i], rhs.m_a[j * this->m_N + i]);
				this->m_l[j * this->m_N + i] = p.operator()(this->m_l[j * this->m_N + i], rhs.m_l[j * this->m_N + i]);
			}
		}
		return *this;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator-=(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator*=(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this->m_N == rhs.m_N)
	{
		for (auto i = 0; i != this->m_N; ++i)
		{
			for (auto j = 0; j != this->m_N; ++j)
			{
				this->m_a[j * this->m_N + i] = std::inner_product(this->m_a.begin(), this->m_a.end(), rhs.m_a.begin(), double(0.0L));
				this->m_l[j * this->m_N + i] = std::inner_product(this->m_l.begin(), this->m_l.end(), rhs.m_a.begin(), double(0.0L));
			}
		}
		return *this;
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator*=(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
	}
}

fdlibcppwrapper::CholeskyC::ArrayEquality  fdlibcppwrapper::CholeskyC::operator==(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this != &rhs)
	{
		if (this->m_N == rhs.m_N)
		{
			//std::vector<bool> results(this->m_N * this->m_N);
			ArrayEquality results = ArrayEquality();
			results.vec_m_a =  std::vector<bool>(rhs.m_N * rhs.m_N);
			results.vec_m_l =  std::vector<bool>(rhs.m_N * rhs.m_N);
			const bool almost_equal = true;
			const bool almost_not_equal = false;
			for (auto i = 0; i != this->m_N; ++i)
			{
				for (auto j = 0; j != this->m_N; ++j)
				{
					if ((std::fabs(this->m_a[j * this->m_N + i] - rhs.m_a[j * this->m_N + i])) <= std::numeric_limits<double>::epsilon())
					{
						results.vec_m_a.push_back(almost_equal);
					}
					else
					{
						results.vec_m_a.push_back(almost_not_equal);
					}

					if ((std::fabs(this->m_l[j * this->m_N + i] - rhs.m_l[j * this->m_N + i])) <= std::numeric_limits<double>::epsilon())
					{
						results.vec_m_l.push_back(almost_equal);
					}
					else
					{
						results.vec_m_l.push_back(almost_not_equal);
					}
				}
			}
			return results;
		}
		else
		{
			throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator==(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
		}
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator==(const CholeskyC& rhs) - this != &rhs\n"));
	}
}

fdlibcppwrapper::CholeskyC::ArrayEquality  fdlibcppwrapper::CholeskyC::operator!=(const fdlibcppwrapper::CholeskyC& rhs)
{
	if (this != &rhs)
	{
		if (this->m_N == rhs.m_N)
		{
			ArrayEquality results = ArrayEquality();
			results.vec_m_a = std::vector<bool>(rhs.m_N * rhs.m_N);
			results.vec_m_l = std::vector<bool>(rhs.m_N * rhs.m_N);
			const bool almost_equal = true;
			const bool not_equal = false;
			for (auto i = 0; i != this->m_N; ++i)
			{
				for (auto j = 0; j != this->m_N; ++j)
				{
					if ((std::fabs(this->m_a[j * this->m_N + i] - rhs.m_a[j * this->m_N + i])) > std::numeric_limits<double>::epsilon())
					{
						results.vec_m_a.push_back(not_equal);
					}
					else
					{
						results.vec_m_a.push_back(almost_equal);
					}

					if ((std::fabs(this->m_l[j * this->m_N + i] - rhs.m_l[j * this->m_N + i])) > std::numeric_limits<double>::epsilon())
					{
						results.vec_m_l.push_back(not_equal);
					}
					else
					{
						results.vec_m_l.push_back(almost_equal);
					}
				}
			}
			return results;
		}
		else
		{
			throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator!=(const CholeskyC& rhs) - this->m_N != rhs.m_N\n"));
		}
	}
	else
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator!=(const CholeskyC& rhs) - this == &rhs\n"));
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator()(fdlibcppwrapper::CholeskyC * ptr, CholeskyC::PTR_ND1 ptr_nd1, const double m,
	fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if(ptr == nullptr)
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator()() - NULL POINTER \n"));
	}
#endif
	bool b_result = (ptr->*ptr_nd1)(m, engine);
#if defined _DEBUG
	std::cerr << __FUNCTIONW__ << "()() executing indirect call to ptr->*ptr_nd1)(m,engine) - returned false\n" << std::endl;
#endif
	if (!b_result)
	{
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*this);
		return *this;
	}
}


fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator()(fdlibcppwrapper::CholeskyC * ptr, CholeskyC::PTR_ND2 ptr_nd2, const double m,
	                                                   const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined  _DEBUG
	    _ASSERTE(ptr != nullptr);
#else
                if (ptr == nullptr)
                 {
	               throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator()() - NULL POINTER \n"));
                 }
#endif
  
              bool b_result   = (ptr->*ptr_nd2)(m, n, engine);
#if defined _DEBUG
			  std::cerr << __FUNCTIONW__ << "()() executing indirect call to ptr->*ptr_nd1)(m,n,engine) - returned false\n" << std::endl;
#endif
			  if (!b_result)
			  {
				  return *this;
			  }
			  else
			  {
				  fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*this);
				  return *this;
			  }
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator()(fdlibcppwrapper::CholeskyC * ptr, CholeskyC::PTR_PD1 ptr_pd1, const double m,
	fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined  _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if (ptr == nullptr)
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator()() - NULL POINTER \n"));
	}
#endif

	bool b_result = (ptr->*ptr_pd1)(m, engine);
#if defined _DEBUG
	std::cerr << __FUNCTIONW__ << "()() executing indirect call to ptr->*ptr_pd1)(m,engine) - returned false\n" << std::endl;
#endif
	if (!b_result)
	{
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*this);
		return *this;
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator()(fdlibcppwrapper::CholeskyC * ptr, CholeskyC::PTR_PD2 ptr_pd2, const double m,
	const double n, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
#if defined  _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if (ptr == nullptr)
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator()() - NULL POINTER \n"));
	}
#endif

	bool b_result = (ptr->*ptr_pd2)(m, n, engine);
#if defined _DEBUG
	std::cerr << __FUNCTIONW__ << "()() executing indirect call to (ptr->*ptr_pd2)(m,engine) - returned false\n" << std::endl;
#endif
	if (!b_result)
	{
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*this);
		return *this;
	}
}

fdlibcppwrapper::CholeskyC & fdlibcppwrapper::CholeskyC::operator()(fdlibcppwrapper::CholeskyC * ptr, CholeskyC::PTR_UD ptr_ud, const double a, const double b,
	const int engine)
{
#if defined  _DEBUG
	_ASSERTE(ptr != nullptr);
#else
	if (ptr == nullptr)
	{
		throw std::runtime_error(std::string("FATAL ERROR in CholeskyC::operator()() - NULL POINTER \n"));
	}
#endif
	bool b_result = (ptr->*ptr_ud)(a, b, engine);
#if defined _DEBUG
	std::cerr << __FUNCTIONW__ << "()() executing indirect call to (ptr->*ptr_ud)(a,b,engine) - returned false\n" << std::endl;
#endif

	if (!b_result)
	{
		return *this;
	}
	else
	{
		fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(*this);
		return *this;
	}
}


void fdlibcppwrapper::CholeskyC::rand_fill(std::vector<REAL>& v, const REAL lo_bound, const REAL up_bound)
{
#if defined (_DEBUG)
	_ASSERTE(fabs(up_bound - lo_bound) > std::numeric_limits<REAL>::epsilon());
#else
	if(fabs(up_bound - lo_bound) > std::numeric_limits<REAL>::epsilon())
	{
		throw std::runtime_error(std::basic_string<TCHAR>(L"ERROR in CholeskyC::rand_fill() - Invalid Argument\n"));
	}
#endif
	size_t seed(clock());
	std::default_random_engine rand_engine{ seed };
	std::uniform_real_distribution<REAL> distribution{ lo_bound, up_bound };
	for (auto &elems : v)
		elems = distribution(rand_engine);

}

void fdlibcppwrapper::CholeskyC::set_m_l(std::vector<REAL>& result)
{
	this->m_l = std::vector<REAL>(result);
}

std::vector<REAL> fdlibcppwrapper::CholeskyC::get_m_a() const
{
	return this->m_a;
}

std::vector<REAL> fdlibcppwrapper::CholeskyC::get_m_l() const
{
	return this->m_l;
}

FDLIB_INT  fdlibcppwrapper::CholeskyC::get_m_N() const
{
	return this->m_N;
}

#if defined _DEBUG
void fdlibcppwrapper::CholeskyC::debug_print()
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

bool fdlibcppwrapper::CholeskyC::print_to_file(const char *fname)
{
	_ASSERTE(fname != NULL);

	FILE * fp;
	bool b_result;
	if ((fopen_s(&fp, fname, "wt")) != 0)
	{
		std::printf("fopen_s() failed to open file: %s\n", fname);
		return b_result = false;
		
	}
	else
	{
		fprintf(fp, "Writing content of array a(%d,%d)  to file: %s, status: started\n\n",this->m_N,this->m_N,fname);
		for (auto i = 0; i != this->m_N; ++i)
		{
			for (auto j = 0; j != this->m_N; ++j)
			{
				fprintf(fp, "a[%d,%d,%d] = %2.15f\n", j, i, this->m_N, this->m_a[j * this->m_N + i]);
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n\n");

		fprintf(fp, "Writing content of array l(%d,%d) to file: %s, status: started\n\n", this->m_N, this->m_N, fname);
		for (auto i = 0; i != this->m_N; ++i)
		{
			for (auto j = 0; j != this->m_N; ++j)
			{
				fprintf(fp, "l[%d,%d,%d] = %2.15f\n", j, i, this->m_N, this->m_l[j * this->m_N + i]);
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n\n");
		fprintf(fp, "Finished writing content to file:%s\n", fname);
		fclose(fp);
		return b_result = true;
	}
}
#endif

void fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(  CholeskyC& cholesky)
{
	std::vector<REAL> temp(cholesky.get_m_N() * cholesky.get_m_N());
	int n = cholesky.get_m_N();
	CHOL_C(&temp[0], &cholesky.get_m_a()[0],&n);
	cholesky.set_m_l(temp);
	//For debug only
	/*for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != n; ++j)
		{
			std::printf("Array l[%2d %2d %2d] = %2.15f\n", j, i, n, cholesky.get_m_l()[j * n + i]);
		}
		std::printf("\n");
	}
	std::printf("\n");*/
}

void fdlibcppwrapper::CholeskyCWrapper::fdlib_chol_c(std::vector<REAL>& l, std::vector<REAL>& a, FDLIB_INT n)
{
#if defined _DEBUG
	_ASSERTE(n == FDLIB_ARRAY_10);
#else
	if(n != FDLIB_ARRAY_10)
	{
		throw std::runtime_error(std::string("ERROR in CholeskyCWrapper::fdlib_chol_c() - Invalid Argument Size\n"));
	}
#endif

	CHOL_C(&l[0], &a[0], &n);
}