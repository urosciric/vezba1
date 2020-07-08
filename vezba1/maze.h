#pragma once
class game;

class maze_base
{
protected:
	size_t width;
	size_t height;
public:
	maze_base(size_t x, size_t y);
	virtual void print(game& the_game) = 0;
	size_t get_width()
	{
		return width;
	}
	size_t get_height()
	{
		return height;
	}
};

class maze : public maze_base
{
public:
	maze(size_t x, size_t y);
	void print(game& the_game);
};

