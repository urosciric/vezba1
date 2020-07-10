#include "pch.h"
#include "player.h"
#include "in_the_back.h"
#include "keyboard.h"
#include "fruit.h"

player::player(size_t x, size_t y)
{

	X = x / 2;
	Y = y / 2;
	height = x;
	width = y;
	the_end = false;

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
			back.put_in(one.x, one.y, 'o');
		}
	}

	if (back.get(X, Y) == '$')
	{
		cords temp;
		temp.x = oldX;
		temp.y = oldY;
		tail.push_back(temp);
	}


	if (X == 0 || Y == 0 || X == height - 1 || Y == width - 1)
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