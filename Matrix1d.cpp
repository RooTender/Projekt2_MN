#include "Matrix1d.h"

Matrix1d::Matrix1d(int n)
{
	this->rows = 1;
	this->cols = n;

	matrix = new long double[n];
}