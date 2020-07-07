#pragma once


enum class game_key
{
	none,
	left,
	right,
	up,
	down,
	exit
};

class input_controler
{
	game_key pressed = game_key::none;
public:
	void read_keys();
	game_key get_current();
};

