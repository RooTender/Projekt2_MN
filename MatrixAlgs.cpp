#include "MatrixAlgs.h"

long double MatrixAlgs::norm(const Matrix1d& res)
{
    long double result = 0;
    for (int i = 0; i < res.size(); ++i) {
        result += res.matrix[i] * res.matrix[i];
    }

    return sqrtl(result);
}

long double MatrixAlgs::jacobi(const Matrix2d& A, Matrix1d& x, const Matrix1d& b, long double limit, int& iterations)
{
    iterations = 0;
    int upperLimit = b.size();

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

    } while (!(norm(res) < limit) && ++iterations < upperLimit);

    return (iterations < upperLimit) ? norm(res) : 0;
}

long double MatrixAlgs::gaussSeidl(const Matrix2d& A, Matrix1d& x, const Matrix1d& b, long double limit, int& iterations)
{
    iterations = 0;
    int upperLimit = b.size();

    Matrix1d res = Matrix1d(x.size());

    do {
        for (int i = 0; i < A.rows; ++i) {
            x.matrix[i] = b.matrix[i];

            for (int j = 0; j < A.cols; ++j) {
                if (j == i) continue;

                x.matrix[i] -= A.matrix[i][j] * x.matrix[j];
            }
            x.matrix[i] /= A.matrix[i][i];
        }

        res = A * x - b;

    } while (!(norm(res) < limit) && ++iterations < upperLimit);

    return (iterations < upperLimit) ? norm(res) : 0;
}
