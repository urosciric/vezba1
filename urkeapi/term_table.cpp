#include "pch.h"
#include "term_table.h"
#include "ansi_codes.h"
#define MAXN 10000

namespace urke
{

	size_t niz_pom[MAXN];
	size_t niz_max[MAXN];

	void rx_dump_table(const rx_table_type& table, std::ostream& out, bool column_names, bool dot_lines, const char table_frame, size_t max_width, size_t options)
	//void rx_dump_table(const rx_table_type& table, std::ostream& out, const table_stype& settings)
	{
		if (table.empty())
			return;

		const size_t col_diff = 2;

		const char option = table_frame;

		out << ANSI_CUR(0, 0);

		size_t columns_number = 0;

		if (options != 0 && options != 1 && options != 2 && options != 3)
		{
			out << "Options variable is invalid\r\n";
			return;
		}
	
		for (const auto& row : table)
		{
			if (columns_number == 0)
				columns_number = row.size();
			else
			{
				if (!row.empty())
				{// we allow empty rows
					if (columns_number != row.size())
					{
						out << "Error in table format\r\n";
						return;
					}
				}
			}
		}

		// o.k. we checked now so let's calculate columns width
		std::vector<size_t> widths(columns_number);
		for (const auto& row : table)
		{
			if (!row.empty())
			{
				for (size_t i = 0; i < columns_number; i++)
				{
					if (row[i].value.size() > widths[i])
						widths[i] = row[i].value.size();
				}
			}
		}
		char empty_char = dot_lines ? '.' : ' ';
		// now we have all widths
		bool first = true;
		size_t first_line = 0;
		size_t length_for_clear = 0;

		size_t pom = 0;

		size_t width_pom = 0;

		bool max_width_pom = false;

		size_t pom_length = 0;

		//////////////
		//////////////
		//////////////

		for (size_t i = 0; i < widths.size(); i++)
		{
			pom += widths[i];
			niz_pom[i] = widths[i];
		}

		if (pom > max_width)
		{

			size_t pom_max = 0;
			size_t remember = 0;
			bool remember_pom;

			for (size_t i = 0; i < widths.size(); i++)
			{
				remember_pom = true;
				for (size_t j = 0; j < widths.size(); j++)
				{
					if (widths[pom_max] <= widths[j])
					{
						for (size_t m = 0; m < remember; m++)
							if (niz_max[m] == widths[i])
								remember_pom = false;
						if (!remember_pom)
						{
							pom_max = i;
						}
						else
						{
							pom_max = j;
						}

					}
				}
				if ((int)(widths[pom_max] - pom + max_width) >= 6)
				{
 					widths[pom_max] -= pom - max_width;
					
					i = widths.size();
				}
				else
				{

					pom -= widths[pom_max] + 6;
					widths[pom_max] = 6;
					
				}
				niz_max[remember] = widths[pom_max];
			}
		}

		//////////////
		//////////////
		//////////////

		pom = 0;
	
		for (size_t i = 0; i < columns_number; i++)
		{
			length_for_clear += (niz_pom[i] + col_diff + 3);

			pom_length+= (widths[i] + col_diff + 3);
			
		}

		length_for_clear += (columns_number - 1) * 2;

		//////////////

		if (option == '-')
		{
			for (size_t i = 0; i < columns_number; i++)
			{
				
				first_line += (widths[i] + col_diff + 3);
				
			}

			first_line += (columns_number - 1) * 2;

			out << '+';

			for (size_t i = 1; i < first_line; i++)
			{
			
				if (!max_width_pom)
				{
					if (widths[pom] + 3 + pom * 3 + width_pom == i)
					{
						if (pom == widths.size() - 1) max_width_pom = true;
						if (max_width_pom)
						{
							i = first_line;
						}
						else
						{
							out << '+';
							width_pom += widths[pom];
							pom++;
						}
					}
					else
					{
						out << option;
					}
				}
				else
				{
					out << option;
				}
			
			}

			out << '+';

			for (size_t i = 0; i <= length_for_clear - pom_length; i++)
				out << ' ';

		}

		else
		{
			for (size_t i = 0; i < columns_number; i++)
			{
				first_line += (widths[i] + col_diff);
			}

			for (size_t i = 1; i < first_line + 5 + (columns_number - 1) * 5; i++)
				out << ' ';

		
		}

		out << "\r\n";

		///////

		pom = 0;
		width_pom = 0;
		max_width_pom = false;

		size_t length = 0;

		size_t cut_string_pom = 0;
		bool repeat_for_rows = false;

		for (const auto& row : table)
		{
			begin:
			if (!first)
				out << "\r\n";
			if (!row.empty())
			{

				if (option == '-')
					out << ANSI_COLOR_GRAY << "|" << ANSI_COLOR_RESET;
				else
					out << " ";

				for (size_t i = 0; i < columns_number; i++)
				{
					if (i != 0 && option == '-')
					{
						out << "|";
					}

					if (row[i].value.size() > widths[i] - 2) length = widths[i] - 2;
					else length = row[i].value.size();

					string_type rest(widths[i] + col_diff - length,
						i == columns_number - 1 || first || row[i].value.empty()
						? ' ' : empty_char);

					
					
					if (!row[i].prefix.empty())
						out << row[i].prefix;

					/////////////////////////////////////////////////////////////////////
					if (options == 0)
					{
						if (row[i].value.size() >= widths[i])
						{
							for (size_t j = 0; j < length - 3; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "...";
						}
						else if (row[i].value.size() == widths[i] - 1)
						{
							for (size_t j = 0; j < length - 2; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "..";
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;

						////////////////////////////////////////////////////////////////////
						if (empty_char == '.')
						{
							if (widths[i] <= niz_pom[i] - widths[i])
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
							/*else if (widths[i] == niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
							//if (i != columns_number - 1) out << "  ";
						}
						else
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < rest.size() - 2 /* + niz_pom[i] - widths[i]*/; j++)
									out << ' ';
							}
							else if (widths[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "  ";
							}
							else
							{
								for (size_t j = 0; j < rest.size() - widths[i]; j++)
									out << ' ';
							}
							//if (i != columns_number - 1) out << "  ";
						}
						if (i != columns_number) out << "  ";
					}
					////////////////////////////////////////////////////////////////////
					else if (options == 1)
					{
						if (i != columns_number) out << "  ";
						if (empty_char == '.')
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
							else if (widths[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "";
							}
							else
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
						
						}
						else
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << ' ';
							}
							else if (widths[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "  ";
							}
							else
							{
								for (size_t j = 0; j < rest.size() - niz_pom[i] + widths[i]; j++)
									out << ' ';
							}
						}
						////////////////////////////////////////////////////////////////////
						if (row[i].value.size() >= widths[i])
						{
							out << "...";
							for (size_t j = 3; j < length; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4 + 3)
								{
									j = row[i].value.size();
								}
							}
						
						}
						else if (row[i].value.size() == widths[i] - 1)
						{
							out << "..";
							for (size_t j = 2; j < length; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4 + 2)
								{
									j = row[i].value.size();
								}
							}
						
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;

						//if (i != columns_number - 1) out << "  ";
				
					}
					////////////////////////////////////////////////////////////////////
					else if (options == 3)
					{
						if (row[i].value.size() >= widths[i])
						{
							for (size_t j = cut_string_pom; j < length; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
									/*cut_string_pom = j;
									repeat_for_rows = true;*/
								}
							}
							if (!repeat_for_rows)
							{
								cut_string_pom += length;

								if(length*2>row[i].value.size()) repeat_for_rows = true;
							}
							//out << "...";
						}
						else if (row[i].value.size() == widths[i] - 1)
						{
							for (size_t j = 0; j < length; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
									/*cut_string_pom = j;
									repeat_for_rows = true;*/
								}
							}
							//out << "..";
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;

						////////////////////////////////////////////////////////////////////
						if (empty_char == '.')
						{
							if (widths[i] <= niz_pom[i] - widths[i])
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
							/*else if (widths[i] == niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < rest.size() - 2; j++)
									out << '.';
							}
							//if (i != columns_number - 1) out << "  ";
						}
						else
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < rest.size() - 2 /* + niz_pom[i] - widths[i]*/; j++)
									out << ' ';
							}
							else if (widths[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "  ";
							}
							else
							{
								for (size_t j = 0; j < rest.size() - widths[i]; j++)
									out << ' ';
							}
							//if (i != columns_number - 1) out << "  ";
						}
						if (i != columns_number) out << "  ";
					}
					////////////////////////////////////////////////////////////////////
					else
					{
						if (i != columns_number) out << " ";
						if (empty_char == '.')
						{
							if (widths[i] <= niz_pom[i])
							{
								if ((rest.size() - 2) % 2 == 0)
								{
									for (size_t j = 0; j < (rest.size() - 2) / 2; j++)
										out << '.';
								}
								else
								{
									for (size_t j = 0; j < (rest.size() - 2) / 2 + 1; j++)
										out << '.';
								}
							}
							/*else if (widths[i] > niz_pom[i] && row[i].value.size() >= niz_pom[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (rest.size() - 2) / 2; j++)
									out << '.';
								if (rest.size() % 2 != 0) out << " ";
							}

						}
						else
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < (rest.size() - 2) / 2; j++)
									out << ' ';
							}
							/*else if (widths[i] > niz_pom[i] && row[i].value.size() >= niz_pom[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (rest.size()) / 2; j++)
									out << ' ';
							}
						}
						////////////////////////////////////////////////////////////////////
						if (row[i].value.size() >= widths[i])
						{
							for (size_t j = 0; j < length - 3; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "...";
						}
						else if (row[i].value.size() == widths[i] - 1)
						{
							for (size_t j = 0; j < length - 2; j++)
							{
								out << row[i].value[j];
								if (j == widths[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "..";
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;
						////////////////////////////////////////////////////////////////////
						if (empty_char == '.')
						{
							if (widths[i] <= niz_pom[i])
							{
								if(rest.size() - 2 != 1)
									for (size_t j = 0; j < (rest.size() - 2) / 2; j++)
										out << '.';
									//if (rest.size() % 2 != 0) out << " ";
						
							}
						/*	else if (widths[i] > niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (rest.size() - 2) / 2 + 1; j++)
									out << '.';
							}

						}
						else
						{
							if (widths[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < (rest.size() - 2) / 2; j++)
									out << ' ';
								if (rest.size() % 2 != 0) out << " ";
							}
					/*		else if (widths[i] > niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << " ";
							}*/
							else
							{
								for (size_t j = 0; j < (rest.size()) / 2; j++)
									out << ' ';
								if (rest.size() % 2 != 0) out << " ";
							}
						}


						if (i != columns_number) out << " ";

					}
					////////////////////////////////////////////////////////////////////

				}

				if (option == '-')
				{
					out << ANSI_COLOR_GRAY << "|" << ANSI_COLOR_RESET;
				}
				else
				{
					out << "";
				}

			}
			if (first)
				first = false;
			if (column_names)
			{
				for (size_t i = 0; i <= length_for_clear - pom_length + 3; i++)
					out << ' ';
				out << "\r\n";
				size_t total_width = 0;
				for (size_t i = 0; i < columns_number; i++)
				{
					total_width += (widths[i] + col_diff);
				}

				if (option == '-') out << '+';
				else out << ' ';
				string_type rest(total_width + 1 + (columns_number - 2) * 5 , option);
				string_type small_rest(total_width + 2, option);

				if (option == '-')
				{
					for (size_t i = 1; i < first_line; i++)
					{
						if (widths[pom] <= max_width)
						{
							if (!max_width_pom)
							{
								if (widths[pom] + 3 + pom * 3 + width_pom == i)
								{
									if (pom == widths.size() - 1) max_width_pom = true;

									if (max_width_pom)
									{
										i = first_line;
									}
									else
									{
										out << '+';
										width_pom += widths[pom];
										pom++;
									}
								}
								else
								{
									out << option;
								}
							}
							else
							{
								out << option;
							}
						}
						else
						{
							if (!max_width_pom)
							{
								if (max_width + 3 + pom * 3 + width_pom == i)
								{
									if (pom == widths.size() - 1) max_width_pom = true;
									if (max_width_pom)
									{
										i = first_line;
									}
									else
									{
										out << '+';
										width_pom += max_width;
										pom++;
									}

								}
								else
								{
									out << option;
								}
							}
							else
							{
								out << option;
							}
						}
					}
				}
				else if (total_width >= columns_number * max_width)
				{
					out << ANSI_COLOR_GRAY << small_rest << ANSI_COLOR_RESET;
					for (size_t i = small_rest.size(); i < rest.size(); i++) out << ' ';
				}
				else if (total_width < columns_number * max_width)
				{
			
					out << ANSI_COLOR_GRAY << small_rest << ANSI_COLOR_RESET;
					for (size_t i = rest.size(); i < rest.size(); i++) out << ' ';
			
				}
				if (option == '-') out << '+';
				else out << ' ';
				column_names = false;

			}
			pom++;
			for (size_t i = 0; i <= length_for_clear - pom_length + 3; i++)
				out << ' ';


			
			if (repeat_for_rows)
			{
				if (cut_string_pom * 2 < length * 2)
				{
					repeat_for_rows = false;
					cut_string_pom = 0;
				}
				goto begin;
			}
		}

		pom = 0;
		width_pom = 0;
		max_width_pom = false;

		out << "\r\n";

		if (table.size() != 1)
		{

			if (option == '-')
			{
				out << '+';

				for (size_t i = 1; i < first_line; i++)
				{
					if (widths[pom] <= max_width)
					{
						if (!max_width_pom)
						{
							if (widths[pom] + 3 + pom * 3 + width_pom == i)
							{
								if (pom == widths.size() - 1) max_width_pom = true;

								if (max_width_pom)
								{
									i = first_line;
								}
								else
								{
									out << '+';
									width_pom += widths[pom];
									pom++;
								}
							}
							else
							{
								out << option;
							}
						}
						else
						{
							out << option;
						}
					}
					else
					{
						if (!max_width_pom)
						{
							if (max_width + 3 + pom * 3 + width_pom == i)
							{
								if (pom == widths.size() - 1) max_width_pom = true;
								if (max_width_pom)
								{
									i = first_line;
								}
								else
								{
									out << '+';
									width_pom += max_width;
									pom++;
								}

							}
							else
							{
								out << option;
							}
						}
						else
						{
							out << option;
						}
					}
				}

				out << '+';
			}

			else
			{

				for (size_t i = 0; i < first_line; i++)
					out << "  ";


			}

			for (size_t i = 0; i <= length_for_clear - pom_length; i++)
				out << ' ';
		}

		out << "\r\n" << ANSI_CUR(tabela.size(), 0);
	}

} //urke