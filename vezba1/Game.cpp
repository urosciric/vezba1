#include "pch.h"
#include "Game.h"

game::game(maze* maze)
	: snake_maze(maze)
	, display(maze->get_width(), maze->get_height())
	, cash(maze->get_width(), maze->get_height())
	//, cash2(height, width)
	, head(maze->get_width(), maze->get_height())
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

body& game::get_head()
{
	return head;
}

maze& game::get_maze()
{
	return *snake_maze;
}

void game::print()
{
	display.clear();
	snake_maze->print(*this);
	cash.print(*this);
	//cash2.print(*this);
	head.print(*this);
}

void game::game_over()
{
	end_game = true;
}

bool game::is_game_over()
{
	return end_game;
}

fruit& game::get_fruit()
{
	return cash;
}
