#pragma once
#include <math.h>

class Matrix
{
protected:
	Matrix() {};

	int rows = 0;
	int cols = 0;

public:
	virtual int size();
};

