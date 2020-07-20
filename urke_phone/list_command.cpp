#include "pch.h"
#include "list_command.h"
#include "phone_query.h"

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
	
    string_type first_name;
    string_type last_name;

    in >> first_name;
    in >> last_name;

    phone_query query;
    //query.all = false;
    query.first_name = first_name;
    query.last_name = last_name;

    auto result = phonedb.find(query);

    for (auto& one : result)
    {
        std::cout << one.first_name << "\t"
            << one.last_name << "\t"
            << one.street << "\t"
            << one.number << "\t"
            << one.male << "\t"
            << one.phone << "\r\n";
    }
}
