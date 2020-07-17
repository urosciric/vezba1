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
    string_type first_name = "";
    string_type last_name = "";
    string_type form = "";

    query.all = false;

    size_t temp = 0;

    char current;
    while (!in.eof())
    {
        in.get(current);  
        if (current == '-')
            temp++;
        else if (current != '-' && current != ' ' && temp == 1)
        {
            while (!in.eof() && current != ' ')
            {
                form.push_back(current);
                in.get(current);
            }

            if (form == "n")
            {
                first_name = "";
                do
                {   
                    in.get(current);
                } while (!in.eof() && current == ' ');
                while (!in.eof() && current != ' ')
                {
                    first_name.push_back(current);
                    in.get(current);
                }
            }
            else if (form == "l")
            {
                last_name = "";
                do
                {
                    in.get(current);
                } while (!in.eof() && current == ' ');
                while (!in.eof() && current != ' ')
                {
                    last_name.push_back(current);
                    in.get(current);
                }
            }
            else
            {
                std::cout << "Pogresna komanda\r\n";
                return false;
                break;
            }
            temp = 0;
            form = "";
        }
        /////////////////////////////////////////////////////////////////////ovo su bile kratke forme
        else if (current != '-' && current != ' ' && temp == 2)
        {
            while (!in.eof() && current != ' ')
            {
                form.push_back(current);
                in.get(current);         
            }

            if (form == "name")
            {
                first_name = "";
                while (!in.eof() && current == ' ')
                    in.get(current);
                while (!in.eof() && current != ' ')
                {
                    first_name.push_back(current);
                    in.get(current);
                }
            }
            else if (form == "last")
            {
                last_name = "";
                while (!in.eof() && current == ' ')
                    in.get(current);
                while (!in.eof() && current != ' ')
                {
                    last_name.push_back(current);
                    in.get(current);
                }
            }
            else
            {
                std::cout << "Pogresna komanda\r\n";
                return false;
                break;
            }
            temp = 0;
            form = "";
        }
        /////////////////////////////////////////////////////////////////////ovo su bile duge forme
    }

    if (first_name=="" && last_name=="")
    {
        std::cout << "Nisi uneo komandu, ime ili prezime idiote\r\n";
        return false;
    }
    else
    {
        query.first_name = first_name;
        query.last_name = last_name;
    }
    
    return true;
}
string_type finder::get_help()
{
	return "Help od add komande find\r\n";
}
