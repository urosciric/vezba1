#pragma once
#include "phone_book.h"

class command_base
{
public:
	virtual ~command_base() = default;

	virtual string_type get_name() = 0;
	virtual string_type get_help() = 0;
	virtual void do_command(std::istream& in, phone_book& phonedb) = 0;
};

class help_command : public command_base
{
public:
	string_type get_name();
	virtual string_type get_help();
	virtual void do_command(std::istream& in, phone_book& phonedb);
private:
	void print_global_help();
	void print_command_help(const string_type& name);
};



