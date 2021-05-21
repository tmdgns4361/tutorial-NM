/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : 21600336 ¹é½ÂÈÆ
Modified         : 15-05-2021
Language/ver     : C++ in MSVS2019

Description      : myNM.cpp

 Assignment: Curve Fitting and Interpolation
----------------------------------------------------------------*/

#include "myNM.h"


// Integration using rectangular method for discrete data inputs


// Create a matrix from 1D-array
Matrix	arr2Mat(double* _1Darray, int _rows, int _cols)
{
	Matrix Output = createMat(_rows, _cols);
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _cols; j++)
			Output.at[i][j] = _1Darray[i * _cols + j];

	return Output;
}