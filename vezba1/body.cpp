#include "pch.h"
#include "body.h"
#include "Game.h"
#include "game_display.h"
#include "input_controler.h"

void body::body_parts(game& the_game, size_t x, size_t y)
{
	height = y;
	width = x;

    size_t X = -1;
    size_t Y = -1;

    if (X == -1 || Y == -1)
    {
        X = width / 2;
        Y = height / 2;
    }

	switch (the_game.get_inputs().get_current())
	{
		case game_key::left:
            X--;
            break;
        case game_key::right:
            X++;
            break;
        case game_key::up:
            Y--;
            break;
        case game_key::down:
            Y++;
            break;
	}

}

void fruit::print(game& the_game)
{
    the_game.get_display().put(X, Y, 'O');
}
