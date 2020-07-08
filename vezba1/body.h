#pragma once
#include "tail.h"
class game;

enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class body_base
{
	direction dir;

	size_t X = -1;
	size_t Y = -1;

	std::vector<tail> tail_data;

	char head_char;
	char tail_char;
	bool first;

	size_t score;

public:	
	body_base(size_t x, size_t y);
	void print(game& the_game);
protected:
	virtual direction get_direction(game& the_game) = 0;
	virtual char get_head_char() = 0;
	virtual char get_tail_char() = 0;
};

class player1 : public body_base
{
public:
	player1(size_t x, size_t y);
	direction get_direction(game& the_game);
	char get_head_char()
	{
		return 'O';
	}
	char get_tail_char()
	{
		return 'o';
	}
};

class player2 : public body_base
{
public:
	player2(size_t x, size_t y);
	direction get_direction(game& the_game);
	char get_head_char()
	{
		return 'Q';
	}
	char get_tail_char()
	{
		return 'q';
	}
};

