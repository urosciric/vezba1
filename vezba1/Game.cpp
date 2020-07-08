#include "pch.h"
#include "Game.h"

game::game(maze_base* maze)
	: snake_maze(maze)
	, display(maze->get_width(), maze->get_height())
	, cash(maze->get_width(), maze->get_height())
	//, cash2(height, width)
{
}
void game::add_player(body_base* player)
{
	players.push_back(player);
}
game_display& game::get_display()
{
	return display;
}

input_controler& game::get_inputs()
{
	return inputs;
}

void game::print()
{
	display.clear();
	snake_maze->print(*this);
	cash.print(*this);
	//cash2.print(*this);
	for (auto one : players)
		one->print(*this);
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
