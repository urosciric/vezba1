#include "pch.h"
#include "hardcore_maze.h"
#include "game.h"

hardcore_maze1::hardcore_maze1(size_t x, size_t y)
	: maze_base(x, y)
{
}

void hardcore_maze1::print(game& the_game)
{
	for (size_t i = 0; i < width; i++)
	{
		the_game.get_display().put(i, 0, '#');
		the_game.get_display().put(i, height - 1, '#');

		if (i > 3 && i < width / 2 - 3 || i >width / 2 + 3 && i < width - 3) the_game.get_display().put(i, width / 2, '#');
	}
	for (size_t i = 0; i < height; i++)
	{
		the_game.get_display().put(0, i, '#');
		the_game.get_display().put(width - 1, i, '#');

		if (i > 3 && i < height / 2 - 3 || i >height / 2 + 3 && i < height - 3) the_game.get_display().put(height / 2, i, '#');
	}
}