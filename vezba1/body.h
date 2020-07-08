#pragma once
#include "tail.h"
class game;

class body
{
	enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	direction dir;

	size_t width;
	size_t height;

	size_t X = -1;
	size_t Y = -1;

	std::vector<tail> tail_data;

public:	
	body(size_t x, size_t y);
	void print(game& the_game);
};

