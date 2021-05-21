/*----------------------------------------------------------------\
@ Numerical Methods by Young-Keun Kim - Handong Global University

Author           : 21600336 ¹é½ÂÈÆ
Modified         : 15-05-2021
Language/ver     : C++ in MSVS2019

Description      : myMatrix.cpp
----------------------------------------------------------------*/

#include "myMatrix.h"
#include "myNM.h"
#include <stdio.h>
#include <math.h> 

// Create Matrix with specified size
Matrix	createMat(int _rows, int _cols)
{
	// check matrix dimension
	if (_rows < 0 || _cols < 0) {
		printf("\n****************************************************");
		printf("\n  ERROR!!: dimension error at 'createMat' function");
		printf("\n****************************************************\n");
		return createMat(0, 0);
	}		

	Matrix Out;
	// 1. Allocate row array first
	Out.at = (double**)malloc(sizeof(double*) * _rows);
	// 2. Then, allocate column 
	for (int i = 0; i < _rows; i++)
		Out.at[i] = (double*)malloc(sizeof(double) * _cols);
	// 3. Initialize row & column values of a matrix
	Out.rows = _rows;
	Out.cols = _cols;

	return Out;
}

// Free a memory allocated matrix
void	freeMat(Matrix _A)
{
	// 1. Free allocated column memory
	for (int i = 0; i < _A.rows; i++)
		free(_A.at[i]);
	// 2. Free allocated row memory
	free(_A.at);
}

// Create a matrix from a text file
Matrix	txt2Mat(std::string _filePath, std::string _fileName)
{
	std::ifstream file;
	std::string temp_string, objFile = _filePath + _fileName + ".txt";
	int temp_int = 0, nRows = 0;

	file.open(objFile);
	if (!file.is_open()) {
		printf("\n*********************************************");
		printf("\n  Could not access file: 'txt2Mat' function");
		printf("\n*********************************************\n");
		return createMat(0, 0);
	}
	while (getline(file, temp_string, '\t'))
		temp_int++;
	file.close();

	file.open(objFile);
	while (getline(file, temp_string, '\n'))
		nRows++;
	file.close();

	int nCols = (temp_int - 1) / nRows + 1;
	Matrix Out = createMat(nRows, nCols);

	file.open(objFile);
	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++) {
			file >> temp_string;
			Out.at[i][j] = stof(temp_string);
		}
	file.close();

	return Out;
}

// Print matrix
void	printMat(Matrix _A, const char* _name)
{
	printf("%s =\n", _name);
	for (int i = 0; i < _A.rows; i++) {
		for (int j = 0; j < _A.cols; j++)
			printf("%15.6f\t", _A.at[i][j]);
		printf("\n");
	}
	printf("\n");
}

// initialization of Matrix elements
void	initMat(Matrix _A, double _val)
{
	for (int i = 0; i < _A.rows; i++)
		for (int j = 0; j < _A.cols; j++)
			_A.at[i][j] = _val;
}

// Create matrix of all zeros
Matrix	zeros(int _rows, int _cols)
{
	Matrix Out = createMat(_rows, _cols);
	initMat(Out, 0);
	return Out;
}

Matrix eye(int _rows, int _cols)
{
	Matrix out = createMat(_rows, _cols);
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			if (i == j)
				out.at[i][j] = 1;
			else
				out.at[i][j] = 0;
		}
	}
	return out;
}

void	copyMat(Matrix _A, Matrix out)
{
	for (int x = 0; x < _A.rows; x++) {
		for (int y = 0; y < _A.cols; y++)
			out.at[x][y] = _A.at[x][y];
	}

}

double norm(Matrix _vec) {
    int n = _vec.rows;;
    double out = 0; 
    for (int i =0; i < n; i++) {
        out +=  _vec.at[i][0]* _vec.at[i][0];
    }
    out = sqrt(out);
    return out; 
}

Matrix	transpose(Matrix _A) {
    int r = _A.rows;
    int c = _A.cols;
   
    double exchang = 0 ;
    Matrix out = zeros(c, r);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (i == j)
                out.at[i][j] = _A.at[i][j];
            else {
                out.at[i][j] = _A.at[j][i];
            }
        }
    }
    return out;
}

double func_curvefit_line(double _x, double _a0, double _a1) {

    return _a0 + _a1 * _x;
}

double func_interpolation_line(double _x, double _y1, double _y2, double _x1, double _x2) {

	return _y1 * ((_x - _x2) / (_x1 - _x2)) + _y2 * ((_x - _x1) / (_x2 - _x1));
}
