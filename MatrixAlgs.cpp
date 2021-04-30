#include "MatrixAlgs.h"

long double MatrixAlgs::norm(Matrix1d& const res)
{
    long double result = 0;
    for (int i = 0; i < res.size(); ++i) {
        result += res.matrix[0] * res.matrix[i];
    }

    return sqrtl(result);
}

bool MatrixAlgs::isSymmetric(Matrix2d& const M)
{
    Matrix2d MT = M.transpose();

    return true;
}
