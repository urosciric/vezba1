#include "pch.h"
#include "special_commands.h"
#include "help_note.h"
#include "dodavanje.h"
#include "telefonski_imenik.h"
#include "telefon.h"
#include "izlistavanje.h"

special_commands::special_commands(int number, char* comms[])
{
	for (int i = 1; i < number; i++)
		obj.push_back(comms[i]);
}

void special_commands::check(help_note& help)
{
	dod.dodaj(obj);
	tel.tele(obj);
	lista.list(obj);

	if (obj.size() >= 2)
	{
		std::ifstream fajl(obj[0]);

		if (!fajl.bad() && obj[1] == "dodaj")
		{
			fajl.close();

			dod.pozivanje(imenik);

		}
		//////////////////////////////////////////////////////////
		else if (!fajl.bad() && obj[1] == "tel" && obj[2] != "")
		{
			fajl.close();
				
			tel.ispis(imenik);

		}
		//////////////////////////////////////////////////////////
		else if (!fajl.bad() && obj[1] == "list" && obj[2] != "")
		{
			fajl.close();

			lista.listanje(imenik);

		}
	}
	else
	{
		help.type_help();
	}

}