#pragma once
class in_the_back
{

	typedef std::vector<char> vector;
	vector draw;

	size_t height;
	size_t width;

	char what;

public:
	in_the_back();
	bool init_back(size_t width, size_t height);
	void put_in(size_t x, size_t y, char shape);
	char get(size_t x, size_t y);
	void clear();
	void print();

private:

	//void init_content();

};

