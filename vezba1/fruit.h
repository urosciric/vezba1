#pragma once
class game;
class body;

class fruit
{
	size_t fruitX;
	size_t fruitY;
	size_t width;
	size_t height;

public:
	fruit(size_t x, size_t y);
	void print(game& the_game);
	void random();
};

