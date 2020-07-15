#include "pch.h"
#include "special_commands.h"
#include "help_note.h"

int main(int argc, char* argv[])
{

	std::cout<<"Ime     Prezime     Ulica     Broj Ulice     0 ili 1 za musko/zensko     Broj"<<"\r\n";

	help_note help;
	special_commands my_commands(argc, argv);
	my_commands.check(help);




	/*telefonski_imenik imenik;
	string file_name, command;
	if (argc > 1)
	{
		file_name = argv[1];
		command = argv[2];
	}

	if (!file_name.empty())
	{
		std::ifstream fajl(file_name);

		if (!fajl.bad())
		{
			imenik.ucitaj(fajl);
		}
	}
	else
	{
		
	}
	
	imenik.snimi(std::cout);

	std::ofstream fajl(argv[1]);

	if (!fajl.bad())
	{
		imenik.snimi(fajl);
		fajl.flush();
		fajl.close();
	}*/

}