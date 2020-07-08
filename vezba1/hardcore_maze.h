#pragma once
#include "maze.h"
#include "Game.h"

class hardcore_maze1 : public maze_base
{
public:
	hardcore_maze1(size_t x, size_t y);
	void print(game& the_game);
};

class hardcore_maze2 : public maze_base
{
	size_t explosive = 0;

	size_t x1 = width - 1;
	size_t x2 = 1;
	size_t x3 = width / 2;
	size_t x4 = width / 2;
	size_t y1 = height / 2;
	size_t y2 = height / 2;
	size_t y3 = 1;
	size_t y4 = height - 1;

public:
	hardcore_maze2(size_t x, size_t y);
	void print(game& the_game);
};

