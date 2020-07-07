#pragma once
#include "game_display.h"

class Game
{
	game_display display;

public:
	Game();
	game_display& get_display();
};

