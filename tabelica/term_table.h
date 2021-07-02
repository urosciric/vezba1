#pragma once
#include "pch.h"



namespace urke
{

	struct term_table_options
	{

		bool column_names;
		bool dot_lines;
		char table_frame;
		size_t max_width;
		size_t options;

	};

	enum class justify_style
	{

		left,
		center,
		right

	};

	enum class border_style
	{

		full_grid,
		header_only,
		none

	};

	struct table_stype
	{

		int screen_width;
		border_style border;
		justify_style style;
		bool use_ellipsis;
		bool multiline;

	};

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



	void rx_dump_table(const rx_table_type& table, std::ostream& out, const term_table_options& options);

}
