#pragma once
#include "in_the_back.h"

class map
{

	size_t height;
	size_t width;

	in_the_back back;

public:

	map(size_t height, size_t width);
	void print();

};

