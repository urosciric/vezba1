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

	void parser3000::add_uint_option(const uint_option& opt)
	{
		uint_options.emplace_back(opt);
	}

	void parser3000::add_float_option(const float_option& opt)
	{
		float_options.emplace_back(opt);
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
		string_type int_temp = "";
		string_type uint_temp = "";
		string_type float_temp = "";
		char current;
		while (!in.eof())
		{
			bad = 0;
			form = "";
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
				{
					if (bit_options[i].short_option == '\0')
						continue;
					if (form[0] == bit_options[i].short_option)
					{
						bad++;
						*bit_options[i].value = true;
						break;
					}
				}
				//for bit options
				for (unsigned int i = 0; i < int_options.size(); i++)
				{
					if (int_options[i].short_option == '\0')
						continue;
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
							int_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for int options
				for (unsigned int i = 0; i < uint_options.size(); i++)
				{
					if (uint_options[i].short_option == '\0')
						continue;
					if (form[0] == uint_options[i].short_option)
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
							uint_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for unsigned int options
				for (unsigned int i = 0; i < float_options.size(); i++)
				{
					if (float_options[i].short_option == '\0')
						continue;
					if (form[0] == float_options[i].short_option)
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
							uint_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for double options
				for (unsigned int i = 0; i < string_options.size(); i++)
				{
					if (string_options[i].short_option == '\0')
						continue;
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
							string_options[i].value->push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for string options
				bad--;
				if (bad != 0)
					return false;
				temp = 0;
			}
			//////////////////////short form
			else if (current != '-' && current != ' ' && temp == 2)
			{
				while (!in.eof() && current != ' ')
				{
					form.push_back(current);
					in.get(current);
				}
				for (unsigned int i = 0; i < bit_options.size(); i++)
				{
					if (bit_options[i].long_option == nullptr)
						continue;
					if (form == bit_options[i].long_option)
					{
						bad++;
						*bit_options[i].value = true;
						break;
					}
				}
				//for bit options
				for (unsigned int i = 0; i < int_options.size(); i++)
				{
					if (int_options[i].long_option == nullptr)
						continue;
					if (form == int_options[i].long_option)
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
							int_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for int options
				for (unsigned int i = 0; i < uint_options.size(); i++)
				{
					if (uint_options[i].long_option == nullptr)
						continue;
					if (form == uint_options[i].long_option)
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
							uint_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for unsigned int options
				for (unsigned int i = 0; i < float_options.size(); i++)
				{
					if (float_options[i].long_option == nullptr)
						continue;
					if (form == float_options[i].long_option)
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
							uint_temp.push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for double options
				for (unsigned int i = 0; i < string_options.size(); i++)
				{
					if (string_options[i].long_option == nullptr)
						continue;
					if (form == string_options[i].long_option)
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
							string_options[i].value->push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for string options
				bad--;
				if (bad != 0)
					return false;
				temp = 0;
			}
			//////////////////////long form
		}
		return true;
	}

} // parser