#pragma once

namespace parser
{

struct parser_option
{
	char short_option;
	string_type long_option;
	string_type help_text;
};

struct int_option : public parser_option
{
	int* value;
};

struct string_option : public parser_option
{
	string_type* value;
};


class parser3000
{
	std::vector<parser_option> bit_options;
	std::vector<int_option> int_options;
	std::vector<string_option> string_options;
public:
	void add_bit_option(const parser_option& opt);
	void add_int_option(const parser_option& opt);
	void add_string_option(const parser_option& opt);

	bool parse(std::istream& in, std::ostream& err);

};



} // parser