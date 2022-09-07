#include "PreStateEst.h"

/*
*Predicted state estimate
 x_k=A*x_k-1+B*u_k-1+w_k-1
 w_k-1~N(0,Q)
    x: state vector [distance][speed]
	A: state transition matrix applied to the previous state x_k-1
	B: control-input matrix applied to the control vector u_k-1
	u: control vector
	w: the process noise vector 
	Q: the covariance of w which is zero-mean Gaussian distribution
	
*/

void Predicted_state_estimate(float *x, float (*A)[2]);
{
// x_k=A*x_k-1+B*u_k-1+w_k-1
//		state->x[0] = state->A[0][0] * state->x[0] + state->A[0][1] * state->x[1];
//		state->x[1] = state->A[1][0] * state->x[0] + state->A[1][1] * state->x[1];	
	int R1=2, C1=R1;
	int R2=C1, C2=1;
	float X[R1];
	int i,j;
	for(i=0;i<R1;i++)
	{
		X[i]=0;
		for(j=0;j<C1;j++)
			X[i]=X[i]+A[i][j]*x[j];
	}
	for(i=0;i<R1;i++)
		x[i]=X[i];	
	
}