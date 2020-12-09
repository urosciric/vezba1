#pragma once


namespace urke
{

struct rx_table_cell_struct
{
	rx_table_cell_struct(const string_type& vvalue)
		: value(vvalue)
	{
	}
	rx_table_cell_struct(const string_type& vvalue, const string_type& vprefix, const string_type& vpostfix)
		: prefix(vprefix), value(vvalue), postfix(vpostfix)
	{
	}
	rx_table_cell_struct(const rx_table_cell_struct& right) = default;
	rx_table_cell_struct(rx_table_cell_struct&& right) noexcept = default;
	string_type prefix;
	string_type value;
	string_type postfix;
};

typedef std::vector<rx_table_cell_struct> rx_row_type;
typedef std::vector<rx_row_type> rx_table_type;


void rx_dump_table(const rx_table_type& table, std::ostream& out, bool column_names, bool dot_lines);


} //urke