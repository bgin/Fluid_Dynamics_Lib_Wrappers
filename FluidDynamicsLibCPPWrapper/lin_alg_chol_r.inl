

__forceinline bool fdlibcppwrapper::CholeskyR::uni_real_dist_fill(const int min_val, const int max_val, const int num_engine)
{
	std::size_t seed = 0U;
	unsigned int status = 9999;
	if ((status = _rdrand32_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::UniDistributions<double>::uni_real_distribution(this->m_a, min_val, max_val, seed, num_engine);
	return true;
}

__forceinline bool fdlibcppwrapper::CholeskyR::exp_dist_fill(const double lambda, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::exponential_distribution(this->m_a, lambda, seed, engine);
	return true;
}

__forceinline   bool fdlibcppwrapper::CholeskyR::gamm_dist_fill(const double alpha, const double beta, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::gamma_distribution(this->m_a, alpha, beta, seed, engine);
	return true;
}

__forceinline   bool fdlibcppwrapper::CholeskyR::weib_distr_fill(const double a, const double b, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::weibull_distribution(this->m_a, a, b, seed, engine);
	return true;
}

__forceinline   bool fdlibcppwrapper::CholeskyR::extr_val_distr_fill(const double a, const double b, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::extreme_value_distribution(this->m_a, a, b, seed,engine);
	return true;
}

__forceinline   bool fdlibcppwrapper::CholeskyR::norm_distr_fill(const double m, const double s, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::normal_distribution(this->m_a, m, s, seed, engine);
	return true;
}

__forceinline  bool  fdlibcppwrapper::CholeskyR::lognorm_distr_fill(const double m, const double s, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::lognormal_ditribution(this->m_a, m, s, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyR::chisquare_distr_fill(const double m, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::chi_squared_distribution(this->m_a, m, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyR::cauchy_distr_fill(const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::cauchy_distribution(this->m_a, a, b, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyR::fisher_distr_fill(const double m, const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdseed64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::fisher_f_distribution(this->m_a, m, n, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyR::student_distr_fill(const double m, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{
		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::student_t_distribution(this->m_a, m, seed, engine);
	return true;
}

// Proper way of defining/declaring template function to be used with lambda functor.
template<typename Function>  std::unique_ptr<fdlibcppwrapper::CholeskyR> apply2(Function f, CholeskyR cholesky)
{
	std::unique_ptr<CholeskyR> ptr = f(cholesky);
	
	return ptr;
}

template<typename Function> std::unique_ptr<CholeskyR> CholeskyR::apply2(Function f, CholeskyR cholesky)
{
	std::unique_ptr<CholeskyR> ptr = f(cholesky);
	return ptr;
	
}
template<typename Function>  std::unique_ptr<fdlibcppwrapper::CholeskyR> apply(Function f, std::vector<REAL>& arg)
{
	std::unique_ptr<CholeskyR> ptr = f(arg);
	
	return ptr;
}
