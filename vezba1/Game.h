#pragma once
#include "game_display.h"
#include "input_controler.h"

class game
{
	game_display display;
	input_controler inputs;
public:
	game();
	game_display& get_display();
	input_controler& get_inputs();
};

