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
		: mapp(2, 2)
		, back(2, 2)
	{
	}
	map& prin();
	in_the_back& printt();

};

