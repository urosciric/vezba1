#include "term_drawer.h"
#include "ansi_codes.h"
#include "pch.h"

namespace urke
{

	size_t in_case_of_frame = 0;

	void table_drawer::multi_row(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 1, 1);

		size_t i = 0;
		bool breaker = true;
		size_t pom = 0;

		bool more_rows = false;

		std::vector<int> rest(ret.size(), 0);

		for (auto& row : table)
		{
			rest.assign(rest.size(), 0);

			while (true)
			{
				breaker = true;
				i = 0;

				for (auto& cell : row)
				{
					if (rest[i] == -1)
					{
						for (size_t q = 0; q < ret[i].width; q++)
							out << " ";
					}

					pom = 0;
					more_rows = false;

					for (size_t j = rest[i]; j < cell.value.size(); j++)
					{
						
						if (cell.value.size() <= ret[i].width && !more_rows)
						{
							rest[i] = -1;
							out << cell.value;

							for (size_t q = cell.value.size(); q < ret[i].width; q++)
								out << " ";

							break;
						}

						else if (cell.value.size() - j <= ret[i].width && !more_rows)
						{
							rest[i] = -1;

							for (size_t q = j; q < cell.value.size(); q++)
								out << cell.value[q];
							for (size_t q = cell.value.size() - j; q < ret[i].width; q++)
								out << " ";

							break;
						}

						else 
						{
							out << cell.value[j];
							more_rows = true;
						}

						if (pom == ret[i].width - 1)
						{
							if (rest[i] != -1) rest[i] = j + 1;
							break;
						}
						pom++;
					}		

					i++;
					out << "   ";
				}

				out << "\r\n";

				for (size_t j = 0; j < rest.size(); j++)
				{
					if (rest[j] != -1)
					{
						breaker = false;
					}
				}

				if (breaker) break;
			}
		}

	}

	void table_drawer::drawer(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 1, 1);

		size_t i = 0;
		//bool if_hole_needed = true;

		if (tto.table_frame == '-')
		{
			out << "\r\n";
			in_case_of_frame = 2;
		}

		else in_case_of_frame = 0;

		for (auto& row : table)
		{

			i = 0;

			if (tto.table_frame == '-') out << "  ";
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
			if (tto.header)
			{
				out << "\r\n";
				tto.header = false;
			}

			out << "\r\n";
		}
	}

	void table_drawer::frame(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 1, 1);

		// puts cursor at the beginning

		size_t i = 0;

		size_t cursor_x = 1;
		size_t cursor_y = 1;

		if (tto.table_frame == '-')
		{
			for (size_t i = 0; i < tto.max_width + 2 + table[0].size(); i++)
			{
				if (i == 0) out << "/";
				else if (i == tto.max_width + 2 + table[0].size() - 1) out << "\\";
				else out << "-";
			}

			cursor_y++;

			for (auto& row : table)
			{
				i = 0;
				
				for (auto& cell : row)
				{
					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x);

					cursor_x += ret[i].width + 3;
					out << "|";

					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x);

					i++;
				}

				if (tto.header)
				{
					out << "|";

					cursor_y++;
					printf("%c[%zu;%df", 0x1B, cursor_y, 1);

					out << "|";

					for (size_t i = 0; i < tto.max_width + 2 + in_case_of_frame; i++)
					{
						out << "-";
					}

					tto.header = false;
				}

				out << "|";

				cursor_x = 1;
				cursor_y++;
			}

			printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x);
			for (size_t i = 0; i < tto.max_width + 2 + table[0].size(); i++)
			{
				if (i == 0) out << "\\";
				else if (i == tto.max_width + 2 + table[0].size() - 1) out << "/";
				else out << "-";
			}
		}

		else if (tto.table_frame == '=')
		{
			printf("%c[%d;%df", 0x1B, 2, 1);
			
			for (size_t i = 0; i < tto.max_width + 2 + in_case_of_frame; i++)
			{
				out << "=";
			}

			for (auto& row : table)
			{
				cursor_x = 0;
				for (auto& cell : row)
				{
					cursor_x++;
				}
				cursor_y++;
			}

			printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x);
		}
	}

	void table_drawer::dots(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 1, 1);

		size_t i = 0;
		size_t pom = 0;

		bool if_hole_needed = true;

		size_t cursor_x_temporary = 0;
		size_t cursor_x = 1;
		size_t cursor_y = 1;

		if (tto.table_frame == '-') cursor_y++;

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
					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x + in_case_of_frame);
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
					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x + in_case_of_frame);

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
					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x + in_case_of_frame);

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

					pom = cursor_x_temporary;

					while (cursor_x_temporary < ret[i].width)
					{
						out << ".";
						cursor_x++;
						cursor_x_temporary+=2;
						pom++;
					}

					cursor_x_temporary = pom;

					printf("%c[%zu;%zuf", 0x1B, cursor_y, cursor_x + in_case_of_frame);

					while (cursor_x_temporary < ret[i].width)
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

			if (!if_hole_needed && (tto.table_frame == '-' || tto.table_frame == '='))
			{
				cursor_y++;
				if_hole_needed = false;
			}
		}
	}

	void table_drawer::clearer(term_table_options tto, const rx_table_type& table, const std::vector<table_header>& ret, std::ostream& out)
	{
		printf("%c[%d;%df", 0x1B, 0, 0);
		for (size_t i = 0; i < (table[0].size() + 5) * 3; i++)
		{
			for (size_t j = 0; j < tto.max_width + ret.size() * 3; j++)
			{
				out << " ";
			}
			out << "\r\n";
		}
	}

} //urke
