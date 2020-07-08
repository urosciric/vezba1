#pragma once
#include "maze.h"

class hardcore_maze1 : public maze_base
{
public:
	hardcore_maze1(size_t x, size_t y);
	void print(game& the_game);
};

