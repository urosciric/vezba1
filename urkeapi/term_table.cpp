#include "pch.h"
#include "term_table.h"
#include "ansi_codes.h"

namespace urke
{

void rx_dump_table(const rx_table_type& table, std::ostream& out, bool column_names, bool dot_lines, const char table_frame)
{
	if (table.empty())
		return;

	const size_t col_diff = 2;

	const char option = table_frame;

	out << ANSI_CUR(0, 0);

	size_t columns_number = 0;
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

	size_t pom = 0;

	size_t width_pom = 0;
	///////

	if (option == '-')
	{
		for (size_t i = 0; i < columns_number; i++)
			first_line += (widths[i] + col_diff + 3);

		out << '+';

		for (size_t i = 1; i < first_line; i++)
		{
			if (widths[pom] + 5 + pom * 5 + width_pom == i)
			{
				out << '+';
				width_pom += widths[pom];
				pom++;
			}
			else
			{
				out << option;
			}
		}

		out << '+' << "\r\n";
	}

	else
	{
		for (size_t i = 0; i < columns_number; i++)
			first_line += (widths[i] + col_diff);

		for (size_t i = 1; i < first_line + 5 + (columns_number - 1) * 5; i++)
			out << ' ';

		out << "\r\n";
	}

	///////

	pom = 0;
	width_pom = 0;

	for (const auto& row : table)
	{
		if (!first)
			out << "\r\n";
		if (!row.empty())
		{

			if (option == '-')
				out << ANSI_COLOR_GRAY << "|  " << ANSI_COLOR_RESET;
			else
				out << "   ";

			for (size_t i = 0; i < columns_number; i++)
			{
				if (i != 0 && option == '-')
				{
					out << "|  ";
				}
				string_type rest(widths[i] + col_diff - row[i].value.size(),
					i == columns_number - 1 || first || row[i].value.empty()
					? ' ' : empty_char);

				if (!row[i].prefix.empty())
					out << row[i].prefix;
				out << row[i].value;
				if (!row[i].postfix.empty())
					out << row[i].postfix;
				if (empty_char == '.')
				{
					for (int i = 0; i < rest.size() - 2; i++)
						out << '.';
					if (i != columns_number - 1) out << "  ";
				}
				else
				{
					out << rest;
				}

			}

			if (option == '-')
			{
				out << ANSI_COLOR_GRAY << "  |" << ANSI_COLOR_RESET;
			}
			else
			{
				for (size_t i = 0; i < (columns_number - 1) * 5 + 3; i++) out << " ";
			}

		}
		if (first)
			first = false;
		if (column_names)
		{
			out << "\r\n";
			size_t total_width = 0;
			for (size_t i = 0; i < columns_number; i++)
				total_width += (widths[i] + col_diff);

			if (option == '-') out << '+';
			else out << ' ';
			string_type rest(total_width + 1 + (columns_number - 2) * 5 , option);
			string_type small_rest(total_width + 2, option);
			if (option == '-')
			{
				for (size_t i = 1; i < first_line; i++)
				{
					if (widths[pom] + 5 + pom * 5 + width_pom == i)
					{
						out << '+';
						width_pom += widths[pom];
						pom++;
					}
					else
					{
						out << option;
					}
				}
			}
			else
			{
				out << ANSI_COLOR_GRAY << small_rest << ANSI_COLOR_RESET;
				for (size_t i = small_rest.size(); i < rest.size(); i++) out << ' ';
			}
			if (option == '-') out << '+';
			else out << ' ';
			column_names = false;
		}
		pom++;
		/*if (option != '-')
		{
			for (size_t i = 0; i < (columns_number - 1) * 5; i++) out << " ";
		}*/
	}

	pom = 0;
	width_pom = 0;

	out << "\r\n";

	if (table.size() != 1)
	{

		if (option == '-')
		{
			out << '+';

			for (size_t i = 1; i < first_line; i++)
			{
				if (widths[pom] + 5 + pom * 5 + width_pom == i)
				{
					out << '+';
					width_pom += widths[pom];
					pom++;
				}
				else
				{
					out << option;
				}
			}

			out << '+' << "\r\n";
		}

		else
		{

			for (size_t i = 0; i < first_line; i++)
				out << "  ";

			out << "\r\n";

		}
	}

	out << "\r\n" << ANSI_CUR(tabela.size(), 0);
}

} //urke