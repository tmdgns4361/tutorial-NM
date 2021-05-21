/*-------------------------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : [YOUR NAME]
Created          : 17-05-2021
Modified         : 17-05-2021
Language/ver     : C++ in MSVS2019

Description      : [Tutorial]Integration_student.cpp
-------------------------------------------------------------------------------*/

#include "../../include/myMatrix.h"
#include "../../include/myNM.h"
#include "math.h"


double integralMid(double x[], double y[], int m);

double integral38(double func(const double x), double a, double b, int n);

int main(int argc, char* argv[])
{
	// PART 1. Integration from Datasets
	printf("\n**************************************************");
	printf("\n        PART 1. Integration from Datasets         ");
	printf("\n**************************************************\n");

	double x[] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60 };
	double y[] = { 0, 3, 8, 20, 33, 42, 40, 48, 60, 12, 8, 4, 3 };
	int M = sizeof(x) / sizeof(x[0]);
	double I_rect = IntegrateRect(x, y, M);
	printf("I_rect  = %f\n", I_rect);

	double I_mid = 0;
	I_mid = integralMid(x, y, M);
	printf("I_mid = %f\n\n", I_mid);

	// PART 2. Integration from a Function
	//printf("\n**************************************************");
	//printf("\n        PART 2. Integration from a Function       ");
	//printf("\n**************************************************\n");
	//
	//double I_simpson38 = 0;
	//double a = -1.0;
	//double b = 1.0;
	//int n = 12;
	//I_simpson38 = integral38(myFunc, a, b, n);
	//printf("I_simpson13  = %f\n", I_simpson38);

	system("pause");
	return 0;
}

// Define a function that defines the target equation.
double myFunc(const double x) {
	return  sqrt(1- x * x);
}

double integralMid(double _x[], double _y[], int _m) {
	int N = _m - 1;
	double I = 0;
	for (int i = 0; i < N; i++)
		I += (0.5)*(_y[i]+_y[i+1])*(_x[i + 1] - _x[i]);
	return I;
}

//double integral38(double func(const double x), double a, double b, int n) {
//
//}

double IntegrateRect(double _x[], double _y[], int _m) {
	int N = _m - 1;
	double I = 0;
	for (int i = 0; i < N; i++)
		I += _y[i] * (_x[i + 1] - _x[i]);

	return I;
}

// Integration using trapezodidal method for discrete data inputs
double trap(double _x[], double _y[], int _m) {
	int N = _m - 1;
	double I = 0.0;
	for (int i = 0; i < N; i++) {
		I = I + (_y[i] + _y[i + 1]) * (_x[i + 1] - _x[i]);
	}
	I = (0.5) * I;
	return I;
}

double integral(double func(const double x), double a, double b, int n) {
	double h = (b - a) / n;
	double odd_I = 0.0;
	double even_I = 0.0;
	double total_I = 0.0;
	total_I = func(a) + func(b);
	for (int i = 1; i < n; i++) {
		a = a + h;
		if ((i % 2) == 1) {
			odd_I = odd_I + func(a);
		}
		if ((i % 2) == 0) {
			even_I = even_I + func(a);
		}
	}
	a = a + h;
	total_I = (h / 3) * (total_I + 4 * odd_I + 2 * even_I);

	return total_I;
}


