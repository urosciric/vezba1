#pragma once
#include "pch.h"
#include "in_the_back.h"
#include "map.h"
#include "player.h"
#include "keyboard.h"
#include "fruit.h"

class game
{

	in_the_back back;
	map mapp;
	player* snake1;
	player* snake2;
	keyboard button;
	fruit cash[2];

public:
	
	game();

	bool init_game(size_t w, size_t h);

	game(const game&) = delete;
	void print_in_the_back();
	void fill_in_the_back();
	void move_player();
	void read_keys();
	bool game_over();
	void clear_disp();

};

