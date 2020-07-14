#pragma once
#include "in_the_back.h"
class player;

class fruit
{

protected:

	size_t height;
	size_t width;
	size_t fruitX;
	size_t fruitY;
	size_t temp;

public:

	fruit(size_t x, size_t y);
	void fruit_position(in_the_back& back, player& snake);

};

