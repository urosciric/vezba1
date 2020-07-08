#include "pch.h"
#include "body.h"
#include "Game.h"
#include "game_display.h"
#include "input_controler.h"
#include "fruit.h"

body_base::body_base(size_t x, size_t y)
{
    X = x;
    Y = y;
}

void body_base::print(game& the_game)
{
    
    direction temp_dir = get_direction(the_game);
    if (temp_dir != STOP)
        dir = temp_dir;

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
    char test_char = the_game.get_display().get(X, Y);

    if (test_char == '$')
    {
        the_game.get_fruit().random();
        tail new_tail;
        new_tail.X = old_x;
        new_tail.Y = old_y;
        tail_data.push_back(new_tail);
    }
    else if(test_char!=get_head_char() && test_char != get_head_char() && test_char!=' ')
        the_game.game_over();

    the_game.get_display().put(X, Y, get_head_char());
    //for (size_t i = 0; i < tail_data.size(); i++)
    //{
    //    tail one = tail_data[i];
    //    // rad
    //}
    for (auto& one : tail_data)
    {
        if (the_game.get_display().get(one.X, one.Y) == '#')
            the_game.game_over();
        the_game.get_display().put(one.X, one.Y, get_tail_char());
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////

player1::player1(size_t x, size_t y)
    : body_base(x, y)
{
}
direction player1::get_direction(game& the_game)
{
    switch (the_game.get_inputs().get_current())
    {
    case game_key::left1:
        return LEFT;
    case game_key::right1:
        return RIGHT;
    case game_key::up1:
        return UP;
    case game_key::down1:
        return DOWN;
    default:
        return STOP;
    }
}

player2::player2(size_t x, size_t y)
    : body_base(x, y)
{
}
direction player2::get_direction(game& the_game)
{
    switch (the_game.get_inputs().get_current())
    {
    case game_key::left2:
        return LEFT;
    case game_key::right2:
        return RIGHT;
    case game_key::up2:
        return UP;
    case game_key::down2:
        return DOWN;
    default:
        return STOP;
    }
}