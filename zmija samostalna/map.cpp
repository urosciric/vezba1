#include "pch.h"
#include "map.h"
#include "in_the_back.h"

map::map(size_t he,size_t wi)
	: back(he, wi)
{

	height = he;
	width = wi;

}

void map::print()
{

	for (size_t i = 0; i < height; i++)
		for (size_t j = 0; j < width; j++)
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
				back.put_in(i, j, '#');

}
