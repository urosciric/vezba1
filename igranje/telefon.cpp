#include "pch.h"
#include "telefon.h"

void telefon::tele(const std::vector<std::string>& nadji)
{
	for (unsigned int i = 0; i < nadji.size(); i++)
		comands.push_back(nadji[i]);
}

void telefon::ispis(telefonski_imenik& imenik)
{

	std::ifstream fajl1(comands[0]);

	imenik.ucitaj2(fajl1, comands[2]);
	
}