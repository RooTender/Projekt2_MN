#pragma once
#include "Matrix.h"
class Matrix1d : protected Matrix
{
public:
	long double* matrix;

	Matrix1d(int n);

	template<typename func>
	void generateValues(func function, int arg);
};

template<typename func>
inline void Matrix1d::generateValues(func function, int arg)
{
	for (int i = 0; i < cols; i++) {
		matrix[i] = function(i, arg);
	}
}