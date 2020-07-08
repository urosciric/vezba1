#include "pch.h"
#include "Game.h"

game::game(maze_base* maze)
	: snake_maze(maze)
	, display(maze->get_width(), maze->get_height())
	, cash(maze->get_width(), maze->get_height())
	//, cash2(height, width)
{
	players.push_back(body(maze->get_width(), maze->get_height(), ))
	, head(maze->get_width(), maze->get_height())
		, head2()
}
game_display& game::get_display()
{
	return display;
}

input_controler1& game::get_inputs1()
{
	return inputs1;
}

input_controler2& game::get_inputs2()
{
	return inputs2;
}

body1& game::get_head1()
{
	return head1;
}

body2& game::get_head2()
{
	return head2;
}

maze_base& game::get_maze()
{
	return *snake_maze;
}

void game::print()
{
	display.clear();
	snake_maze->print(*this);
	cash.print(*this);
	//cash2.print(*this);
	head1.print(*this);
	head2.print(*this);
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
