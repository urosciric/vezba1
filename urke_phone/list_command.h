#pragma once
#include "commands.h"
class list_command : public command_base
{
public:
	string_type get_name() { return "list"; }
	string_type get_help();
	void do_command(std::istream& in, phone_book& phonedb);
};

