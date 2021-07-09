#include "term_drawer.h"
#include "ansi_codes.h"
#include "pch.h"

namespace urke
{

	void table_drawer::drawer(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 0, 0);

		size_t i = 0;

		for (auto& row : table)
		{

			i = 0;
			for (auto& cell : row)
			{
				if (cell.value.size() <= ret[i].width)
				{
					if (tto.options == 1)
					{
						out << cell.value;

						for (size_t j = cell.value.size(); j < ret[i].width; j++)
							out << ' ';
					}
					// if text is to the left

					if (tto.options == 2)
					{
						for (size_t j = cell.value.size(); j < ret[i].width; j++)
							out << ' ';

						out << cell.value;
					}
					// if text is to the right

					if (tto.options == 3)
					{
						for (size_t j = cell.value.size(); j < ret[i].width; j += 2)
							out << ' ';

						out << cell.value;

						for (size_t j = cell.value.size() + 1; j < ret[i].width; j += 2)
							out << ' ';
					}
					// if text is in the center

				}
				//if cell size is smaler than max width of that column it will draw the whole thing

				else
				{
					if (tto.options == 1)
					{
						for (size_t j = 0; j < ret[i].width; j++)
							out << cell.value[j];
					}
					// if text is to the left

					if (tto.options == 2)
					{
						for (size_t j = cell.value.size() - ret[i].width; j < cell.value.size(); j++)
							out << cell.value[j];
					}
					// if text is to the right

					if (tto.options == 3)
					{
						for (size_t j = 0; j < ret[i].width; j++)
							out << cell.value[j];
					}
					// if text is in the center
				}
				//if cell size is larger than max width it will draw just the part that can fit

				i++;

				out << "   ";
			}

			out << "\r\n";
		}
	}

	void table_drawer::frame(term_table_options& tto, std::ostream& out)
	{
		//printf("%c[%d;%df", 0x1B, 0, 0);

		// puts cursor at the beginning

	}

	void table_drawer::dots(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 1, 1);

		size_t i = 0;

		int cursor_x_temporary = 0;
		int cursor_x = 1;
		int cursor_y = 1;

		for (auto& row : table)
		{
			i = 0;
			for (auto& cell : row)
			{
				if (tto.options == 1)
				{
					if (ret[i].width - 2 < cell.value.size())
					{
						cursor_x += ret[i].width - 2;
						cursor_x_temporary = ret[i].width - 2;
					}
					else
					{
						cursor_x += cell.value.size();
						cursor_x_temporary = cell.value.size();
					}
					printf("%c[%d;%df", 0x1B, cursor_y, cursor_x);
					while (cursor_x_temporary < ret[i].width)
					{
						out << ".";
						cursor_x++;
						cursor_x_temporary++;
					}
					cursor_x += 3;
				}
				// if text is to the left

				else if (tto.options == 2)
				{
					printf("%c[%d;%df", 0x1B, cursor_y, cursor_x);

					if (ret[i].width - 2 < cell.value.size())
					{
						cursor_x += ret[i].width - 2;
						cursor_x_temporary = ret[i].width - 2;
					}
					else
					{
						cursor_x += cell.value.size();
						cursor_x_temporary = cell.value.size();
					}

					while (cursor_x_temporary < ret[i].width)
					{
						out << ".";
						cursor_x++;
						cursor_x_temporary++;
					}

					cursor_x += 3;				
				}
				// if text is to the right

				else if (tto.options == 3)
				{
					printf("%c[%d;%df", 0x1B, cursor_y, cursor_x);

					if (ret[i].width - 2 < cell.value.size())
					{
						cursor_x += ret[i].width - 2;
						cursor_x_temporary = ret[i].width - 2;
					}
					else
					{
						cursor_x += cell.value.size();
						cursor_x_temporary = cell.value.size();
					}

					while (cursor_x_temporary <= ret[i].width/2+2)
					{
						out << ".";
						cursor_x++;
						cursor_x_temporary++;
					}

					printf("%c[%d;%df", 0x1B, cursor_y, cursor_x);

					while (cursor_x_temporary <= ret[i].width/2+1)
					{
						out << ".";
						cursor_x++;
						cursor_x_temporary++;
					}
					cursor_x += 3;
				}
				// if text is in the center

				i++;
			}
			cursor_y++;
			cursor_x = 1;
		}
	}

	void table_drawer::clearer(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 0, 0);
		for (size_t i = 0; i < table[0].size() + 2; i++)
		{
			for (size_t j = 0; j < tto.max_width + ret.size() * 3; j++)
			{
				out << " ";
			}
			out << "\r\n";
		}
	}

} //urke
