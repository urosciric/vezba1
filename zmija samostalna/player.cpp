#include "pch.h"
#include "player.h"
#include "in_the_back.h"
#include "keyboard.h"
#include "fruit.h"

player::player(size_t x, size_t y)
{

	X = x / 2;
	Y = y / 2;

}

void player::body(keyboard& input,in_the_back& back)
{

	size_t oldX = X;
	size_t oldY = Y;

	switch (input.get_current())
	{
	case key::left:
		Y--;
		break;
	case key::right:
		Y++;
		break;
	case key::up:
		X--;
		break;
	case key::down:
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
		}
	}

	if (back.get(X, Y) == '$')
	{
		cords temp;
		temp.x = oldX;
		temp.y = oldY;
		tail.push_back(temp);
	}

	if (back.get(X, Y) == '#')
		the_end = true;

}

void player::print(in_the_back& back)
{

	back.put_in(X, Y, 'O');

}

bool player::end_game()
{

	return the_end;

}