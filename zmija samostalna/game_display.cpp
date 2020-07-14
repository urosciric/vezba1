#include "pch.h"
#include "game_display.h"


bool game_display::initialize_dsplay()
{
	cord_.X = 0;
	cord_.Y = 0;

	std_out_ = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(std_out_, &csbi_);
	clear();
	return true;
}
void game_display::clear()
{
	DWORD dwConSize;
	DWORD cCharsWritten;
	dwConSize = csbi_.dwSize.X * csbi_.dwSize.Y;
	FillConsoleOutputCharacter(std_out_, TEXT(' '), dwConSize, cord_, &cCharsWritten);
	FillConsoleOutputAttribute(std_out_, csbi_.wAttributes, dwConSize, cord_, &cCharsWritten);

}
void game_display::reset_coordinates()
{
	SetConsoleCursorPosition(std_out_, cord_);

}
void game_display::print(std::string& data)
{
	printf("%s", data.c_str());
}
