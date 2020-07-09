#include "pch.h"
#include "in_the_back.h"

in_the_back::in_the_back(size_t x, size_t y)
{

	height = x;
	width = y;
	draw.assign(width * height, ' ');
}

void in_the_back::put_in(size_t X, size_t Y, char shap)
{

	draw[X*height+Y] = shap;

}

void in_the_back::print()
{

	std::ostringstream ss;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			ss << draw[i*width+j];
		}
		ss << "\r\n";
	}

	std::cout << ss.str();

}

char in_the_back::get(size_t x, size_t y)
{

	return draw[x * width + y];

}

void in_the_back::clear()
{

	draw.assign(width * height, ' ');

}