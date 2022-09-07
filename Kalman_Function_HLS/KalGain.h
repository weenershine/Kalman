#ifndef  _KALMAN_FILTER_H
#define  _KALMAN_FILTER_H


#include "ap_fixed.h"

typedef ap_int<8> int8


void KalGain(float (*H)[2], float (*P)[2], float (*R)[2], float (*K)[2]);