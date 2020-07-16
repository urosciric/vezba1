#include "pch.h"
#include "commands.h"
#include "commands_manager.h"

string_type command_base::get_help()
{
	string_type ret = "Komanda ";
	ret += get_name();
	ret += " nema help!";
	return ret;
}

string_type help_command::get_name()
{
	return "help";
}
string_type help_command::get_help()
{
	return
		"Ovo je help komanda koja prikazuje pomoc\r\n"
		"Koriscenje\r\n"
		"urke_phone help <sub_command>\r\n"
		"gde je <sub_command> ime komande za koju se trazi pomoc\r\n";

}
void help_command::do_command(std::istream& in, phone_book& phonedb)
{
	string_type sub_command;
	in >> sub_command;
	if (sub_command.empty())
		print_global_help();
	else
		print_command_help(sub_command);
}
void help_command::print_global_help()
{
	std::cout
		<< "Ovo je najbolji telefonski imenik na svetu\r\n"
		<< "==========================================\r\n"
		<< "Koriscenje\r\n"
		<< "urke_phone <sub_command> <parametri>\r\n";

	std::cout
		<< "Spisak podkomandi:\r\n";
	auto commands = commands_manager::instance().get_commands_list();
	for (auto one : commands)
	{
		std::cout << one->get_name() << "\r\n";
	}
}
void help_command::print_command_help(const string_type& name)
{
	auto sub_command = commands_manager::instance().get_command(name);
	if (sub_command)
		std::cout << sub_command->get_help() << "\r\n";
}