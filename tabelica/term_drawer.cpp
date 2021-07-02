#include "term_drawer.h"
#include "pch.h"

namespace urke
{

	void table_drawer::drawer(const rx_table_type& table, const std::vector<table_header> ret, std::ostream& out)
	{

		size_t i = 0;

		for (auto& row : table)
		{

			i = 0;
			for (auto& cell : row)
			{
				if (cell.value.size() <= ret[i].width)
				{
					out << cell.value;

					for (size_t j = cell.value.size(); j < ret[i].width; j++)
						out << ' ';
				}
				//if cell size is smaler than max width of that column it will draw the whole thing

				else
				{
					for (size_t j = 0; j < ret[i].width; j++)
						out << cell.value[j];
				}
				//if cell size is larger than max width it will draw just the part that can fit

				i++;

				out << "	";
			}

			out << "\r\n";
		}
	}

} //urke
