#include "pch.h"
#include "input_controler.h"


void input_controler::read_keys()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            pressed = game_key::left1;
            break;
        case 'd':
            pressed = game_key::right1;
            break;
        case 'w':
            pressed = game_key::up1;
            break;
        case 's':
            pressed = game_key::down1;
            break;
        case 'j':
            pressed = game_key::left2;
            break;
        case 'l':
            pressed = game_key::right2;
            break;
        case 'i':
            pressed = game_key::up2;
            break;
        case 'k':
            pressed = game_key::down2;
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

