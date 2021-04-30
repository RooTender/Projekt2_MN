#pragma once
#include "Matrix.h"

class Matrix2d : protected Matrix
{
public:
	long double** matrix;

	Matrix2d(int n);
	void generateValues(int a1, int a2, int a3);
};