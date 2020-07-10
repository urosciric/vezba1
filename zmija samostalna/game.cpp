#include "pch.h"
#include "game.h"



void game::print_in_the_back()
{

	back.print();
	back.clear();

}

void game::move_player()
{

	cash.fruit_position(back,snake);
	snake.body(button,back);

}

void game::fill_in_the_back()
{

	mapp.print(back);
	snake.print(back);

}

void game::read_keys()
{

	button.getch();

}

bool game::game_over()
{

	return snake.end_game();

}
