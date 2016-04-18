
#ifndef _LINEAR_ALGEBRA_H_
#define _LINEAR_ALGEBRA_H_
#include "LibDefs.h"
 // Definition of F77 subroutines "ported" to C representation

#if defined __cplusplus
extern "C"
{
	// chol_c(l,a,n) subroutine.
	void CHOL_C(double *, double *, FDLIB_INT *);

	// chol_r(l,a,n) subroutine
	void CHOL_R(double *, double *, FDLIB_INT  *);

	//TO DO
	// CHANGE FUNCTIONS NAMES TO UPPERCASE in order to be linked. DONE!!
	// det_hess_l(n,a,det)
	void DET_HESS_L(FDLIB_INT *, double *, double *);

	// det_hess_u(n,a,det)
	void DET_HESS_U(FDLIB_INT *, double *, double *);

	// Det_33c(AR,AI,DetR,DetI)
	void DET_33C(double *, double *, double *, double *);

	// Det_44c(AR,AI,DetR,DetI)
	void DET_44C(double *, double *, double *, double *);

	// inv_l(n,a,b)
	void INV_L(FDLIB_INT *, double *, double *);

	// inv_u(n,a,b)
	void INV_U(FDLIB_INT *, double *, double *);

	// ldu(n,a,l,d,u)
	void LDU(FDLIB_INT *, double *, double *, double *, double *);

	// crout(n,a,l,u)
	void CROUT(FDLIB_INT *, double *, double *, double *);

	// lu_d_t(n,c,a,b,l,u)
	void LU_D_T(FDLIB_INT *, double *, double *, double *, double *, double *);

	// qr_gs(a,n,index,q,r)
	void QR_GS(double *, FDLIB_INT *, FDLIB_INT *, double *, double *);

	// QR_REFLEX(a,n,q,r)
	void QR_REFLEX(double *, FDLIB_INT *, double *, double *);

	// QR_ROT(a,n,q,r)
	void QR_ROT(double *, FDLIB_INT *, double *, double *);
}
#endif
#endif /*_LINEAR_ALGEBRA_H_*/