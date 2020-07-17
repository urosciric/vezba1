#include "pch.h"
#include "finder.h"
#include "phone_book.h"
#include "phone_query.h"

void finder::do_command(std::istream& in, phone_book& phonedb)
{
	std::cout << "Ovo je komanda find\r\n";


    phone_query query;

    if (parse_command(in, query))
    {
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
    else
    {
        std::cout << "Jbg greska\r\n";
    }
}
bool finder::parse_command(std::istream& in, phone_query& query)
{
    string_type first_name;
    string_type last_name;
    string_type long_form = "";

    query.all = true;

    size_t temp = 0;

    char current;
    while (!in.eof())
    {
        in >> current;
        if (current == '-')
            temp++;
        else if (current != '-' && current != ' ' && temp == 1)
        {
            if (current == 'n')
            {
                while (!in.eof() && current == ' ')
                    in >> current;
                while (!in.eof() && current != ' ')
                {
                    in >> current;
                    first_name.push_back(current);
                }
                first_name.pop_back();
            }
            else if (current == 'l')
            {
                while (!in.eof() && current == ' ')
                    in >> current;
                while (!in.eof() && current != ' ')
                {
                    in >> current;
                    last_name.push_back(current);
                }
                last_name.pop_back();
            }
        }
        /////////////////////////////////////////////////////////////////////ovo su bile kratke forme
        else if (current != '-' && current != ' ' && temp == 2)
        {
            while (!in.eof() && current != ' ')
            {
                long_form.push_back(current);
                in.get(current);         
            }

            if (long_form == "name")
            {
                while (!in.eof() && current == ' ')
                    in >> current;
                while (!in.eof() && current != ' ')
                {
                    in >> current;
                    first_name.push_back(current);
                }
                first_name.pop_back();
            }
            else if (long_form == "last")
            {
                while (!in.eof() && current == ' ')
                    in >> current;
                while (!in.eof() && current != ' ')
                {
                    in >> current;
                    last_name.push_back(current);
                }
                last_name.pop_back();
            }
        }
        /////////////////////////////////////////////////////////////////////ovo su bile duge forme
    }
    
    query.first_name = first_name;
    query.last_name = last_name;
    
    return true;
}
string_type finder::get_help()
{
	return "Help od add komande find\r\n";
}
