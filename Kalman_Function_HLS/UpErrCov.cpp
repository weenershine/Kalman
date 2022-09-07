#include "UpErrCov.h"

/*
*Updated error covariance 
  P_k=(I-K_k*H)*P-_k)
*/
void UpErrCov(float (*K)[2], float (*H)[2], float (*P)[2])
{
// P_k=(I-K_k*H)*P-_k)	
	int R1=2, C1=R1;
	int R2=C1, C2=2;
	int i,j,k;
	float P1[R1][C2];
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			P1[i][j]=0;
			for(k=0;k<C1;k++)
				P1[i][j]=P1[i][j]+K[i][k]*H[k][j];
		}	
	}
	
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			if(i==j)
				P1[i][j]=1-P1[i][j];
			else
				P1[i][j]=-P1[i][j];
			
		}	
	}
	
	float P2[R1][C2];
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			P2[i][j]=0;
			for(k=0;k<C1;k++)
				P2[i][j]=P2[i][j]+P1[i][k]*P[k][j];
		}	
	}
	
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			P[i][j]=P2[i][j];			
		}		
	}
} 
