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
		: mapp(40, 40)
		, back(40, 40)
		, snake(40, 40)
		, cash(40, 40)
	{
	}

	void print_in_the_back();
	void move_player();
	void fill_in_the_back();
	void read_keys();
	bool game_over();

};

