#pragma once
#include "telefonski_imenik.h"

class dodavanje
{

public:

	std::vector<std::string> comands;

	void dodaj(const std::vector<std::string>& dodajmo);
	void pozivanje(telefonski_imenik& imenik);

};

