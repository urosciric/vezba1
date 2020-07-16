#include "pch.h"
#include "list_command.h"

string_type list_command::get_help()
{
	return
		"Ovo je komanda za listanje imenika\r\n"
		"Koriscenje\r\n"
		"urke_phone list\r\n"
		"Nema dodatnih argumenata.\r\n";
}
void list_command::do_command(std::istream& in, phone_book& phonedb)
{
	string_type args;
	in >> args;
	if (!args.empty())
	{
		std::cout << "Ova komanda nema argumente!!!\r\n";
		std::cout << get_help();
		return;
	}

	phonedb.save(std::cout);
}
