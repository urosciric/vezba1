#include "pch.h"
#include "keyboard.h"

void keyboard::getch()
{

	if (_kbhit())
	{
		switch(_getch())
		{
		case 'A':
			pressed = key::left1;
			break;
		case 'D':
			pressed = key::right1;
			break;
		case 'W':
			pressed = key::up1;
			break;
		case 'S':
			pressed = key::down1;
			break;
		case 'a':
			pressed = key::left1;
			break;
		case 'd':
			pressed = key::right1;
			break;
		case 'w':
			pressed = key::up1;
			break;
		case 's':
			pressed = key::down1;
			break;
			///////////////////////////////////////////////
		case 'J':
			pressed = key::left2;
			break;
		case 'L':
			pressed = key::right2;
			break;
		case 'I':
			pressed = key::up2;
			break;
		case 'K':
			pressed = key::down2;
			break;
		case 'j':
			pressed = key::left2;
			break;
		case 'l':
			pressed = key::right2;
			break;
		case 'i':
			pressed = key::up2;
			break;
		case 'k':
			pressed = key::down2;
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