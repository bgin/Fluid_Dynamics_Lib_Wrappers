#ifndef _LIN_ALG_DET_HESS_L_H_
#define _LIN_ALG_DET_HESS_L_H_


#include "F77_lin_alg_defs.h"
#include "StatDistributionWrapper.h"

namespace fdlibcppwrapper
{

	class DetHessL
	{
	public:

		// Constructors

		// Ctor filled with random numbers.
		DetHessL(const int n);

		// Ctor from user passed std::vector
		DetHessL(const std::vector<REAL>&);

		// Copy-Ctor
		DetHessL(const DetHessL&);


		// Dtor
		~DetHessL();



	private:

		std::vector<REAL> m_a;
		REAL det;
		FDLIB_INT n;
	};








	class DetHesLWrapper
	{

	};
}
#endif /*_LIN_ALG_DET_HESS_L_H_*/