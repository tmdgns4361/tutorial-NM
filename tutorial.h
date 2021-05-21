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
Matrix	gradient(Matrix _x, Matrix _y);

void gradient1D(double x[], double y[], double dydx[], int _m);

Matrix  gradientFunc(double func(const double x), Matrix _x);

double myFunc(const double x);

double mydFunc(const double x);

double newtonRahpsonFunc(double func(const double x), double dfunc(const double x), float x0, float tol);


// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols);

#endif