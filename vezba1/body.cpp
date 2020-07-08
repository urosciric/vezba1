#include "pch.h"
#include "body.h"
#include "Game.h"
#include "game_display.h"
#include "input_controler.h"
#include "fruit.h"

body::body(size_t x, size_t y)
{
	height = y;
	width = x;
    X = width / 2;
    Y = height / 2;
}

void body::print(game& the_game)
{
    switch (the_game.get_inputs().get_current())
    {
    case game_key::left:
        dir = LEFT;
        break;
    case game_key::right:
        dir = RIGHT;
        break;
    case game_key::up:
        dir = UP;
        break;
    case game_key::down:
        dir = DOWN;
        break;
    }

    size_t old_x = X;
    size_t old_y = Y;

    switch (dir)
    {
    case LEFT:
        X--;
        break;
    case RIGHT:
        X++;
        break;
    case UP:
        Y--;
        break;
    case DOWN:
        Y++;
        break;
    }

    /*size_t pom_x;
    size_t pom_y;*/

    if (the_game.get_display().get(X, Y) == '#')
        the_game.game_over();
    if (the_game.get_display().get(X, Y) == '$')
    {
        the_game.get_fruit().random();

        for (auto one : tail_data)
        {
            /*pom_x = one.X;
            pom_y = one.Y;
            one.X = old_x;
            one.Y = old_y;*/
            the_game.get_display().put(old_x, old_y, 'o');
            old_x = one.X;
            old_y = one.Y;
        }

        tail new_tail;
        new_tail.X = old_x;
        new_tail.Y = old_y;
        tail_data.push_back(new_tail);

        //tail_data[0] = (old_x, old_y);

    }

    the_game.get_display().put(X, Y, 'O');
    //for (size_t i = 0; i < tail_data.size(); i++)
    //{
    //    tail one = tail_data[i];
    //    // rad
    //}
}
