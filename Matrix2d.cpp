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

Matrix2d Matrix2d::transpose(Matrix2d M)
{
	for (int i = 0; i < M.cols; ++i) {
		for (int j = 0; j < i; ++j) {
			
			// swap algorithm
			auto tmp = M.matrix[i][j];
			M.matrix[i][j] = M.matrix[j][i];
			M.matrix[j][i] = tmp;
		}
	}

	return M;
}
