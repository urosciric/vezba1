#pragma once
#include "in_the_back.h"
#include "keyboard.h"
#include "fruit.h"

struct cords
{

	size_t x;
	size_t y;

};

class player
{

	size_t X;
	size_t Y;

	size_t height;
	size_t width;

	size_t tail_size = 0;

	size_t tempX;
	size_t tempY;

	std::vector<cords> tail;

	bool the_end;

public:

	player(size_t x, size_t y);
	void body(keyboard& input, in_the_back& back);
	void print(in_the_back& back);
	bool end_game();

};

