#include "pch.h"
#include "special_commands.h"
#include "help_note.h"

int main(int argc, char* argv[])
{

	std::cout<<"Ime     Prezime     Ulica     Broj Ulice     0 ili 1 za musko/zensko     Broj"<<"\r\n";

	help_note help;
	special_commands my_commands(argc, argv);
	my_commands.check(help);

}