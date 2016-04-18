
#ifndef _F77_LIN_ALG_DEF_H_
#define _F77_LIN_ALG_DEF_H_

#include "LibDefs.h"

#if defined __cplusplus
extern "C"
{

	// chol_c(l,a,n) subroutine.
	void CHOL_C(double *, double *, FDLIB_INT *);

	// chol_r(l,a,n) subroutine
	 void CHOL_R(double *, double *, FDLIB_INT  *);

   //  det_hess_l(n,a,det)
	 void DET_HESS_L(FDLIB_INT *, double *, double *);

	 // det_hess_u(n,a,det)
	 void DET_HESS_U(FDLIB_INT *, double *, double *);


}
#endif
#endif  /*_F77_LIN_ALG_DEF_H_*/