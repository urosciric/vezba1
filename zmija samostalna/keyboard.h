#pragma once

enum class key
{
	none,
	left1,
	right1,
	up1,
	down1,
	left2,
	right2,
	up2,
	down2,
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

