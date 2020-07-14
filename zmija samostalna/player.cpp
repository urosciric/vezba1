#include "pch.h"
#include "player.h"
#include "in_the_back.h"
#include "keyboard.h"
#include "fruit.h"
#include "game.h"

player::player(size_t x, size_t y)
{
	dir = direction::STOP;
	tempX = tempY = 0;
	X = x / 3;
	Y = y / 3;
	height = x;
	width = y;
	the_end = false;

}

void player::body(keyboard& input,in_the_back& back)
{

	direction temp_dir = get_dir(input);
	if (temp_dir != direction::STOP)
		dir = temp_dir;

	size_t oldX = X;
	size_t oldY = Y;

	switch (dir)
	{
	case direction::LEFT:
		Y--;
		break;
	case direction::RIGHT:
		Y++;
		break;
	case direction::UP:
		X--;
		break;
	case direction::DOWN:
		X++;
		break;
	default:
		break;
	}

	if (oldX != X || oldY != Y)
	{
		for (auto& one : tail)
		{

			tempX = one.x;
			tempY = one.y;
			one.x = oldX;
			one.y = oldY;
			oldX = tempX;
			oldY = tempY;

			if (back.get(one.x, one.y) != ' ' && back.get(one.x, one.y) != '$')
				the_end = true;

			back.put_in(one.x, one.y, get_tail_char());

		}
	}

	if (back.get(X, Y) != ' ' && back.get(X, Y) != '$')
		the_end = true;

	if (back.get(X, Y) == '$')
	{
		cords temp;
		temp.x = oldX;
		temp.y = oldY;
		tail.push_back(temp);
	}

}

void player::print(in_the_back& back)
{

	back.put_in(X, Y, get_head_char());

}

bool player::end_game()
{

	return the_end;

}

player1::player1(size_t x, size_t y)
	: player(x, y)
{

	this->X = height / 3 + 1;
	this->Y = width / 3;

}

direction player1::get_dir(keyboard& input)
{

	switch (input.get_current())
	{
	case key::left1:
		return direction::LEFT;
	case key::right1:
		return direction::RIGHT;
	case key::up1:
		return direction::UP;
	case key::down1:
		return direction::DOWN;
	default:
		return direction::STOP;
	}

}

player2::player2(size_t x, size_t y)
	: player(x, y)
{

	this->X = height / 3 * 2 + 1;
	this->Y = width / 3 * 2;

}


direction player2::get_dir(keyboard& input)
{

	switch (input.get_current())
	{
	case key::left2:
		return direction::LEFT;
	case key::right2:
		return direction::RIGHT;
	case key::up2:
		return direction::UP;
	case key::down2:
		return direction::DOWN;
	default:
		return direction::STOP;
	}

}