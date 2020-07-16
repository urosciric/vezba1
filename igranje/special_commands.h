#pragma once

#include "help_note.h"
#include "dodavanje.h"
#include "telefonski_imenik.h"
#include "telefon.h"
#include "izlistavanje.h"

class special_commands
{	

	dodavanje dod;
	telefon tel;
	izlistavanje lista;
	telefonski_imenik imenik;

	int numb = 0;
	std::vector<std::string> obj;

public:

	special_commands(int number, char* comms[]);
	void check(help_note& help);

};

