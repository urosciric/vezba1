#include "pch.h"
#include "game.h"


game::game(size_t w, size_t h)
	: mapp(h, w)
	, back(h, w)
	, cash(h, w)
{
	snake1 = new player1(h, w);
	snake2 = new player2(h, w);
}
void game::print_in_the_back()
{

	back.print();
	back.clear();

}

void game::move_player()
{

	cash.fruit_position(back,*snake1);
	cash.fruit_position(back, *snake2);
	snake1->body(button, back);
	snake2->body(button, back);

}

void game::fill_in_the_back()
{

	mapp.print(back);
	mapp.explosive(back);
	snake1->print(back);
	snake2->print(back);

}

void game::read_keys()
{

	button.getch();

}

bool game::game_over()
{

	return snake1->end_game() || snake2->end_game();

}
