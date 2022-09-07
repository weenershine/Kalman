#include "PreErrCov.h"

/*
*Predicted error covariance
 P-_k=A*P_k-1*A'+Q
    P-: predicted error covariance
	P: updated state error covariance
	It encrypts the error covariance that the filter thinks the estimate error has.
*/

void PreErrCov(float (*A)[2], float (*Q)[2], float (*P)[2])
{
// P-_k=A*P_k-1*A'+Q
//    state->p[0][0] = state->A[0][0] * state->p[0][0] + state->A[0][1] * state->p[1][0] + state->q[0];
//    state->p[0][1] = state->A[0][0] * state->p[0][1] + state->A[1][1] * state->p[1][1];
//    state->p[1][0] = state->A[1][0] * state->p[0][0] + state->A[0][1] * state->p[1][0];
//    state->p[1][1] = state->A[1][0] * state->p[0][1] + state->A[1][1] * state->p[1][1] + state->q[1];	
	int R1=2, C1=R1;
	int R2=C1, C2=2;
	float P1[R1][C2];
	int i,j,k;
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			P1[i][j]=0;
			for(k=0;k<C1;k++)
				P1[i][j]=P1[i][j]+A[i][k]*P[k][j];		
		}	
	}
	
	float AT[R1][C1];
	for(i=0;i<R1;i++)
		for(j=0;j<C1;j++)
			AT[j][i]=A[i][j];
		
	float P2[R1][C2];
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C2;j++)
		{
			P2[i][j]=0;
			for(k=0;k<C1;k++)
				P2[i][j]=P2[i][j]+P1[i][k]*AT[k][j];		
		}	
	}
	
	for(i=0;i<R1;i++)
	{
		for(j=0;j<C1;j++)
		{
			P[i][j]=P2[i][j]+Q[i][j];			
		}	
	}
	
}