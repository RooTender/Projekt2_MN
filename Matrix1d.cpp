#include "Matrix1d.h"

Matrix1d::Matrix1d(int n)
{
	this->rows = 1;
	this->cols = n;

	matrix = new long double[n];
}

Matrix1d Matrix1d::operator-(Matrix1d const M)
{
	for (int i = 0; i < this->size(); ++i) {
		M.matrix[i] = this->matrix[i] - M.matrix[i];
	}

	return M;
}

Matrix1d::~Matrix1d()
{
	delete[] matrix;
}
