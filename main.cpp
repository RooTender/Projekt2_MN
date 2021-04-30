#include <iostream>
#include "Matrix1d.h"
#include "Matrix2d.h"

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

long double bFunction(int i, long double arg) {
	return sinl((long double)i * (arg + 1));
}

int main() {
	int const transcript = 180348;
	int const N = 900 + nPos(transcript, 5) + nPos(transcript, 6);

	Matrix2d A(N);
	Matrix1d b(N);

	A.generateValues(5 + nPos(transcript, 4), -1, -1);
	b.generateValues(bFunction, nPos(transcript, 3));


}