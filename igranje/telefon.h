#pragma once
#include "telefonski_imenik.h"

class telefon
{

public:

	std::vector<std::string> comands;
	void tele(const std::vector<std::string>& nadji);
	void ispis(telefonski_imenik& imenik);

};

