#pragma once
#include "game_display.h"
#include "input_controler.h"
#include "maze.h"
#include "fruit.h"
#include "body.h"
#include "tail.h"

class game
{
	game_display display;
	input_controler inputs;
	maze snake_maze;
	fruit cash;
	//fruit cash2;
	body head;
	bool end_game = false;
public:
	game(size_t width, size_t height);
	game_display& get_display();
	input_controler& get_inputs();
	maze& get_maze();
	body& get_head();
	void print();
	void game_over();
	bool is_game_over();
	fruit& get_fruit();
	
};

