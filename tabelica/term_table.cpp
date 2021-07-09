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

	void rx_dump_table(const rx_table_type& table, std::ostream& out,const term_table_options& options)
	{
		columns_creator cc;
		table_drawer td;
		term_table_options tto;
		
		std::vector<table_header> ret = cc.create_headers(table, options);

		cc.create_headers(table, options);
		td.drawer(options, table, ret, std::cout);
		td.frame(tto, std::cout);
		td.dots(options, table, ret, std::cout);

		out << "\r\n";
		system("pause");

		td.clearer(options, table, ret, std::cout);
	}

} //urke