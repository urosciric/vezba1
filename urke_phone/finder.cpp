#include "pch.h"
#include "finder.h"
#include "phone_book.h"
#include "phone_query.h"
#include "parser3000.h"

void finder::do_command(std::istream& in, phone_book& phonedb)
{
	std::cout << "Ovo je komanda find\r\n";


    phone_query query;

    std::ostringstream err;

    //////////////////////////////////////////////////////////////////////////////
    // pomoc parsera 3000
    parser::parser3000 my_parser;

    parser::string_option temp_opt;

    system("pause");

    temp_opt.short_option = 'n';
    temp_opt.long_option = "name";
    temp_opt.value = &query.first_name;
    my_parser.add_string_option(temp_opt);

    temp_opt.short_option = 'l';
    temp_opt.long_option = "last";
    temp_opt.value = &query.last_name;
    my_parser.add_string_option(temp_opt);


    if (my_parser.parse(in, err))
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
        std::cout << "Greska parsiranja:\r\n";
        std::cout << err.str();
    }
    system("pause");

    //////////////////////////////////////////////////////////////////////////////

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
    int number = -1;
    bool sex = true;
    string_type num = "";
    string_type form = "";

    //query.all = false;

    size_t temp = 0;
    int sex_temp = -1;

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
            else if (form == "b")
            {
                do
                {
                    in.get(current);
                } while (!in.eof() && current == ' ');
                while (!in.eof() && current != ' ')
                {
                    num.push_back(current);
                    in.get(current);
                }
                for (unsigned int i = 0; i < num.size(); i++)
                {
                    temp = 0;
                    if (num[i] != '0' && num[i] != '1' && num[i] != '2' && num[i] != '3' && num[i] != '4' && num[i] != '5' && num[i] != '6' && num[i] != '7' && num[i] != '8' && num[i] != '9')
                        temp++;
                }
                if (temp == 0)
                {
                    number = std::stoi(num);
                }
                else
                {
                    std::cout << "Ne moze slova moraju brojevi!!!\r\n";
                    return false;
                    break;
                }
            }
            else if (form == "m")
            {
                sex = false;
                sex_temp = 1;
            }
            else if (form == "f")
            {
                sex = true;
                sex_temp = 0;
            }
            else
            {
                std::cout << "Pogresna komanda\r\n";
                return false;
                break;
            }
            num = "";
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
            else if (form == "broj")
            {
                while (!in.eof() && current == ' ')
                    in.get(current);
                while (!in.eof() && current != ' ')
                {
                    num.push_back(current);
                    in.get(current);
                }
                for (unsigned int i = 0; i < num.size(); i++)
                {
                    temp = 0;
                    if (num[i] != '0' && num[i] != '1' && num[i] != '2' && num[i] != '3' && num[i] != '4' && num[i] != '5' && num[i] != '6' && num[i] != '7' && num[i] != '8' && num[i] != '9')
                        temp++;
                }
                if (temp == 0)
                {
                    number = std::stoi(num);
                }
                else
                {
                    std::cout << "Ne moze slova moraju brojevi!!!\r\n";
                    return false;
                    break;
                }
            }
            else if (form == "male")
            {
                sex = false;
                sex_temp = 1;
            }
            else if (form == "female")
            {
                sex = true;
                sex_temp = 0;
            }
            else
            {
                std::cout << "Pogresna komanda\r\n";
                return false;
                break;
            }
            num = "";
            temp = 0;
            form = "";
        }
        /////////////////////////////////////////////////////////////////////ovo su bile duge forme
    }

    if (first_name == "" && last_name == "" && number == -1 && sex_temp == -1)
    {
        std::cout << "Nisi uneo sta treba!!!\r\n";
        return false;
    }
    else if (first_name != "" || last_name != "" || number != -1 || sex_temp != -1)
    {
        query.first_name = first_name;
        query.last_name = last_name;
        query.number = number;
        query.sex_temp = sex_temp;
        query.sex = sex;
    }
    
    return true;
}
string_type finder::get_help()
{
	return "Help od add komande find\r\n";
}
