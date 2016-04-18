

__forceinline  bool fdlibcppwrapper::CholeskyC::uni_real_distr_fill(const double a, const double b, const int engine)
{
	std::size_t seed = 0U;
	unsigned int status = 9999;
	if ((status = _rdrand32_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::UniDistributions<double>::uni_real_distribution(this->m_a, a, b, seed, engine);
	return true;
}


__forceinline   bool fdlibcppwrapper::CholeskyC::exp_distr_fill(const double lambda, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::exponential_distribution(this->m_a, lambda, seed, engine);
	return true;
}


__forceinline   bool fdlibcppwrapper::CholeskyC::gamma_distr_fill(const double a, const double b, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::gamma_distribution(this->m_a, a, b, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::extr_val_distr_fill(const double a, const double b, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::extreme_value_distribution(this->m_a, a, b, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::norm_distr_fill(const double m, const double s, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::normal_distribution(this->m_a, m, s, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::lognorm_distr_fill(const double m, const double s, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::lognormal_ditribution(this->m_a, m, s, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::chisquared_distr_fill(const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::chi_squared_distribution(this->m_a, n, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::cauchy_distr_fill(const double a, const double b, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::cauchy_distribution(this->m_a, a, b, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::fisher_distr_fill(const double m, const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::fisher_f_distribution(this->m_a, m, n, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::weibull_distr_fill(const double m, const double n, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}

	auto s1 = fdlibcppwrapper::PoissonDistributionImpl<double>::weibull_distribution(this->m_a, m, n, seed, engine);
	return true;
}

__forceinline  bool fdlibcppwrapper::CholeskyC::student_distr_fill(const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines engine)
{
	unsigned long long seed = 0ULL;
	unsigned int status = 9999;
	if ((status = _rdrand64_step(&seed)) == 0)
	{

		return false;
	}
	auto s1 = fdlibcppwrapper::NormalDistributionImpl<double>::student_t_distribution(this->m_a, n, seed, engine);
	return true;
}

template<typename _Function> std::unique_ptr<CholeskyC> fdlibcppwrapper::CholeskyC::apply(_Function f, fdlibcppwrapper::CholeskyC cholesky)
{
	std::unique_ptr<CholeskyC> ret_ptr = f(cholesky);
	return ret_ptr;
}

template<typename _Function> std::unique_ptr<fdlibcppwrapper::CholeskyC> apply_functor(_Function f, fdlibcppwrapper::CholeskyC cholesky)
{
	std::unique_ptr<CholeskyC> ret_ptr = f(cholesky);
	return ret_ptr;
}

template<typename _Function> std::unique_ptr<fdlibcppwrapper::CholeskyC> apply_functor(_Function f, std::vector<REAL>& arg)
{
	std::unique_ptr<CholeskyC> ret_ptr = f(arg);
	return ret_ptr;
}