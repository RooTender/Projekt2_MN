#include "MatrixAlgs.h"

long double MatrixAlgs::norm(const Matrix1d& res)
{
    long double result = 0;
    for (int i = 0; i < res.size(); ++i) {
        result += res.matrix[0] * res.matrix[i];
    }

    return sqrtl(result);
}

bool MatrixAlgs::jacobi(const Matrix2d& A, const Matrix1d& b, Matrix1d& x, long double limit)
{
    int iterator = 0;
    int upperLimit = 10000;

    Matrix1d res = Matrix1d(x.size());
    do {
        Matrix1d xNew = x;
        for (int i = 0; i < A.rows; ++i) {
            
            xNew.matrix[i] = b.matrix[i];
            for (int j = 0; j < A.cols; ++j) {
                if (j == i) continue;

                xNew.matrix[i] -= A.matrix[i][j] * x.matrix[j];
            }
            xNew.matrix[i] /= A.matrix[i][i];
        }
        
        x = xNew;
        res = A * x - b;

    } while (!(norm(res) < limit) && ++iterator < upperLimit);

    return (iterator < upperLimit) ? true : false;
}

bool MatrixAlgs::gaussSeidl(const Matrix2d& A, const Matrix1d& b, Matrix1d& x, long double limit)
{
    return false;
}
