#include "MeaResi.h"

/*
*Measurement residual
 y~_k=z_k-H*x_k
    y~: the difference between the true measurement z_k, and the estimated measurement H*x_k	
    (z_k=H*x_k+v_k, v_k~N(0,R))
	z: measurement vector
	H: measurement matrix
	R: the covariance of v which is zero-mean Gaussian distribution
*/

void MeaResi(float (*H)[2], float *x, float *z_mes, float *y)
{// y~_k=z_k-H*x_k	
	int Rz=2, Rx=2;
	int CH=Rx, RH=Rz;
	float ze[Rz];
	int i,j;
	for(i=0;i<Rz;i++)
	{
		ze[i]=0;
		for(j=0;j<Rx;j++)
			ze[i]=ze[i]+H[i][j]*x[j];
	}
	
	for(i=0;i<Rz;i++)
		y[Rz]=z_mes[i]-ze[i];	
	
}