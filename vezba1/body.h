#pragma once
class game;

class body
{
	typedef std::vector<size_t> lenght;

	lenght bodyXY;

	size_t width;
	size_t height;

public:
	
	void body_parts(game& the_game, size_t x, size_t y);
	void print(game& the_game);
};

