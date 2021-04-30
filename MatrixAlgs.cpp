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
    int iterator = 0;

    Matrix1d res = Matrix1d(x.size());
    do {
        Matrix1d xOld = x;
        for (int i = 0; i < x.size(); ++i) {
            
            x.matrix[i] = b.matrix[i];
            for (int j = 0; j < x.size(); ++j) {
                if (j == i) continue;

                x.matrix[i] -= A.matrix[i][j] * xOld.matrix[j];
            }
            x.matrix[i] /= A.matrix[i][i];
        }

        res = A * x - b;
    } while (norm(res) < limit && ++iterator < (x.size() * x.size()));

    return (iterator < (x.size() * x.size())) ? true : false;
}

bool MatrixAlgs::gaussSeidl(Matrix2d& A, Matrix1d const& b, Matrix1d& x, long double limit)
{
    return false;
}
