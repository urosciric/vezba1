#include "pch.h"
#include "fruit.h"

fruit::fruit(size_t x, size_t y)
{

	height = x;
	width = y;

}

void fruit::fruit_position(in_the_back& back)
{

	if (temp == 0)
	{
		fruitX = rand() % (height - 2) + 1;
		fruitY = rand() % (width - 2) + 1;

		back.put_in(fruitX, fruitY, '$');

		temp++;
	}

	if (back.get(fruitX, fruitY) == 'O')
		temp = 0;

}
