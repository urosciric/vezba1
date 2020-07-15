#include "help_note.h"
#include "pch.h"

void help_note::type_help()
{

	std::cout << "- koriscenje programa:" << "\r\n"
		<< "imenik <fajl> <komanda>" << "\r\n"
		<< "ako nema dovoljno argumenata, fajl ne moze da se otvori ili nije poznata komanda ispisi help i izadji" << "\r\n"
		<< "<fajl> -ime fajla sa kojim se radi, mora uvek da bude tu" << "\r\n"
		<< "<komanda> -podkomanda koja se aktivira :" << "\r\n"
		<< "-dodaj - dodaje novi red u imeniku" << "\r\n"
		<< "- tel - nadji telefon za ime i prezime" << "\r\n"
		<< "- list - izlistavanje po raznim kriterijumima(muski, iz ulice neke ...)" << "\r\n";

}
