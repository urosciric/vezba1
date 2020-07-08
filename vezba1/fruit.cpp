#include "pch.h"
#include "fruit.h"
#include "Game.h"
#include "body.h"

fruit::fruit(size_t x, size_t y)
{
	width = x;
	height = y;
	random();
}

void fruit::random()
{

	fruitX = rand() % (width - 2) + 1;
	fruitY = rand() % (height - 2) + 1;
}

void fruit::print(game& the_game)
{
	if (the_game.get_display().get(fruitX, fruitY) == '#') random();
	the_game.get_display().put(fruitX, fruitY, '$');
}

