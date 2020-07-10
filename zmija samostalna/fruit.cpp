#include "pch.h"
#include "fruit.h"

fruit::fruit(size_t x, size_t y)
{

	height = x;
	width = y;
	temp = 0;

}

void fruit::fruit_position(in_the_back& back)
{

	if (temp == 0)
	{
		fruitX = rand() % (height - 2) + 1;
		fruitY = rand() % (width - 2) + 1;

		temp=1;
	}

	if (back.get(fruitX, fruitY) == 'O')
		temp = 0;

	back.put_in(fruitX, fruitY, '$');

}
