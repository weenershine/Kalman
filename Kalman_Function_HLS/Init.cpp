#include "Init.h"

/*
@inputs  
 x: state vector [distance][speed]
 A: state transition matrix
 //B: control-input matrix
 //u: control vector
 H: measurement matrix
 Q: w~N(0,Q)
 R: v~N(0,R)
 P: intial state error covariance
*/

void Init(kalman_state *state, float *init_x, float *init_A, float *init_H, float *init_Q, float *init_R, float *init_P)
{
	state->x[0]    = init_x[0];
    state->x[1]    = init_x[1];
	
	//state->A       = {{1, 1}, {0, 1}};
    state->A[0][0] = init_A[0][0];
    state->A[0][1] = init_A[0][1];
    state->A[1][0] = init_A[1][0];
    state->A[1][1] = init_A[1][1];
	
	//state->H       = {{1,0},{0,1}};
    state->H[0][0] = init_H[0][0];
    state->H[0][1] = init_H[0][1];
    state->H[1][0] = init_H[1][0];
    state->H[1][1] = init_H[1][1];
	
	//state->Q       = {{0.1,0},{0,0.1}};  /* estimated noise convariance */
    state->Q[0][0] = init_Q[0][0];
    state->Q[0][1] = init_Q[0][1];
    state->Q[1][0] = init_Q[1][0];
    state->Q[1][1] = init_Q[1][1];
	
	//state->R       = {{1,0},{0,1}};  /* measure noise convariance */
	state->R[0][0] = init_R[0][0];
    state->R[0][1] = init_R[0][1];
    state->R[1][0] = init_R[1][0];
    state->R[1][1] = init_P[1][1];
	
	//state->P
    state->P[0][0] = init_P[0][0];
    state->P[0][1] = init_P[0][1];
    state->P[1][0] = init_P[1][0];
    state->P[1][1] = init_P[1][1];
	
}