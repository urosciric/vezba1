#include "pch.h"
#include "finder.h"
#include "phone_book.h"

void finder::do_command(std::istream& in, phone_book& phonedb)
{
	std::cout << "Ovo je komanda find\r\n";

    string_type first_name;
    string_type last_name;

    in >> first_name;
    in >> last_name;

    auto result=phonedb.find(first_name, last_name);

    if (result.first_name.empty())
        std::cout << "nema\r\n";
    else
        std::cout << result.phone << "\r\n";
}
string_type finder::get_help()
{
	return "Help od add komande find\r\n";
}
