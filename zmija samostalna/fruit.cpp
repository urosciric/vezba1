#include "pch.h"
#include "fruit.h"
#include "player.h"



fruit::fruit()
{
	width = 0;
	height = 0;
	fruitX = fruitY = 0;
	temp = 0;
}
bool fruit::initialize(size_t x, size_t y)
{
	height = x;
	width = y;
	temp = 0;
	return true;

}

void fruit::fruit_position(in_the_back& back,player& snake)
{

	if (temp == 0)
	{
		
		fruitX = rand() % (height - 2) + 1;
		fruitY = rand() % (width - 2) + 1;

		temp=1;

	}

	if (fruitX==snake.X&&fruitY==snake.Y)
		temp = 0;

	back.put_in(fruitX, fruitY, '$');

}
