#pragma once
#include <math.h>

class Matrix
{
protected:
	Matrix() {};

public:
	int rows = 0;
	int cols = 0;

	virtual int size();
};

