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
//////////////////////////////////////////////////////////////////////////////////////
hardcore_maze2::hardcore_maze2(size_t x, size_t y)
	: maze_base(x, y)
{
}

void hardcore_maze2::print(game& the_game)
{
	explosive++;
	for (size_t i = 0; i < width; i++)
	{
		the_game.get_display().put(i, 0, '#');
		the_game.get_display().put(i, height - 1, '#');
	}
	for (size_t i = 0; i < height; i++)
	{
		the_game.get_display().put(0, i, '#');
		the_game.get_display().put(width - 1, i, '#');
	}
	if (x1 != x2)
	{
		x1--;
		x2++;
		y3++;
		y4--;
	}
	else
	{
		x1 = width - 1;
		x2 = 1;
		x3 = width / 2;
		x4 = width / 2;
		y1 = height / 2;
		y2 = height / 2;
		y3 = 1;
		y4 = height - 1;
	}
	the_game.get_display().put(x1, y1, '#');
	the_game.get_display().put(x2, y2, '#');
	the_game.get_display().put(x3, y3, '#');
	the_game.get_display().put(x4, y4, '#');
}