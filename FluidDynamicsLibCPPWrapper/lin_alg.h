
#ifndef _LIN_ALG_H_
#define _LIN_ALG_H_

//#include <immintrin.h>
#include <memory>
#include <numeric>
#include <stdlib.h>
#include "F77_lin_alg_defs.h"
#include "StatDistributionWrapper.h"

namespace fdlibcppwrapper
{

	class CholeskyC
	{
		
	public:

		CholeskyC();
		// Initialized by the call to statistical distribution functions.
		CholeskyC(const int);

		//random fill by the call to HW RDRAND.
		CholeskyC( int, const REAL, const REAL);

		//Construct from user passed vectors.
		CholeskyC(const std::vector<REAL>&);

		//Copy Constructor.
		CholeskyC(const CholeskyC&);

		~CholeskyC();

		// Getters/Setters:
		void set_m_l(std::vector<REAL>&);

		std::vector<REAL> get_m_a() const;

		std::vector<REAL> get_m_l() const;

		FDLIB_INT get_m_N() const;

		// member function delegates which call statistical distribution functions.

		__forceinline  bool uni_real_distr_fill(const double, const double, const int);

		__forceinline  bool exp_distr_fill(const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool gamma_distr_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool weibull_distr_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool extr_val_distr_fill(const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool norm_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool lognorm_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool chisquared_distr_fill(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool cauchy_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool fisher_distr_fill(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		__forceinline  bool student_distr_fill(const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		// friend operators:
		std::unique_ptr<CholeskyC> friend operator+(const CholeskyC&, const CholeskyC&);

		std::unique_ptr<CholeskyC> friend operator-(const CholeskyC&, const CholeskyC&);

		std::unique_ptr<CholeskyC> friend operator*(const CholeskyC&, const CholeskyC&);

		// Friend functions called with lambda argument.
	  	template<typename _Function> friend std::unique_ptr<CholeskyC>  apply_functor(_Function, CholeskyC);

		template<typename _Function> friend std::unique_ptr<CholeskyC>  apply_functor(_Function, std::vector<REAL>&);

		//member operators:
		CholeskyC & operator=(const CholeskyC&);

		CholeskyC & operator+=(const CholeskyC&);

		CholeskyC & operator-=(const CholeskyC&);

		CholeskyC & operator*=(const CholeskyC&);

		

		//inner class for holding the results of FP comparison.
		class ArrayEquality
		{
		public:
			std::vector<bool> vec_m_a;
			std::vector<bool> vec_m_l;
		};

		ArrayEquality  operator==(const CholeskyC&);

		ArrayEquality  operator!=(const CholeskyC&);

		
		// Function pointers to statistical distribution class member functions.
		// Normal distribution functions
		using PTR_UD = bool(CholeskyC::*)(const double, const double, const int);

		using PTR_ND1 = bool(CholeskyC::*)( const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);
		using PTR_ND2 = bool(CholeskyC::*)(const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);
		
		// Poisson distribution functions.
		using PTR_PD1 = bool(CholeskyC::*)( const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);
		using PTR_PD2 = bool(CholeskyC::*)( const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		// overloaded operators call which provide random fill methods for CholeskyC objects.

		CholeskyC & operator()(CholeskyC *, PTR_UD, const double, const double, const int);

		CholeskyC & operator()(CholeskyC *, PTR_ND1, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		CholeskyC & operator()(CholeskyC *, PTR_ND2, const double, const double, fdlibcppwrapper::NormalDistributionImpl<double>::RandomNumberEngines);

		CholeskyC & operator()(CholeskyC *, PTR_PD1, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		CholeskyC & operator()(CholeskyC *, PTR_PD2, const double, const double, fdlibcppwrapper::PoissonDistributionImpl<double>::RandomNumberEngines);

		template<typename _Function> std::unique_ptr<CholeskyC>  apply(_Function, CholeskyC);


#if defined (_DEBUG)
		void debug_print();
		bool print_to_file(const char *);
		//void debug_print(const CholeskyC&);
#endif
	private:

	 	std::vector<REAL> m_a;
		 std::vector<REAL> m_l;
		FDLIB_INT m_N;

		void init_vector(const int);

		void rand_fill( std::vector<REAL>&, const REAL, const REAL);
	};


	

	class CholeskyCWrapper
	{
	public:

	  static	void fdlib_chol_c( CholeskyC&);

	  static    void fdlib_chol_c(std::vector<REAL>&, std::vector<REAL>&, FDLIB_INT);
	};
	      
#include "lin_alg.inl"	

}
#endif /*_LIN_ALG_H_*/