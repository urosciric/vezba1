#pragma once
#include "in_the_back.h"

class map
{

protected:

	size_t height;
	size_t width;

	size_t x1;
	size_t x2;
	size_t x3;
	size_t x4;
	size_t y1;
	size_t y2;
	size_t y3;
	size_t y4;

	size_t exp = 0;


public:
	map();
	bool init_map(size_t height, size_t width);
	void text_doc();
	void explosive(in_the_back& back);
	void print(in_the_back& back);

};

