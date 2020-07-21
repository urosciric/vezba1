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
		string_type form = "";
		string_type int_temp = "";
		string_type uint_temp = "";
		string_type float_temp = "";
		size_t bool_temp = 0;
		char current;

		bool wrong = true;

		while (!in.eof())
		{
			form = "";
			if (bool_temp == 0)
				in.get(current);
			bool_temp = 0;
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
						wrong = false;
						*bit_options[i].value = true;
						while (!in.eof() && current == ' ')
							in.get(current);
						if (current != '-')
						{
							err << "Bit option cant have argument!\r\n";
							return false;
						}
						bool_temp = 1;
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{							
							int_temp.push_back(current);
							in.get(current);
						}
						int val;
						if (to_int_parser(int_temp, val))
						{
							*int_options[i].value = val;
						}
						else
						{
							err << "Unable to convert " << int_temp << " to integer value!";
							return false;
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (!(current >= '0' && current <= '9'))
							{
								err << "You need to put in unsigned integer as an argument in unsigned integer option!\r\n";
								return false;
							}
							uint_temp.push_back(current);
							in.get(current);
						}
						*uint_options[i].value = to_uint_parser(int_temp);
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (!(current == '0' || current == '1' || current == '2' || current == '3' || current == '4' || current == '5' || current == '6' || current == '7' || current == '8' || current == '9'))
							{
								err << "You need to put in double float as an argument in float option!\r\n";
								return false;
							}
							float_temp.push_back(current);
							in.get(current);
						}
						*float_options[i].value = to_float_parser(int_temp);
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						if (in.eof())
						{
							err << "String option needs an argument!\r\n";
							return false;
						}
						while (!in.eof() && current != ' ')
						{
							if (current == '-' || in.eof())
							{
								err << "String option needs an argument!\r\n";
								return false;
							}	
							string_options[i].value->push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for string options
				if (wrong)
				{
					err << "Unknown command!\r\n";
					return false;
				}
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
						wrong = false;
						*bit_options[i].value = true;
						while (!in.eof() && current == ' ')
							in.get(current);
						if (current != '-')
						{
							err << "Bit option cant have argument!\r\n";
							return false;
						}
						bool_temp = 1;
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{							
							int_temp.push_back(current);
							in.get(current);
						}
						int val;
						if (to_int_parser(int_temp, val))
						{
							*int_options[i].value = val;
						}
						else
						{
							err << "Unable to convert " << int_temp << " to integer value!";
							return false;
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (!(current == '0' || current == '1' || current == '2' || current == '3' || current == '4' || current == '5' || current == '6' || current == '7' || current == '8' || current == '9'))
							{
								err << "You need to put in unsigned integer as an argument in unsigned integer option!\r\n";
								return false;
							}
							uint_temp.push_back(current);
							in.get(current);
						}
						*uint_options[i].value = to_uint_parser(int_temp);
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						while (!in.eof() && current != ' ')
						{
							if (!(current == '0' || current == '1' || current == '2' || current == '3' || current == '4' || current == '5' || current == '6' || current == '7' || current == '8' || current == '9'))
							{
								err << "You need to put in double float as an argument in float option!\r\n";
								return false;
							}
							float_temp.push_back(current);
							in.get(current);
						}
						*float_options[i].value = to_float_parser(int_temp);
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
						wrong = false;
						do
						{
							in.get(current);
						} while (!in.eof() && current == ' ');
						if (in.eof())
						{
							err << "String option needs an argument!\r\n";
							return false;
						}
						while (!in.eof() && current != ' ')
						{
							if (current == '-')
							{
								err << "String option needs an argument!\r\n";
								return false;
							}	
							string_options[i].value->push_back(current);
							in.get(current);
						}
						break;
					}
				}
				//for string options
				if (wrong)
				{
					err << "Unknown command!\r\n";
					return false;
				}
				temp = 0;
			}
			//////////////////////long form
		}
		if (wrong)
			err << "You didnt put enything!\r\n";
		else
			return true;
	}

	//////////////////////////////////////////////

	bool parser3000::to_int_parser(const string_type& what, int& val)
	{
		errno = 0;
		char* endptr = nullptr;
		long converted = strtol(what.c_str(), &endptr, 10);
		if (errno != 0)
		{
			return false;
		}
		else
		{
			val = (int)converted;
			return true;
		}
	}

	unsigned int parser3000::to_uint_parser(const string_type& what)
	{
		unsigned int converted = stoul(what, nullptr, 0);
		return converted;
	}

	double parser3000::to_float_parser(const string_type& what)
	{
		double converted = stod(what);
		return converted;
	}

} // parser
