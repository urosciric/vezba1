#pragma once
class game_display
{
	typedef std::vector<char> data_type;

	size_t width;
	size_t height;
	data_type display_data;

public:
	game_display(size_t xsize, size_t ysize);
	void clear();
	void put(size_t x, size_t y, char what);
	char get(size_t x, size_t y);
	void print(std::ostream& stream);

private:
	void init_content();

};

