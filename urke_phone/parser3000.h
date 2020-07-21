#pragma once

namespace parser
{

struct parser_option
{
	char short_option = '\0';
	const char* long_option = nullptr;
	const char* help_text = nullptr;
};

struct bit_option : public parser_option
{
	bool* value;
};

struct int_option : public parser_option
{
	int* value;
};

struct uint_option : public parser_option
{
	unsigned int* value;
};

struct float_option : public parser_option
{
	double* value;
};

struct string_option : public parser_option
{
	string_type* value;
};

//////////////////////////////////////////////////////////////////

class parser3000
{

	std::vector<bit_option> bit_options;
	std::vector<int_option> int_options;
	std::vector<uint_option> uint_options;
	std::vector<float_option> float_options;
	std::vector<string_option> string_options;
public:
	void add_bit_option(const bit_option& opt);
	void add_int_option(const int_option& opt);
	void add_uint_option(const uint_option& opt);
	void add_float_option(const float_option& opt);
	void add_string_option(const string_option& opt);


	bool parse(std::istream& in, std::ostream& err);
	
private:
	int to_int_parser(const string_type& what);
	unsigned int to_uint_parser(const string_type& what);
	double to_float_parser(const string_type& what);
};


} // parser