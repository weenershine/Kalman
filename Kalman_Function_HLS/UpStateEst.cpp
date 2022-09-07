#include "UpStateEst.h"

/*
*Updated state estimate
  x_k=x-_k+K_k*y~_k
*/


void UpStateEst(float (*K)[2], float *x, float *y)
{
//x_k=x-_k+K_k*y~_k
	int R1=2, C1=R1;
	int R2=C1, C2=2;
	int i,j;
	float X[R1];
	for(i=0;i<R1;i++)
	{
		X[i]=0;
		for(j=0;j<C1;j++)
			X[i]=X[i]+K[i][j]*y[j];
	}
	
	for(i=0;i<R1;i++)
		x[i]=x[i]+X[i];

}