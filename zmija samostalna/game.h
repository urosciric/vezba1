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
	player snake;
	keyboard button;
	fruit cash;

public:
	
	game()
		: mapp(30, 30)
		, back(30, 30)
		, snake(30, 30)
		, cash(30, 30)
	{
	}

	game(const game&) = delete;
	void print_in_the_back();
	void move_player();
	void fill_in_the_back();
	void read_keys();
	bool game_over();
	void clear_disp();

};

