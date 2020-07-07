
#include "pch.h"
#include "maze.h"
#include "Game.h"

maze::maze(size_t x, size_t y)
{
	width = x;
	height = y;
}

void maze::print(game& the_game)
{
	for (size_t i = 0; i < width; i++)
	{
		the_game.get_display().put(i, 0, '#');
		the_game.get_display().put(i, height-1, '#');
	}
	for (size_t i = 0; i < height; i++)
	{
		the_game.get_display().put(0, i, '#');
		the_game.get_display().put(width - 1, i, '#');
	}
}