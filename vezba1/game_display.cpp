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
	display_data[x+y*width] = what;
}
void game_display::print(std::ostream& stream)
{
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			stream << display_data[j+i*width];
		}
		stream << "\r\n";
	}
}


void game_display::clear()
{
	init_content();
}
void game_display::init_content()
{
	std::vector<char> height_helper;
	display_data.assign(width* height, ' ');

}
