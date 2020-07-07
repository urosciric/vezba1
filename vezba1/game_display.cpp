#include "pch.h"
#include "game_display.h"

game_display::game_display(size_t xsize, size_t ysize)
{
	width = xsize;
	height = ysize;
	init_content();
}

void game_display::put(size_t x, size_t y, char what)
{
	display_data[y+x*height] = what;
}
char game_display::get(size_t x, size_t y)
{
	return display_data[y + x * height];
}

void game_display::print(std::ostream& stream)
{
	std::ostringstream ss;
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			ss << display_data[j+i*width];
		}
		ss << "\r\n";
	}
	stream << ss.str();
}

void game_display::clear()
{
	init_content();
}

void game_display::init_content()
{
	display_data.assign(width* height, ' ');
}
