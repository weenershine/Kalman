#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H


#include "ap_fixed.h"

typedef ap_int<8> int8



void MeaResi(float (*H)[2], float *x, float *z_mes, float *y);