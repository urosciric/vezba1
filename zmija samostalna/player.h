#pragma once
#include "in_the_back.h"
#include "keyboard.h"
#include "fruit.h"
#include "game.h"

struct cords
{

	size_t x;
	size_t y;

};

enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class player
{

protected:

	size_t height;
	size_t width;

	size_t tail_size = 0;

	size_t tempX;
	size_t tempY;

	std::vector<cords> tail;

	bool the_end;

	virtual char get_head_char() = 0;
	virtual char get_tail_char() = 0;
	virtual direction get_dir(keyboard& input) = 0;

public:

	direction dir;

	size_t X;
	size_t Y;

	player(size_t x, size_t y);
	void body(keyboard& input, in_the_back& back);
	void print(in_the_back& back);
	bool end_game();

};

class player1 : public player
{

public:

	player1(size_t x, size_t y);
	direction get_dir(keyboard& input);

	char get_head_char()
	{
		return 'O';
	}
	char get_tail_char()
	{
		return 'o';
	}

};

class player2 : public player
{

public:

	player2(size_t x, size_t y);
	direction get_dir(keyboard& input);

	char get_head_char()
	{
		return 'Q';
	}
	char get_tail_char()
	{
		return 'q';
	}

};