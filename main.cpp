#include <iostream>
#include <chrono> // Function for measuring time
#include "Matrix1d.h"
#include "Matrix2d.h"
#include "MatrixAlgs.h"

#pragma region Miscellaneous
// Returns power of a number as int
int powInt(int const& base, int exponent)
{
	int result = 1;
	while (exponent--)
		result *= base;

	return result;
}

// Returns digit of number at given position (1, n)
int nPos(int number, int position) {
	int length = 0;
	int tmp = number;
	while (tmp) {
		tmp /= 10;
		length++;
	}

	return number / powInt(10, length - position) % 10;
}
#pragma endregion

inline long double bFunction(int i, long double arg) {
	return sinl((long double)i * (arg + 1));
}

template<typename func>
void analyzeIterativeFunction(const char* methodUsed, func function, Matrix2d& A, Matrix1d& x, Matrix1d& b, long double limit) {
	
	int iterations = 0;

	auto start = std::chrono::high_resolution_clock::now();
	long double norm = function(A, x, b, limit, iterations);
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	std::cout << methodUsed << std::endl;
	std::cout << "  Elapsed time: " << duration.count() << "ms" << std::endl;
	std::cout << "  Iterations: " << iterations << std::endl;
	std::cout << "  Norm: " << norm << std::endl;

	if (norm == 0) {
		std::cout << "  This method doesn't coincide with to solution for given data!" << std::endl;
	}

	std::cout << std::endl;
}

template<typename func>
void analyzeDirectFunction(const char* methodUsed, func function, Matrix2d& A, Matrix1d& x, Matrix1d& b) {

	auto start = std::chrono::high_resolution_clock::now();
	long double norm = function(A, x, b);
	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

	std::cout << methodUsed << std::endl;
	std::cout << "  Elapsed time: " << duration.count() << "ms" << std::endl;
	std::cout << "  Norm: " << norm << std::endl;
	std::cout << std::endl;
}

int main() {
	
	// ZADANIE A
	int const transcript = 180348;
	int const N = 900 + nPos(transcript, 5) * 10 + nPos(transcript, 6);

	Matrix2d A = Matrix2d(N);
	Matrix1d x = Matrix1d(N);
	Matrix1d b = Matrix1d(N);

	A.generateValues(5 + nPos(transcript, 4), -1, -1);
	b.generateValues(bFunction, nPos(transcript, 3));


	// ZADANIE B
	std::cout << "ZADANIE B" << std::endl;

	x.fill(1);
	analyzeIterativeFunction("Jacobi method", MatrixAlgs::jacobi, A, x, b, powl(10, -9));

	x.fill(1);
	analyzeIterativeFunction("Gauss-Seidl method", MatrixAlgs::gaussSeidl, A, x, b, powl(10, -9));


	// ZADANIE C
	std::cout << std::endl << "ZADANIE C" << std::endl;

	A.generateValues(3, -1, -1);

	x.fill(1);
	analyzeIterativeFunction("Jacobi method", MatrixAlgs::jacobi, A, x, b, powl(10, -9));

	x.fill(1);
	analyzeIterativeFunction("Gauss-Seidl method", MatrixAlgs::gaussSeidl, A, x, b, powl(10, -9));


	// ZADANIE D
	std::cout << std::endl << "ZADANIE D" << std::endl;

	analyzeDirectFunction("LU decomposition method", MatrixAlgs::LUDecomposition, A, x, b);

	
	// ZADANIE E
	std::cout << std::endl << "ZADANIE E" << std::endl;

	int arr[] = { 100, 500, 1000, 2000, 3000 };
	for (int n : arr) {

		std::cout << "N = " << n << std::endl;

		Matrix2d A = Matrix2d(n);
		Matrix1d x = Matrix1d(n);
		Matrix1d b = Matrix1d(n);

		A.generateValues(5 + nPos(transcript, 4), -1, -1);
		b.generateValues(bFunction, nPos(transcript, 3));

		x.fill(1);
		analyzeIterativeFunction("Jacobi method", MatrixAlgs::jacobi, A, x, b, powl(10, -9));

		x.fill(1);
		analyzeIterativeFunction("Gauss-Seidl method", MatrixAlgs::gaussSeidl, A, x, b, powl(10, -9));

		analyzeDirectFunction("LU decomposition method", MatrixAlgs::LUDecomposition, A, x, b);
	}

}