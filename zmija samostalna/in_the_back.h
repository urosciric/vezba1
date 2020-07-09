#pragma once
class in_the_back
{

	typedef std::vector<char> vector;
	vector draw;

	size_t height;
	size_t width;

	char what;

public:

	in_the_back(size_t width, size_t height);
	void put_in(size_t x, size_t y, char shape);
	void print();

private:

	void init_content();

};

