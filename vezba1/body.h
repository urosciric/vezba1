#pragma once
#include "tail.h"
class game;

class body_base
{
	enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	direction dir;

	size_t width;
	size_t height;

	size_t X = -1;
	size_t Y = -1;

	std::vector<tail> tail_data;

	char head_char;
	char tail_char;

protected:
	size_t score1;

public:	
	body(size_t x, size_t y, char head, char tail);
	void print(game& the_game);
};


