#pragma once
class game_display
{
	COORD cord_;
	HANDLE std_out_;
	CONSOLE_SCREEN_BUFFER_INFO csbi_;
public:
	bool initialize_dsplay();
	void print(std::string& data);
	void reset_coordinates();
	void clear();
};

