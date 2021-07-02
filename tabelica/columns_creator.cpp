#include "pch.h"
#include "columns_creator.h"


namespace urke
{

	std::vector<table_header> columns_creator::create_headers(const rx_table_type& table, const term_table_options& o)
	{
		std::vector<table_header> ret;

		table_header th;

		if (table.empty())
			return ret;

		std::vector<size_t> max_widths(table[0].size());

		for (auto& row : table)
		{
			int col = 0;
			for (auto& cell : row)
			{
				if (max_widths[col] < cell.value.size())
					max_widths[col] = cell.value.size();
				col++;
			}
		}
		int i = 0;
		for (auto& cell : table[0])
		{
			table_header one;
			one.width = (int)max_widths[i];
			if (o.column_names)
			{
				one.disply_string = cell.prefix + cell.value + cell.postfix;
				one.column_name = cell.value;
			}

			ret.emplace_back(one);

			i++;
		}
		return ret;
	}

}
