#include "izlistavanje.h"

void izlistavanje::list(const std::vector<std::string>& lista)
{
	for (unsigned int i = 0; i < lista.size(); i++)
		comands.push_back(lista[i]);
}

void izlistavanje::listanje(telefonski_imenik& imenik)
{

	std::ifstream fajl1(comands[0]);

	imenik.ucitaj2(fajl1, comands[2]);

}