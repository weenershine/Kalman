#include "KalGain.h"

void KalGain(float (*H)[2], float (*P)[2], float (*R)[2], float (*K)[2])
{
// K_k=P-_k*H'/(R+H*P-_k*H')
	int R=2, C=R;
	
	float HT[R][C];
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			HT[j][i]=H[i][j];
		
	float K1[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			K1[i][j]=0;
			for(int k=0;k<C1;k++)
				K1[i][j]=K1[i][j]+P[i][k]*HT[k][j];		
		}		
	}
	
	float K2[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			K2[i][j]=0;
			for(k=0;k<C1;k++)
				K2[i][j]=K2[i][j]+H[i][k]*K1[k][j];		
		}	
	}
	
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			K2[i][j]=R[i][j]+K2[i][j];
		
    Inverse_matrix(K2);
	
	float K3[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			K3[i][j]=0;
			for(k=0;k<C1;k++)
				K3[i][j]=K3[i][j]+K1[i][k]*K2[k][j];
		}	
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			K[i][j]=K3[i][j];			
		}		
	}
} 