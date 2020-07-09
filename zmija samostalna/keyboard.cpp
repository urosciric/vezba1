#include "pch.h"
#include "keyboard.h"

void keyboard::getch()
{

	if (_kbhit())
	{
		switch(_getch())
		{
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