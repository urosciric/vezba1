#include "pch.h"
#include "Game.h"

game::game(size_t width, size_t height)
	: display(width, height)
	, snake_maze(width, height)
	, cash(height, width)
	, cash2(height, width)
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

maze& game::get_maze()
{
	return snake_maze;
}

body& game::get_head()
{
	return head;
}

void game::print()
{
	display.clear();
	snake_maze.print(*this);
	cash.print(*this);
	cash2.print(*this);
}
