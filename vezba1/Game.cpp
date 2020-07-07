#include "Game.h"

Game::Game()
	: display(20, 20)
{
}
game_display& Game::get_display()
{
	return display;
}
