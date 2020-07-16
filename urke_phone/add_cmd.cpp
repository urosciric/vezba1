#include "pch.h"
#include "add_cmd.h"
#include "phone_book.h"

void add_cmd::do_command(std::istream& in, phone_book& phonedb)
{
	std::cout<<"Ovo je komanda add\r\n";

	phone_data data;
	std::cin >> data.first_name;
	std::cin >> data.last_name;
	std::cin >> data.street;
	std::cin >> data.number;
	std::cin >> data.male;
	std::cin >> data.phone;

	phonedb.add(data);
}
string_type add_cmd::get_help()
{
	return "Help od add komande\r\n";
}