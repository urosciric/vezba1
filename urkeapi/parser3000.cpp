#include "pch.h"
#include "parser3000.h"
#include "ansi_codes.h"

namespace urke
{

	namespace parser
	{

		void parser3000::add_bit_option(const bit_option& opt)
		{
			bit_options.emplace_back(opt);
		}

		void parser3000::add_bit_option(char opt, bool* value, const char* help)
		{
			bit_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = nullptr;
			temp.value = value;
			add_bit_option(temp);
		}
		void parser3000::add_bit_option(const char* opt, bool* value, const char* help)
		{
			bit_option temp;
			temp.help_text = help;
			temp.short_option = '\0';
			temp.long_option = opt;
			temp.value = value;
			add_bit_option(temp);
		}
		void parser3000::add_bit_option(char opt, const char* opt_long, bool* value, const char* help)
		{
			bit_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = opt_long;
			temp.value = value;
			add_bit_option(temp);
		}


		///////////////////////////////////////////////////////////////////////////////////////////////////for bit options


		void parser3000::add_int_option(const int_option& opt)
		{
			int_options.emplace_back(opt);
		}

		void parser3000::add_int_option(char opt, int* value, const char* help)
		{
			int_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = nullptr;
			temp.value = value;
			add_int_option(temp);
		}
		void parser3000::add_int_option(const char* opt, int* value, const char* help)
		{
			int_option temp;
			temp.help_text = help;
			temp.short_option = '\0';
			temp.long_option = opt;
			temp.value = value;
			add_int_option(temp);
		}
		void parser3000::add_int_option(char opt, const char* opt_long, int* value, const char* help)
		{
			int_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = opt_long;
			temp.value = value;
			add_int_option(temp);
		}

		/////////////////////////////////////////////////////////////////////////for int options

		void parser3000::add_uint_option(const uint_option& opt)
		{
			uint_options.emplace_back(opt);
		}

		void parser3000::add_uint_option(char opt, unsigned int* value, const char* help)
		{
			uint_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = nullptr;
			temp.value = value;
			add_uint_option(temp);
		}

		void parser3000::add_uint_option(const char* opt, unsigned int* value, const char* help)
		{
			uint_option temp;
			temp.help_text = help;
			temp.short_option = '\0';
			temp.long_option = opt;
			temp.value = value;
			add_uint_option(temp);
		}

		void parser3000::add_uint_option(char opt, const char* opt_long, unsigned int* value, const char* help)
		{
			uint_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = opt_long;
			temp.value = value;
			add_uint_option(temp);
		}

		/////////////////////////////////////////////////////////////////////////for unsigned int options

		void parser3000::add_float_option(const float_option& opt)
		{
			float_options.emplace_back(opt);
		}

		void parser3000::add_float_option(char opt, double* value, const char* help)
		{
			float_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = nullptr;
			temp.value = value;
			add_float_option(temp);
		}

		void parser3000::add_float_option(const char* opt, double* value, const char* help)
		{
			float_option temp;
			temp.help_text = help;
			temp.short_option = '\0';
			temp.long_option = opt;
			temp.value = value;
			add_float_option(temp);
		}

		void parser3000::add_float_option(char opt, const char* opt_long, double* value, const char* help)
		{
			float_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = opt_long;
			temp.value = value;
			add_float_option(temp);
		}

		/////////////////////////////////////////////////////////////////////////for double options

		void parser3000::add_string_option(const string_option& opt)
		{
			string_options.emplace_back(opt);
		}

		void parser3000::add_string_option(char opt, string_type* value, const char* help)
		{
			string_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = nullptr;
			temp.value = value;
			add_string_option(temp);
		}
		void parser3000::add_string_option(const char* opt, string_type* value, const char* help)
		{
			string_option temp;
			temp.help_text = help;
			temp.short_option = '\0';
			temp.long_option = opt;
			temp.value = value;
			add_string_option(temp);
		}
		void parser3000::add_string_option(char opt, const char* opt_long, string_type* value, const char* help)
		{
			string_option temp;
			temp.help_text = help;
			temp.short_option = opt;
			temp.long_option = opt_long;
			temp.value = value;
			add_string_option(temp);
		}
		/////////////////////////////////////////////////////////////////////////for string options
		void parser3000::print_help(const string_type& str, std::ostream& help)
		{
			help << "Usage:\n" << "   " << str << "   [OPTIONS...]\n\n";
			string_type max = "";
			string_type pom;
			for (int i = 0; i < bit_options.size(); i++)
			{
				if (bit_options[i].long_option != nullptr)
				{
					pom = bit_options[i].long_option;
					if (pom.size() > max.size()) max = pom;
				}
			}
			for (int i = 0; i < int_options.size(); i++)
			{
				if (int_options[i].long_option != nullptr)
				{
					pom = int_options[i].long_option;
					if (pom.size() > max.size()) max = pom;
				}
			}
			for (int i = 0; i < uint_options.size(); i++)
			{
				if (uint_options[i].long_option != nullptr)
				{
					pom = uint_options[i].long_option;
					if (pom.size() > max.size()) max = pom;
				}
			}
			for (int i = 0; i < float_options.size(); i++)
			{
				if (float_options[i].long_option != nullptr)
				{
					pom = float_options[i].long_option;
					if (pom.size() > max.size()) max = pom;
				}
			}
			for (int i = 0; i < string_options.size(); i++)
			{
				if (string_options[i].long_option != nullptr)
				{
					pom = string_options[i].long_option;
					if (pom.size() > max.size()) max = pom;
				}
			}
			/////////////////////searching for biggest long option by size
			for (int i = 0; i < bit_options.size(); i++)
			{
				help << "   ";
				if (bit_options[i].short_option == '\0') help << "     ";
				else help << ANSI_COLOR_GREEN ANSI_COLOR_BOLD << "-" << bit_options[i].short_option << ANSI_COLOR_RESET << "   ";
				if (bit_options[i].long_option == nullptr)
				{
					for (int i = 0; i < max.size() + 2; i++) help << " ";
					help << "   ";
				}
				else
				{
					help << ANSI_COLOR_BLUE ANSI_COLOR_BOLD << "--" << bit_options[i].long_option << ANSI_COLOR_RESET;
					pom = bit_options[i].long_option;
					for (int i = 0; i < max.size() - pom.size(); i++) help << " ";
					help << "   ";
				}
				if (bit_options[i].help_text)
					help << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << bit_options[i].help_text << ANSI_COLOR_RESET;
				help << "\n";
			}
			///////////print for bit
			for (int i = 0; i < int_options.size(); i++)
			{
				help << "   ";
				if (int_options[i].short_option == '\0') help << "     ";
				else help << ANSI_COLOR_GREEN ANSI_COLOR_BOLD << "-" << int_options[i].short_option << ANSI_COLOR_RESET << "   ";
				if (int_options[i].long_option == nullptr)
				{
					for (int i = 0; i < max.size() + 2; i++) help << " ";
					help << "   ";
				}
				else
				{
					help << ANSI_COLOR_BLUE ANSI_COLOR_BOLD << "--" << int_options[i].long_option << ANSI_COLOR_RESET;
					pom = int_options[i].long_option;
					for (int i = 0; i < max.size() - pom.size(); i++) help << " ";
					help << "   ";
				}
				if (int_options[i].help_text)
					help << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << int_options[i].help_text << ANSI_COLOR_RESET;
				help << "\n";
			}
			///////////print for int
			for (int i = 0; i < uint_options.size(); i++)
			{
				help << "   ";
				if (uint_options[i].short_option == '\0') help << "     ";
				else help << ANSI_COLOR_GREEN ANSI_COLOR_BOLD << "-" << uint_options[i].short_option << ANSI_COLOR_RESET << "   ";
				if (uint_options[i].long_option == nullptr)
				{
					for (int i = 0; i < max.size() + 2; i++) help << " ";
					help << "   ";
				}
				else
				{
					help << ANSI_COLOR_BLUE ANSI_COLOR_BOLD << "--" << uint_options[i].long_option << ANSI_COLOR_RESET;
					pom = uint_options[i].long_option;
					for (int i = 0; i < max.size() - pom.size(); i++) help << " ";
					help << "   ";
				}
				if (uint_options[i].help_text)
					help << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << uint_options[i].help_text << ANSI_COLOR_RESET;
				help << "\n";
			}
			///////////print for uint
			for (int i = 0; i < float_options.size(); i++)
			{
				help << "   ";
				if (float_options[i].short_option == '\0') help << "     ";
				else help << ANSI_COLOR_GREEN ANSI_COLOR_BOLD << "-" << float_options[i].short_option << ANSI_COLOR_RESET << "   ";
				if (float_options[i].long_option == nullptr)
				{
					for (int j = 0; j < max.size() + 2; j++) help << " ";
					help << "   ";
				}
				else
				{
					help << ANSI_COLOR_BLUE ANSI_COLOR_BOLD << "--" << float_options[i].long_option << ANSI_COLOR_RESET;
					pom = float_options[i].long_option;
					for (int j = 0; j < max.size() - pom.size(); j++) help << " ";
					help << "   ";
				}
				if (float_options[i].help_text)
					help << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << float_options[i].help_text << ANSI_COLOR_RESET;
				help << "\n";
			}
			///////////print for float
			for (int i = 0; i < string_options.size(); i++)
			{
				help << "   ";
				if (string_options[i].short_option == '\0') help << "     ";
				else help << ANSI_COLOR_GREEN ANSI_COLOR_BOLD << "-" << string_options[i].short_option << ANSI_COLOR_RESET << "   ";
				if (string_options[i].long_option == nullptr)
				{
					for (int i = 0; i < max.size() + 2; i++) help << " ";
					help << "   ";
				}
				else
				{
					help << ANSI_COLOR_BLUE ANSI_COLOR_BOLD << "--" << string_options[i].long_option << ANSI_COLOR_RESET;
					pom = string_options[i].long_option;
					for (int i = 0; i < max.size() - pom.size(); i++) help << " ";
					help << "   ";
				}
				if (string_options[i].help_text)
					help << ANSI_COLOR_YELLOW ANSI_COLOR_BOLD << string_options[i].help_text << ANSI_COLOR_RESET;
				help << "\n";
			}
			///////////print for string
			/////////////////////printing help
		}
		/////////////////////////////////////////////////////////////////////////for help
		bool parser3000::parse(std::istream& in, std::ostream& err)
		{
			size_t temp = 0;
			string_type form = "";
			string_type int_temp = "";
			string_type uint_temp = "";
			string_type float_temp = "";
			size_t bool_temp = 0;

			char current;

			int val1;
			unsigned int val2;
			double val3;

			bool wrong = true;

			while (!in.eof())
			{
				wrong = true;
				form = "";
				if (bool_temp == 0)
					in.get(current);
				bool_temp = 0;
				if (current == '-')
					temp++;
				else if (current != '-' && current != ' ' && current != '	' && temp == 1)
				{
					while (!in.eof() && current != ' ' && current != '	')
					{
						form.push_back(current);
						in.get(current);
					}
					for (unsigned int i = 0; i < bit_options.size(); i++)
					{
						if (bit_options[i].short_option == '\0')
							continue;
						for (int j = 0; j < form.size(); j++)
						{
							if (form[j] == bit_options[i].short_option)
							{
								wrong = false;
								if (*bit_options[i].value == true)
								{
									err << "You can't put 2 same commands!";
									return false;
								}
								*bit_options[i].value = true;
								while (!in.eof() && (current == ' ' || current == '	'))
									in.get(current);
								if (current != '-' && !in.eof())
								{
									err << "Bit option cant have argument!";
									return false;
								}
								bool_temp = 1;
							}
						}
					}
					//for bit options
					for (unsigned int i = 0; i < int_options.size(); i++)
					{
						if (int_options[i].short_option == '\0')
							continue;
						if (form[form.size() - 1] == int_options[i].short_option)
						{
							wrong = false;
							do
							{
								in.get(current);
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								int_temp.push_back(current);
								in.get(current);
							}
							if (to_int_parser(int_temp, val1))
							{
								if (int_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
								*int_options[i].value = val1;
							}
							else
							{
								err << "Unable to convert " << int_temp << " to integer value!";
								return false;
							}
							break;
						}
					}
					int_temp = "";
					//for int options
					for (unsigned int i = 0; i < uint_options.size(); i++)
					{
						if (uint_options[i].short_option == '\0')
							continue;
						if (form[form.size() - 1] == uint_options[i].short_option)
						{
							wrong = false;
							do
							{
								in.get(current);
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								uint_temp.push_back(current);
								in.get(current);
							}
							if (to_uint_parser(uint_temp, val2))
							{
								if (uint_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
								*uint_options[i].value = val2;
							}
							else
							{
								err << "Unable to convert " << uint_temp << " to unsigned integer value!";
								return false;
							}
							break;
						}
					}
					uint_temp = "";
					//for unsigned int options
					for (unsigned int i = 0; i < float_options.size(); i++)
					{
						if (float_options[i].short_option == '\0')
							continue;
						if (form[form.size() - 1] == float_options[i].short_option)
						{
							wrong = false;
							do
							{
								in.get(current);
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								float_temp.push_back(current);
								in.get(current);
							}
							if (to_float_parser(float_temp, val3))
							{
								if (float_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
								*float_options[i].value = val3;
							}
							else
							{
								err << "Unable to convert " << float_temp << " to double value!";
								return false;
							}
							break;
						}
					}
					float_temp = "";
					//for double options
					for (unsigned int i = 0; i < string_options.size(); i++)
					{
						if (string_options[i].short_option == '\0')
							continue;
						if (form[form.size() - 1] == string_options[i].short_option)
						{
							wrong = false;
							do
							{
								in.get(current);
							} while (!in.eof() && (current == ' ' || current == '	'));
							if (in.eof())
							{
								err << "String option needs an argument!";
								return false;
							}
							while (!in.eof() && current != ' ' && current != '	')
							{
								if (current == '-' || in.eof())
								{
									err << "String option needs an argument!";
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
						err << "Unknown command!";
						return false;
					}
					temp = 0;
				}
				//////////////////////short form
				else if (current != '-' && current != ' ' && current != '	' && temp == 2)
				{
					while (!in.eof() && current != ' ' && current != '	')
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
							if (*bit_options[i].value == true)
							{
								err << "You can't put 2 same commands!";
								return false;
							}
							*bit_options[i].value = true;
							while (!in.eof() && (current == ' ' || current == '	'))
								in.get(current);
							if (current != '-' && !in.eof())
							{
								err << "Bit option cant have argument!";
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
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								int_temp.push_back(current);
								in.get(current);
							}
							int val;
							if (to_int_parser(int_temp, val))
							{
								if (int_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
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
					int_temp = "";
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
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								uint_temp.push_back(current);
								in.get(current);
							}
							if (to_uint_parser(uint_temp, val2))
							{
								if (uint_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
								*uint_options[i].value = val2;
							}
							else
							{
								err << "Unable to convert " << uint_temp << " to unsigned integer value!";
								return false;
							}
							break;
						}
					}
					uint_temp = "";
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
							} while (!in.eof() && (current == ' ' || current == '	'));
							while (!in.eof() && current != ' ' && current != '	')
							{
								float_temp.push_back(current);
								in.get(current);
							}
							if (to_float_parser(float_temp, val3))
							{
								if (float_temp.empty())
								{
									err << "There is no argument";
									return false;
								}
								*float_options[i].value = val3;
							}
							else
							{
								err << "Unable to convert " << float_temp << " to double value!";
								return false;
							}
							break;
						}
					}
					float_temp = "";
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
							} while (!in.eof() && (current == ' ' || current == '	'));
							if (in.eof())
							{
								err << "String option needs an argument!";
								return false;
							}
							while (!in.eof() && current != ' ' && current != '	')
							{
								if (current == '-')
								{
									err << "String option needs an argument!";
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
						err << "Unknown command!";
						return false;
					}
					temp = 0;
				}
				//////////////////////long form
			}
			if (wrong)
			{
				err << "You didnt put enything!";
				return true;
			}
			else
			{
				return true;
			}
		}

		//////////////////////////////////////////////

		bool parser3000::to_int_parser(const string_type& what, int& val)
		{
			errno = 0;
			char* endptr = nullptr;
			long converted = strtol(what.c_str(), &endptr, 10);
			if (endptr == nullptr || *endptr != '\0' || errno != 0)
			{
				return false;
			}
			else
			{
				val = (int)converted;
				return true;
			}
		}

		bool parser3000::to_uint_parser(const string_type& what, unsigned int& val)
		{
			errno = 0;
			char* endptr = nullptr;
			unsigned long converted = strtoul(what.c_str(), &endptr, 10);
			if (errno != 0)
			{
				return false;
			}
			else
			{
				val = (unsigned int)converted;
				return true;
			}
		}

		bool parser3000::to_float_parser(const string_type& what, double& val)
		{
			errno = 0;
			char* endptr = nullptr;
			double converted = strtod(what.c_str(), &endptr);
			if (errno != 0)
			{
				return false;
			}
			else
			{
				val = converted;
				return true;
			}
		}

	} // parser

} // urke
