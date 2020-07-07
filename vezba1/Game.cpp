#include "pch.h"
#include "Game.h"

game::game()
	: display(20, 20)
{
}
game_display& game::get_display()
{
	return display;
}

input_controler& game::get_inputs()
{
	return inputs;
}
