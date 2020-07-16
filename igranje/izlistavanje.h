#pragma once
#include "telefonski_imenik.h"

class izlistavanje
{

public:

	std::vector<std::string> comands;

	void list(const std::vector<std::string>& lista);
	void listanje(telefonski_imenik& imenik);

};

