#pragma once
#include <math.h>
#include "Matrix2d.h"
#include "Matrix1d.h"

namespace MatrixAlgs
{
	long double norm(const Matrix1d& res);
	bool jacobi(const Matrix2d& A, const Matrix1d& b, Matrix1d& x, long double limit);
	bool gaussSeidl(const Matrix2d& A, const Matrix1d& b, Matrix1d& x, long double limit);
};

