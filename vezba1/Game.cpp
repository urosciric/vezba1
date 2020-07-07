#include "pch.h"
#include "Game.h"

game::game(size_t width, size_t height)
	: display(width, height)
	, snake_maze(width, height)
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

maze& game::draw_maze()
{
	return snake_maze;
}
