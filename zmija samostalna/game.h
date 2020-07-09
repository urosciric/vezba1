#pragma once
#include "pch.h"
#include "in_the_back.h"
#include "map.h"

class game
{

	in_the_back back;
	map mapp;

public:
	
	game()
		: mapp(40, 40)
		, back(40, 40)
	{
	}

	void print_in_the_back();
	void fill_in_the_back();

};

