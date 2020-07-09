#include "pch.h"
#include "in_the_back.h"

in_the_back::in_the_back(size_t x, size_t y)
{

	height = x;
	width = y;
	//init_content();
	draw.assign(width * height, ' ');
}

void in_the_back::put_in(size_t X, size_t Y, char shap)
{

	draw[X*height+Y] = shap;

}

void in_the_back::print()
{

	std::ostringstream ss;

	for (size_t i = 0; i < height * width; i++)
	{
		ss << draw[i];
		if (i % width == 0)
			std::cout << "\r\n";
	}

	std::cout << ss.str();

}

/*void in_the_back::init_content()
{
	draw.assign(width * height, ' ');
}*/
