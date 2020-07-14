#include "pch.h"
#include "game.h"


game::game()
{
	
	snake1 = snake2 = nullptr;

}
bool game::init_game(size_t w, size_t h)
{
	if (!back.init_back(w, h))
		return false;
	if (!mapp.init_map(w, h))
		return false;
	for (size_t i = 0; i < sizeof(cash) / sizeof(cash[0]); i++)
	{
		if (!cash[i].initialize(w, h))
			return false;
	}
	snake1 = new player1(h, w);
	snake2 = new player2(h, w);

	return true;
}
void game::print_in_the_back()
{

	back.print();
	back.clear();

}

void game::move_player()
{
	for (size_t i = 0; i < sizeof(cash) / sizeof(cash[0]); i++)
	{
		cash[i].fruit_position(back, *snake1);
		cash[i].fruit_position(back, *snake2);
	}
	snake1->body(button, back);
	snake2->body(button, back);
	snake1->print(back);
	snake2->print(back);

}

void game::fill_in_the_back()
{

	mapp.print(back);
	mapp.explosive(back);
	/*snake1->print(back);
	snake2->print(back);*/

}

void game::read_keys()
{

	button.getch();

}

bool game::game_over()
{

	return snake1->end_game() || snake2->end_game();

}
void game::clear_disp()
{

}
