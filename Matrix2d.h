#pragma once
#include "Matrix.h"

class Matrix2d : public Matrix
{
public:
	long double** matrix;

	Matrix2d(int n);

	void generateValues(int a1, int a2, int a3);
	Matrix2d transpose();

	~Matrix2d();
};