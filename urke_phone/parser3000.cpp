#include "pch.h"
#include "parser3000.h"

namespace parser
{

	void parser3000::add_bit_option(const bit_option& opt)
	{
		bit_options.emplace_back(opt);
	}

	void parser3000::add_int_option(const int_option& opt)
	{
		int_options.emplace_back(opt);
	}

	void parser3000::add_string_option(const string_option& opt)
	{
		string_options.emplace_back(opt);
	}
	/////////////////////////////////////////////////////////////////////////
	bool parser3000::parse(std::istream& in, std::ostream& err)
	{
		size_t temp = 0;
		size_t bad = 0;
		string_type form = "";
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
				for (unsigned int i = 0; i < bit_options.size(); i++)
					if (form[0] == bit_options[i].short_option)
						bad++;
				//for bit options
				for (unsigned int i = 0; i < int_options.size(); i++)
					if (form[0] == int_options[i].short_option)
					{
						bad++;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (!(current == '0' || current == '1' || current == '2' || current == '3' || current == '4' || current == '5' || current == '6' || current == '7' || current == '8' || current == '9'))
								bad++;
							in.get(current);
						}
					}
				//for int options
				for (unsigned int i = 0; i < string_options.size(); i++)
					if (form[0] == string_options[i].short_option)
					{
						bad++;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (current == '-')
								bad++;
							in.get(current);
						}
					}
				//for string options
				bad--;
				if (bad != 0)
					return false;
			}
		}
		return true;
	}

} // parser