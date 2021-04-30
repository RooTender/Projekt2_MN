#include "MatrixAlgs.h"

long double MatrixAlgs::norm(Matrix1d& const res)
{
    long double result = 0;
    for (int i = 0; i < res.size(); ++i) {
        result += res.matrix[0] * res.matrix[i];
    }

    return sqrtl(result);
}

bool MatrixAlgs::jacobi(Matrix2d& A, Matrix1d const& b, Matrix1d& x, long double limit)
{

    return true;
}

bool MatrixAlgs::gaussSeidl(Matrix2d& A, Matrix1d const& b, Matrix1d& x, long double limit)
{
    return false;
}
