#pragma once
#include <math.h>
#include "Matrix2d.h"
#include "Matrix1d.h"

class MatrixAlgs
{
private:
	long double norm(Matrix1d& const res);

public:
	bool jacobi(Matrix2d& A, Matrix1d const& b, Matrix1d& x, long double limit);
	bool gaussSeidl(Matrix2d& A, Matrix1d const& b, Matrix1d& x, long double limit);

};

