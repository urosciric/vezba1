#pragma once
#include "commands.h"
#include "phone_book.h"
class finder :
    public command_base
{
public:
	string_type get_name() { return "find"; }
	string_type get_help();
	void do_command(std::istream& in, phone_book& phonedb);
};

