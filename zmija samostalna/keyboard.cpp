#include "pch.h"
#include "keyboard.h"

void keyboard::getch()
{

	if (_kbhit())
	{
		switch(_getch())
		{
		case 'A':
			pressed = key::left;
			break;
		case 'D':
			pressed = key::right;
			break;
		case 'W':
			pressed = key::up;
			break;
		case 'S':
			pressed = key::down;
			break;
		case 'a':
			pressed = key::left;
			break;
		case 'd':
			pressed = key::right;
			break;
		case 'w':
			pressed = key::up;
			break;
		case 's':
			pressed = key::down;
			break;
		default:
			pressed = key::none;
		}
	}

}

key keyboard::get_current()
{
	return pressed;
}