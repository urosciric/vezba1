#include "pch.h"
#include "body.h"
#include "Game.h"
#include "game_display.h"
#include "input_controler.h"
#include "fruit.h"

body1::body1(size_t x, size_t y)
{
	height = y;
	width = x;
    X = 3;
    Y = 3;
}

void body1::print(game& the_game)
{
    switch (the_game.get_inputs1().get_current())
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

    if (old_x != X || old_y != Y)
    {
        // we are moving :)
        size_t temp_x;
        size_t temp_y;
        for (auto& one : tail_data)
        {
            temp_x = one.X;
            temp_y = one.Y;
            one.X = old_x;
            one.Y = old_y;
            old_x = temp_x;
            old_y = temp_y;
        }
    }

    /*size_t pom_x;
    size_t pom_y;*/

    if (the_game.get_display().get(X, Y) == '#' || the_game.get_display().get(X, Y) == 'q' || the_game.get_display().get(X, Y) == 'Q')
        the_game.game_over();
    if (the_game.get_display().get(X, Y) == '$')
    {
        the_game.get_fruit().random();
        tail new_tail;
        new_tail.X = old_x;
        new_tail.Y = old_y;
        tail_data.push_back(new_tail);
        score1 = tail_data.size();
    }

    the_game.get_display().put(X, Y, 'O');
    //for (size_t i = 0; i < tail_data.size(); i++)
    //{
    //    tail one = tail_data[i];
    //    // rad
    //}
    for (auto& one : tail_data)
    {
        if (the_game.get_display().get(one.X, one.Y) == '#')
            the_game.game_over();
        the_game.get_display().put(one.X, one.Y, 'o');
    }

    std::cout << score1 << "\r\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////

body2::body2(size_t x, size_t y)
{
    height = y;
    width = x;
    X = width - 3;
    Y = height - 3;
}

void body2::print(game& the_game)
{
    switch (the_game.get_inputs2().get_current())
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

    if (old_x != X || old_y != Y)
    {
        // we are moving :)
        size_t temp_x;
        size_t temp_y;
        for (auto& one : tail_data)
        {
            temp_x = one.X;
            temp_y = one.Y;
            one.X = old_x;
            one.Y = old_y;
            old_x = temp_x;
            old_y = temp_y;
        }
    }

    /*size_t pom_x;
    size_t pom_y;*/

    if (the_game.get_display().get(X, Y) == '#' || the_game.get_display().get(X, Y) == 'o' || the_game.get_display().get(X, Y) == 'O')
        the_game.game_over();
    if (the_game.get_display().get(X, Y) == '$')
    {
        the_game.get_fruit().random();
        tail new_tail;
        new_tail.X = old_x;
        new_tail.Y = old_y;
        tail_data.push_back(new_tail);
        score2 = tail_data.size();
    }

    the_game.get_display().put(X, Y, 'Q');
    //for (size_t i = 0; i < tail_data.size(); i++)
    //{
    //    tail one = tail_data[i];
    //    // rad
    //}
    for (auto& one : tail_data)
    {
        if (the_game.get_display().get(one.X, one.Y) == '#')
            the_game.game_over();
        the_game.get_display().put(one.X, one.Y, 'q');
    }

    std::cout << score2 << "\r\n";
}

