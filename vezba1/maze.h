#pragma once
class game;

class maze
{
	size_t width;
	size_t height;
public:
	maze(size_t x, size_t y);
	void print(game& the_game);
	size_t get_width()
	{
		return width;
	}
	size_t get_height()
	{
		return height;
	}
};

