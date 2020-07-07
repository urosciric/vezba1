#pragma once
#include "game_display.h"
#include "input_controler.h"
#include "maze.h"

class game
{
	game_display display;
	input_controler inputs;
	maze snake_maze;
public:
	game(size_t width, size_t height);
	game_display& get_display();
	input_controler& get_inputs();
	maze& draw_maze();
};

