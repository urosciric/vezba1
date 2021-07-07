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
				{
					max_widths[col] = cell.value.size();
				}
				
				col++;
			}
		}
		//finding max_widths of all columns

		size_t max_max_width = 0;
		size_t pom_pos = 0;
		int for_if_bellow = 0;

		for (size_t i = 0; i < max_widths.size(); i++) max_max_width += max_widths[i];

		while (max_max_width > o.max_width)
		{
			pom_pos = 0;

			for (size_t i = 0; i < max_widths.size(); i++)
			{
				if (max_widths[pom_pos] < max_widths[i])
				{
					pom_pos = i;
				}
			}

			for_if_bellow = max_widths[pom_pos] - 5 + o.max_width - max_max_width;
			if (for_if_bellow >= 0)
			{
				max_widths[pom_pos] -= max_max_width - o.max_width + 5;
				max_max_width = o.max_width;
			}
			else
			{
				max_max_width -= max_widths[pom_pos] - 5;
				max_widths[pom_pos] = 5;	
			}
		}
		//cutting columns to fit in max_width

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
