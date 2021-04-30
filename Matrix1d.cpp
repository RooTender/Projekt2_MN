#include "Matrix1d.h"

Matrix1d::Matrix1d(int n)
{
	this->rows = 1;
	this->cols = n;

	matrix = new long double[n];
}

Matrix1d::Matrix1d(const Matrix1d& M) : Matrix1d(M.size())
{
	for (int i = 0; i < this->size(); ++i) {
		this->matrix[i] = M.matrix[i];
	}
}

Matrix1d Matrix1d::operator=(const Matrix1d& M)
{
	for (int i = 0; i < this->size(); ++i) {
		this->matrix[i] = M.matrix[i];
	}
	return *this; // copy constructor not working! Use *this!
}

Matrix1d Matrix1d::operator-(Matrix1d M)
{
	for (int i = 0; i < this->size(); ++i) {
		M.matrix[i] = this->matrix[i] - M.matrix[i];
	}

	return Matrix1d(M);
}

Matrix1d::~Matrix1d()
{
	delete[] matrix;
}
