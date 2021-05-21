/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : 21600336 ¹é½ÂÈÆ
Modified         : 15-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.h
----------------------------------------------------------------*/

#ifndef		_MY_NM_H		// use either (#pragma once) or  (#ifndef ...#endif)
#define		_MY_NM_H

#include "myMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//For differentiation

double IntegrateRect(double _x[], double _y[], int _m);

double trap(double _x[], double _y[], int _m);

double integral(double func(const double x), double a, double b, int n);

double myFunc(const double x);



// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);

#endif