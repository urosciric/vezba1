#include "pch.h"
#include "map.h"
#include "in_the_back.h"

map::map(size_t he,size_t wi)
{

	height = he;
	width = wi;

	x1 = 1;
	x2 = height - 1;
	x3 = 0;
	x4 = height - 1;
	y1 = 1;
	y2 = width - 1;
	y3 = 0;
	y4 = width - 1;

}

void map::explosive(in_the_back& back)
{

	if (x1 == x2)
	{
		x1 = 1;
		x2 = height - 1;
		x3 = 0;
		x4 = height - 1;
		y1 = 1;
		y2 = width - 1;
		y3 = 0;
		y4 = width - 1;
	}
	else
	{

		x1++;
		x2--;
		x3--;
		x4++;
		y1++;
		y2--;
		y3--;
		y4++;
		
	}

	back.put_in(x1, y1, '#');
	back.put_in(x2, y2, '#');
	back.put_in(x3, y3, '#');
	back.put_in(x4, y4, '#');

}

void map::print(in_the_back& back)
{

	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				back.put_in(i, j, '#');

}
