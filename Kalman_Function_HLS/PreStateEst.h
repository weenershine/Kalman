#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H


#include "ap_fixed.h"

typedef ap_int<8> int8

//typedef struct {
//    float x[2];     /* state: [0]-Location [1]-Speed, 2x1 */
//    float A[2][2];  /* X(n)=A*X(n-1)+B*U(n-1)+W(n),W(n)~N(0,Q), 2x2 */
//    float H[2][2];     /* Z(n)=H*X(n)+V(n),V(n)~N(0,R), 2x2   */
//    float Q[2][2];     /* process(predict) noise convariance,2x2 [q0,0; 0,q1] */
//    float R[2][2];     /* measure noise convariance,2x2 [r0,0; 0,r1]  */
//    float P[2][2];  /* estimated error convariance,2x2 [p0 p1; p2 p3] */
//    float K[2];  /* 2x1 */
//} kalman_state; 

void PreStateEst(float *x, float (*A)[2]);