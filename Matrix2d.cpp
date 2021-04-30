#include "Matrix2d.h"

Matrix2d::Matrix2d(int n)
{
	this->rows = n;
	this->cols = n;

	matrix = new long double* [n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new long double[n];
	}
}

void Matrix2d::generateValues(int a1, int a2, int a3)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {

			switch (abs(i - j)) {
			case 0:
				matrix[i][j] = a1;
				break;

			case 1:
				matrix[i][j] = a2;
				break;

			case 2:
				matrix[i][j] = a3;
				break;

			default:
				matrix[i][j] = 0;
				break;
			}
		}
	}
}

Matrix2d Matrix2d::transpose()
{
	Matrix2d trM(*this);

	for (int i = 0; i < this->cols; ++i) {
		for (int j = 0; j < i; ++j) {
			
			// swap algorithm
			auto tmp = trM.matrix[i][j];
			trM.matrix[i][j] = trM.matrix[j][i];
			trM.matrix[j][i] = tmp;
		}
	}

	return trM;
}

Matrix1d Matrix2d::operator*(Matrix1d& const M) const
{
	Matrix1d A(M);
	for (int i = 0; i < this->rows; ++i) {
		A.matrix[i] = 0;

		for (int j = 0; j < this->cols; ++j) {
			A.matrix[i] += this->matrix[i][j] * M.matrix[j];
		}
	}

	return A;
}

Matrix2d::~Matrix2d()
{
	for (int i = 0; i < this->rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
