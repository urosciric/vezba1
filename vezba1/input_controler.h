#pragma once


enum class game_key
{
	none,
	left1,
	right1,
	up1,
	down1,
	left2,
	right2,
	up2,
	down2
};

class input_controler
{
	game_key pressed = game_key::none;
public:
	void read_keys();
	game_key get_current();
};

//