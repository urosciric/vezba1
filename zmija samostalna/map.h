#pragma once
#include "in_the_back.h"

class map
{

	size_t height;
	size_t width;

public:

	map(size_t height, size_t width);
	void print(in_the_back& back);

};

