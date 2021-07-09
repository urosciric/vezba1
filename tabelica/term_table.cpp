#include "pch.h"
#include "term_table.h"
#include "ansi_codes.h"
#include "columns_creator.h"
#include "term_drawer.h"
#define MAXN 10000

namespace urke
{

	struct context
	{

		char option;
		size_t columns_number;
		size_t first_line;
		size_t col_diff;
		size_t width_pom;
		bool max_width_pom;
		size_t length_for_clear;
		size_t pom_length;
		size_t pom;
		std::vector<size_t>* widths;
		size_t length;
		char empty_char;
		std::ostream* out_;
		std::ostream& out()
		{
			return *out_;
		}
		string_type rest;
		rx_row_type* row;

	};

	void rx_dump_table(const rx_table_type& table, std::ostream& out, const term_table_options& options)
	{
		table3000 t3000;
		t3000.set_options(options);
		t3000.display(table, out);
	}

} //urke