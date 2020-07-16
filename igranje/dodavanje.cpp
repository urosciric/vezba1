#include "pch.h"
#include "dodavanje.h"
#include "special_commands.h"
#include "telefonski_imenik.h"

void dodavanje::dodaj(const std::vector<std::string>& dodajmo)
{
	for (unsigned int i = 0; i < dodajmo.size(); i++)
		comands.push_back(dodajmo[i]);
}

void dodavanje::pozivanje(telefonski_imenik& imenik)
{
	std::ifstream fajl1(comands[0]);

	imenik.ucitaj1(fajl1);
	fajl1.close();

	imenik.upisi();
	imenik.snimi(std::cout);

	std::ofstream fajl2(comands[0]);
	if (!fajl2.bad())
	{
		imenik.snimi(fajl2);
		fajl2.flush();
		fajl2.close();
	}
}
