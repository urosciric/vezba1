#pragma once

enum class key
{
	none,
	left,
	right,
	up,
	down
};

class keyboard
{

	key pressed = key::none;

public:

	keyboard()
	{

	}

	void getch();
	key get_current();

};

