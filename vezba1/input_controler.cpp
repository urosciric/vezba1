#include "pch.h"
#include "input_controler.h"


void input_controler::read_keys()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            pressed = game_key::left;
            break;
        case 'd':
            pressed = game_key::right;
            break;
        case 'w':
            pressed = game_key::up;
            break;
        case 's':
            pressed = game_key::down;
            break;
        case 'x':
            pressed = game_key::exit;
            break;
        default:
            pressed = game_key::none;

        }
    }
}
game_key input_controler::get_current()
{
    return pressed;
}