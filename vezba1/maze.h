#pragma once
class game;

class maze
{
	size_t width;
	size_t height;
public:
	maze(size_t x, size_t y);
	void print(game& the_game);
};

