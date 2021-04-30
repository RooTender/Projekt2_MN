#pragma once
#include <math.h>
#include "Matrix2d.h"
#include "Matrix1d.h"

class MatrixAlgs
{
private:
	long double norm(Matrix1d& const res);
	bool isSymmetric(Matrix2d& const M);

public:
	bool jacobi(Matrix2d const& A, Matrix1d const& b, Matrix1d& x, long double limit);
	bool gaussSeidl(Matrix2d const& A, Matrix1d const& b, Matrix1d& x, long double limit);

};

