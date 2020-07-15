#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <string>
#include <fstream>
#include "telefonski_imenik.h"

int main(int argc, char* argv[])
{
	telefonski_imenik imenik;
	string file_name;

	if (argc > 1)
		file_name = argv[1];

	if (!file_name.empty())
	{
		std::ifstream fajl("imenik.txt");

		if (!fajl.bad())
		{
			imenik.ucitaj(fajl);
		}
	}
	else
	{
		imenik_data temp;
		temp.ime = "Uros";
		temp.prezime = "Ciric";
		temp.ulica = "Zagorska";
		temp.broj = 48;
		temp.musko = true;
		temp.telefon = "1345678";

		imenik.dodaj(temp);

		temp.ime = "Zrna";
		temp.musko = false;
		temp.telefon = "987654";

		imenik.dodaj(temp);
	}

	imenik.snimi(std::cout);

	std::ofstream fajl("imenik.txt");

	if (!fajl.bad())
	{
		imenik.snimi(fajl);
		fajl.flush();
		fajl.close();
	}

}