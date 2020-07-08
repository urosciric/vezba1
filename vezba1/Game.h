#pragma once
#include "game_display.h"
#include "input_controler.h"
#include "maze.h"
#include "fruit.h"
#include "body.h"

class game
{
	game_display display;
	input_controler inputs;
	maze_base* snake_maze;
	fruit cash;
	//fruit cash2;
	std::vector<body_base*> players;
	bool end_game = false;
public:
	game(maze_base* maze);
	void add_player(body_base* player);
	game_display& get_display();
	input_controler& get_inputs();
	void print();
	void game_over();
	bool is_game_over();
	fruit& get_fruit();
	
};

