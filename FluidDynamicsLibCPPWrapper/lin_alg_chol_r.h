#ifndef _LIN_ALG_CHOL_R_H_
#define _LIN_ALG_CHOL_R_H_

#include <memory>
#include "F77_lin_alg_defs.h"
#include "fdlibcppwrapper_utils.h"
#include "StatDistributionWrapper.h"
namespace fdlibcppwrapper
{
	class CholeskyR
	{
	public:

		// Initialized by member function which in turn calls Random Distribution function.
		CholeskyR(const int);

		// Initialized by call to HW RDRAND 
		CholeskyR(const int, const REAL, const REAL);

		// Initialize by std::vector.
		CholeskyR(const std::vector<REAL>&);

		// Copy Ctor.
		CholeskyR(const CholeskyR&);

		// Functor fill.
		CholeskyR(REAL (*)(REAL),const std::vector<REAL>&);

		// Dtor.
		~CholeskyR();
		// Setter
		void set_m_l(std::vector<REAL>&);

		void set_m_N(FDLIB_INT);

		void set_m_a(std::vector<REAL>&);

		FDLIB_INT get_m_N() const;

		std::vector<REAL> get_m_l() const;

		std::vector<REAL> get_m_a() const;

		// member functions delegates which encapsulate call to StatsDistribution  template function

		// _rdrand_step64() failed to compile - unindentified symbol
	__forceinline	bool uni_real_dist_fill(const int, const int, const int);
	
	__forceinline	bool exp_dist_fill(const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);
	

	__forceinline   bool gamm_dist_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool weib_distr_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool extr_val_distr_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool norm_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool lognorm_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool chisquare_distr_fill(const double n, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool cauchy_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool fisher_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	__forceinline   bool student_distr_fill(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	// Member operators
	void operator()(CholeskyR&);

	CholeskyR & operator+=(const CholeskyR&);

	CholeskyR & operator-=(const CholeskyR&);

	CholeskyR & operator=(const CholeskyR&);

	//CholeskyR & operator*(const CholeskyR&);
	//void operator()(bool(CholeskyR::*)(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines), const double,
		//fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	
	// Pointers to member functions

	//using ND_RNE = fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines;

	
	//typedef fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines PD_RNE;

	using Ptr_to_func = bool(CholeskyR::*)(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	using Ptr_to_func2 = bool(CholeskyR::*)(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	using Ptr_to_func3 = bool(CholeskyR::*)(const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	using Ptr_to_func4 = bool(CholeskyR::*)(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	CholeskyR & operator()(CholeskyR *, Ptr_to_func, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	CholeskyR & operator()(CholeskyR *, Ptr_to_func2, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

	CholeskyR & operator()(CholeskyR *, Ptr_to_func3, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	CholeskyR & operator()(CholeskyR *, Ptr_to_func4, const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

	// Called mainly with the lambda argument.
	CholeskyR & operator()(std::unique_ptr<CholeskyR>);

	std::vector<REAL>&          operator()(std::vector<REAL>&);
	//template<typename Function> static std::unique_ptr<CholeskyR> apply2(Function);

	// Called mainly with the lambda argument.
	static std::unique_ptr<CholeskyR>  apply3(std::unique_ptr<CholeskyR>);

	template<typename Function>  std::unique_ptr<CholeskyR> apply2(Function, CholeskyR);
	

#if defined (_DEBUG)
		void debug_print();
#endif
		
		// friend operators.
		std::unique_ptr<CholeskyR> friend operator*(const CholeskyR&, const CholeskyR&);

		std::unique_ptr<CholeskyR> friend operator+(const CholeskyR&, const CholeskyR&);

		std::unique_ptr<CholeskyR> friend operator-(const CholeskyR&, const CholeskyR&);

		//template<typename Function>  std::unique_ptr<CholeskyR>  operator()(Function, CholeskyR);

	private:

		// class member variables
	    	std::vector<REAL> m_l;
		std::vector<REAL> m_a;
		FDLIB_INT m_N;
		
		// private functions.

		void rand_fill( std::vector<REAL>&, const REAL, const REAL);

		void copy_vector(const std::vector<REAL>&);

		void copy_vector(REAL(*)(REAL), const std::vector<REAL>&);

		void copy_ctor(const CholeskyR&);

		void init_vector(const int, const REAL, const REAL);

		void init_vector(const int);
		
	};

	// Non member  namespace functions
	
	// Template non  - member function which applies lambda functor to CholeskyR object inline. 
	template<typename Function> std::unique_ptr<CholeskyR> apply2(Function,CholeskyR);

	template<typename Function> std::unique_ptr<CholeskyR> apply2(Function, std::vector<REAL>&);

	
	
	bool exp_dist_fill(std::vector<REAL>&, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);
	
	class CholeskyRWrapper
	{

	public:

	 static	void fdlib_chol_r( CholeskyR&);

	 static void fdlib_chol_r(std::vector<REAL>, std::vector<REAL>, FDLIB_INT);

	};

#include "lin_alg_chol_r.inl"
}
#endif /*_LIN_ALG_CHOL_R_H_*/