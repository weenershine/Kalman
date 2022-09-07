#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H


#include "ap_fixed.h"

typedef ap_int<8> int8



void PreErrCov(float (*A)[2], float (*Q)[2], float (*P)[2]);