#include "pch.h"
#include "term_table.h"
#include "ansi_codes.h"
#define MAXN 10000


namespace urke
{

/*namespace
{
void term_set_cursor(std::ostream& out, int x, int y)
{
	char buffer[0x40];
	sprintf_s(buffer, sizeof(buffer) / sizeof(buffer[0]), "\x1b[%d;%dH", x, y);
	out << buffer;
}


void term_cursor_up(std::ostream& out, int count)
{
	char buffer[0x40];
	sprintf_s(buffer, sizeof(buffer) / sizeof(buffer[0]), "\x1b[%dA", count);
	out << buffer;
}

void zajebancija()
{
	for (int i = 0; i < 80; i++)
	{
		term_set_cursor(std::cout, 40, i);
		Sleep(200);
	}
}
}*/
	size_t niz_pom[MAXN];
	size_t niz_max[MAXN];

	void column_width_calculator(context* ctx, size_t max_width)
	{

		//widths.resize(columns_number, 0);

		if (ctx->pom > max_width)
		{

			size_t pom_max = 0;
			size_t remember = 0;
			bool remember_pom;

			for (size_t i = 0; i < (*ctx->widths).size(); i++)
			{
				remember_pom = true;
				for (size_t j = 0; j < (*ctx->widths).size(); j++)
				{
					if ((*ctx->widths)[pom_max] <= (*ctx->widths)[j])
					{
						for (size_t m = 0; m < remember; m++)
							if (niz_max[m] == (*ctx->widths)[i])
								remember_pom = false;
						if (!remember_pom)
						{
							pom_max = i;
						}
						else
						{
							pom_max = j;
						}

					}
				}
				if ((int)((*ctx->widths)[pom_max] - ctx->pom + max_width) >= 6)
				{
					(*ctx->widths)[pom_max] -= ctx->pom - max_width;

					i = (*ctx->widths).size();
				}
				else
				{

					ctx->pom -= (*ctx->widths)[pom_max] + 6;
					(*ctx->widths)[pom_max] = 6;

				}
				niz_max[remember] = (*ctx->widths)[pom_max];
			}
		}
	}

	void prvi_red(context* ctx)
	{
		if (ctx->option == '-')
		{
			for (size_t i = 0; i < ctx->columns_number; i++)
			{

				ctx->first_line += ((*ctx->widths)[i] + ctx->col_diff + 3);

			}

			ctx->first_line += (ctx->columns_number - 1) * 2;

			ctx->out() << '+';

			for (size_t i = 1; i < ctx->first_line; i++)
			{

				if (!ctx->max_width_pom)
				{
					if ((*ctx->widths)[ctx->pom] + 3 + ctx->pom * 3 + ctx->width_pom == i)
					{
						if (ctx->pom == (*ctx->widths).size() - 1) ctx->max_width_pom = true;
						if (ctx->max_width_pom)
						{
							i = ctx->first_line;
						}
						else
						{
							ctx->out() << '+';
							ctx->width_pom += (*ctx->widths)[ctx->pom];
							ctx->pom++;
						}
					}
					else
					{
						ctx->out() << ctx->option;
					}
				}
				else
				{
					ctx->out() << ctx->option;
				}

			}

			ctx->out() << '+';

			for (size_t i = 0; i <= ctx->length_for_clear - ctx->pom_length; i++)
				ctx->out() << ' ';

		}

		else
		{
			for (size_t i = 0; i < ctx->columns_number; i++)
			{
				ctx->first_line += ((*ctx->widths)[i] + ctx->col_diff);
			}

			for (size_t i = 1; i < ctx->first_line + 5 + (ctx->columns_number - 1) * 5; i++)
				ctx->out() << ' ';


		}
	}

	void opcija_nula(context* ctx, size_t max_width, size_t i)
	{
		if ((*ctx->row)[i].value.size() >= (*ctx->widths)[i])
		{
			for (size_t j = 0; j < ctx->length - 3; j++)
			{
				ctx->out() << (*ctx->row)[i].value[j];
				if (j == (*ctx->widths)[i] - 4)
				{
					j = (*ctx->row)[i].value.size();
				}
			}
			ctx->out() << "...";
		}
		else if ((*ctx->row)[i].value.size() == (*ctx->widths)[i] - 1)
		{
			for (size_t j = 0; j < ctx->length - 2; j++)
			{
				ctx->out() << (*ctx->row)[i].value[j];
				if (j == (*ctx->widths)[i] - 4)
				{
					j = (*ctx->row)[i].value.size();
				}
			}
			ctx->out() << "..";
		}
		else
		{
			ctx->out() << (*ctx->row)[i].value;
		}


		if (!(*ctx->row)[i].postfix.empty())
			ctx->out() << (*ctx->row)[i].postfix;

		////////////////////////////////////////////////////////////////////
		if (ctx->empty_char == '.')
		{
			if ((*ctx->widths)[i] <= niz_pom[i] - (*ctx->widths)[i])
			{
				for (size_t j = 0; j < ctx->rest.size() - 2; j++)
					ctx->out() << '.';
			}
			/*else if (widths[i] == niz_pom[i] && row[i].value.size() >= widths[i])
			{
				out << "";
			}*/
			else
			{
				for (size_t j = 0; j < ctx->rest.size() - 2; j++)
					ctx->out() << '.';
			}
			//if (i != columns_number - 1) out << "  ";
		}
		else
		{
			if ((*ctx->widths)[i] <= niz_pom[i])
			{
				for (size_t j = 0; j < ctx->rest.size() - 2 /* + niz_pom[i] - widths[i]*/; j++)
					ctx->out() << ' ';
			}
			else if ((*ctx->widths)[i] > max_width && (*ctx->row)[i].value.size() >= max_width)
			{
				ctx->out() << "  ";
			}
			else
			{
				for (size_t j = 0; j < ctx->rest.size() - (*ctx->widths)[i]; j++)
					ctx->out() << ' ';
			}
			//if (i != columns_number - 1) out << "  ";
		}
		if (i != ctx->columns_number) ctx->out() << "  ";
	}

	void rx_dump_table(const rx_table_type& table, std::ostream& out, bool column_names, bool dot_lines, const char table_frame, size_t max_width, size_t options)
	//void rx_dump_table(const rx_table_type& table, std::ostream& out, const table_stype& settings)
	{

		context ctx;
		ctx.columns_number = 0;
		ctx.option = table_frame;
		ctx.first_line = 0;
		ctx.col_diff = 2;
		ctx.width_pom = 0;
		ctx.max_width_pom = false;
		ctx.length_for_clear = 0;
		ctx.pom_length = 0;
		ctx.pom = 0;
		ctx.widths = new std::vector<size_t>(ctx.columns_number);
		ctx.length = 0;
		ctx.empty_char;
		ctx.out_ = &out;
		ctx.row = nullptr;
		ctx.rest;

		if (table.empty())
			return;

		//const char option = table_frame;


		if (options != 0 && options != 1 && options != 2 && options != 3)
		{
			out << "Options variable is invalid\r\n";
			return;
		}
	
		for (const auto& row : table)
		{
			if (ctx.columns_number == 0)
				ctx.columns_number = row.size();
			else
			{
				if (!row.empty())
				{// we allow empty rows
					if (ctx.columns_number != row.size())
					{
						out << "Error in table format\r\n";
						return;
					}
				}
			}
		}

		ctx.widths->resize(ctx.columns_number, 0);

		// o.k. we checked now so let's calculate columns width
		for (const auto& row : table)
		{
			if (!row.empty())
			{
				for (size_t i = 0; i < ctx.columns_number; i++)
				{
					if (row[i].value.size() >(*ctx.widths)[i])
						(*ctx.widths)[i] = row[i].value.size();
				}
			}
		}
		ctx.empty_char = dot_lines ? '.' : ' ';
		// now we have all widths
		bool first = true;


		//////////////

		for (size_t i = 0; i < (*ctx.widths).size(); i++)
		{
			ctx.pom += (*ctx.widths)[i];
			niz_pom[i] = (*ctx.widths)[i];
		}

		column_width_calculator(&ctx, max_width);

		//////////////

		ctx.pom = 0;
	
		for (size_t i = 0; i < ctx.columns_number; i++)
		{
			ctx.length_for_clear += (niz_pom[i] + ctx.col_diff + 3);

			ctx.pom_length+= ((*ctx.widths)[i] + ctx.col_diff + 3);
			
		}

		ctx.length_for_clear += (ctx.columns_number - 1) * 2;

		//////////////

		

		prvi_red(&ctx);

		out << "\r\n";

		///////

		ctx.pom = 0;
		ctx.width_pom = 0;
		ctx.max_width_pom = false;

		size_t cut_string_pom = 0;
		bool repeat_for_rows = false;

		bool pom_extender = false;

		size_t column_number = 0;

		size_t niz[100];
		
		size_t  pom_for_niz = 0;

		bool rep = false;

		size_t brojac = 0;

		for (auto row : table)
		{
			ctx.row = &row;
			pom_for_niz = 0;
			brojac = 1;
			memset(niz, 0, sizeof(niz));

			begin:
			

			if (!first)
				out << "\r\n";
			if (!row.empty())
			{

				if (ctx.option == '-')
					out << ANSI_COLOR_GRAY << "|" << ANSI_COLOR_RESET;
				else
					out << " ";

				for (size_t i = 0; i < ctx.columns_number; i++)
				{
					if (i != 0 && ctx.option == '-')
					{
						out << "|";
					}

					if (row[i].value.size() > (*ctx.widths)[i] - 2)
					{
						ctx.length = (*ctx.widths)[i] - 2;
						pom_extender = true;
					}
					else
					{
						ctx.length = row[i].value.size();
					}
					bool test = ((*ctx.widths)[i] + ctx.col_diff - ctx.length,
						i == ctx.columns_number - 1 || first || row[i].value.empty());
					ctx.rest=(test
						? ' ' : ctx.empty_char);

					
					//if (pom_extender) length = row[i].value.size();

					
					if (!row[i].prefix.empty())
						out << row[i].prefix;

					/////////////////////////////////////////////////////////////////////
					if (options == 0)
					{

						opcija_nula(&ctx, max_width, i);
						
					}
					////////////////////////////////////////////////////////////////////
					if (options == 1)
					{
						if (i != ctx.columns_number) out << "  ";
						if (ctx.empty_char == '.')
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < ctx.rest.size() - 2; j++)
									out << '.';
							}
							else if ((*ctx.widths)[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "";
							}
							else
							{
								for (size_t j = 0; j < ctx.rest.size() - 2; j++)
									out << '.';
							}
						
						}
						else
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < ctx.rest.size() - 2; j++)
									out << ' ';
							}
							else if ((*ctx.widths)[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "  ";
							}
							else
							{
								for (size_t j = 0; j < ctx.rest.size() - niz_pom[i] + (*ctx.widths)[i]; j++)
									out << ' ';
							}
						}
						////////////////////////////////////////////////////////////////////
						if (row[i].value.size() >= (*ctx.widths)[i])
						{
							out << "...";
							for (size_t j = 3; j < ctx.length; j++)
							{
								out << row[i].value[j];
								if (j == (*ctx.widths)[i] - 4 + 3)
								{
									j = row[i].value.size();
								}
							}
						
						}
						else if (row[i].value.size() == (*ctx.widths)[i] - 1)
						{
							out << "..";
							for (size_t j = 2; j < ctx.length; j++)
							{
								out << row[i].value[j];
								if (j == (*ctx.widths)[i] - 4 + 2)
								{
									j = row[i].value.size();
								}
							}
						
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;

						//if (i != columns_number - 1) out << "  ";
				
					}
					////////////////////////////////////////////////////////////////////
					if (options == 3)
					{
						if (pom_for_niz == 8)
						{
							for (size_t j = 0; j < pom_for_niz; j += 2)
							{
								if (i == niz[j])
								{
									cut_string_pom = niz[j + 1] * brojac;
									break;
								}
							}
						}
						//if (pom_for_niz == 8) pom_for_niz = 0;
						if (row[i].value.size() - cut_string_pom > (*ctx.widths)[i] - 2)
						{
							for (size_t j = 0; j < (*ctx.widths)[i] - 2; j++)
							{
								if (cut_string_pom + j < row[i].value.size()) out << row[i].value[cut_string_pom + j];
								
							}

							if (!rep)
							{
								cut_string_pom = (*ctx.widths)[i] - 2;
								niz[pom_for_niz] = i;
								pom_for_niz++;
								niz[pom_for_niz] += cut_string_pom;
								pom_for_niz++;
							}
							else
							{
								niz[i * 2 + 1] += (*ctx.widths)[i] - 2;
							}
							
							cut_string_pom = 0;
							repeat_for_rows = true;

							
						}

						else
						{
							for (size_t j = 0; j < (*ctx.widths)[i] - 2; j++)
							{
								if (cut_string_pom + j < row[i].value.size() && (cut_string_pom != 0 || !rep))
								{
									out << row[i].value[cut_string_pom + j];
									niz[i * 2 + 1]++;
								}
								else if (/*cut_string_pom == 0 && */ rep && j < row[i].value.size())
								{
									out << ' ';
								}
								
							}
							
							if (!rep)
							{
								//cut_string_pom = widths[i] - 2;
								niz[pom_for_niz] = i;
								pom_for_niz++;
								niz[pom_for_niz] += cut_string_pom;
								pom_for_niz++;
							}
							
							cut_string_pom = 0;
						}
						
						if (!row[i].postfix.empty())
							out << row[i].postfix;

						//////////////////////////////////////
						if (ctx.empty_char == '.')
						{
							
							for (size_t j = 0; j < ctx.rest.size() - 2; j++)
								out << '.';
							
						}
						else
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < ctx.rest.size() - 2; j++)
									out << ' ';
							}
							else if ((*ctx.widths)[i] > max_width && row[i].value.size() >= max_width)
							{
								out << "  ";
							}
							else
							{
								for (size_t j = 0; j < ctx.rest.size() - (*ctx.widths)[i]; j++)
									out << ' ';
							}
							
						}
						if (i != ctx.columns_number) out << "  ";
					}
					////////////////////////////////////////////////////////////////////
					else
					{
						if (i != ctx.columns_number) out << " ";
						if (ctx.empty_char == '.')
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								if ((ctx.rest.size() - 2) % 2 == 0)
								{
									for (size_t j = 0; j < (ctx.rest.size() - 2) / 2; j++)
										out << '.';
								}
								else
								{
									for (size_t j = 0; j < (ctx.rest.size() - 2) / 2 + 1; j++)
										out << '.';
								}
							}
							/*else if (widths[i] > niz_pom[i] && row[i].value.size() >= niz_pom[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (ctx.rest.size() - 2) / 2; j++)
									out << '.';
								if (ctx.rest.size() % 2 != 0) out << " ";
							}

						}
						else
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < (ctx.rest.size() - 2) / 2; j++)
									out << ' ';
							}
							/*else if (widths[i] > niz_pom[i] && row[i].value.size() >= niz_pom[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (ctx.rest.size()) / 2; j++)
									out << ' ';
							}
						}
						////////////////////////////////////////////////////////////////////
						if (row[i].value.size() >= (*ctx.widths)[i])
						{
							for (size_t j = 0; j < ctx.length - 3; j++)
							{
								out << row[i].value[j];
								if (j == (*ctx.widths)[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "...";
						}
						else if (row[i].value.size() == (*ctx.widths)[i] - 1)
						{
							for (size_t j = 0; j < ctx.length - 2; j++)
							{
								out << row[i].value[j];
								if (j == (*ctx.widths)[i] - 4)
								{
									j = row[i].value.size();
								}
							}
							out << "..";
						}
						else
						{
							out << row[i].value;
						}


						if (!row[i].postfix.empty())
							out << row[i].postfix;
						////////////////////////////////////////////////////////////////////
						if (ctx.empty_char == '.')
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								if(ctx.rest.size() - 2 != 1)
									for (size_t j = 0; j < (ctx.rest.size() - 2) / 2; j++)
										out << '.';
									//if (rest.size() % 2 != 0) out << " ";
						
							}
						/*	else if (widths[i] > niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << "";
							}*/
							else
							{
								for (size_t j = 0; j < (ctx.rest.size() - 2) / 2 + 1; j++)
									out << '.';
							}

						}
						else
						{
							if ((*ctx.widths)[i] <= niz_pom[i])
							{
								for (size_t j = 0; j < (ctx.rest.size() - 2) / 2; j++)
									out << ' ';
								if (ctx.rest.size() % 2 != 0) out << " ";
							}
					/*		else if (widths[i] > niz_pom[i] && row[i].value.size() >= widths[i])
							{
								out << " ";
							}*/
							else
							{
								for (size_t j = 0; j < (ctx.rest.size()) / 2; j++)
									out << ' ';
								if (ctx.rest.size() % 2 != 0) out << " ";
							}
						}


						if (i != ctx.columns_number) out << " ";

					}
					////////////////////////////////////////////////////////////////////

				}

				if (ctx.option == '-')
				{
					out << ANSI_COLOR_GRAY << "|" << ANSI_COLOR_RESET;
				}
				else
				{
					out << "";
				}

			}
			if (first)
				first = false;
			if (column_names)
			{
				for (size_t i = 0; i <= ctx.length_for_clear - ctx.pom_length + 3; i++)
					out << ' ';
				if (!repeat_for_rows && ctx.option != ' ') out << "\r\n";
				size_t total_width = 0;
				for (size_t i = 0; i < ctx.columns_number; i++)
				{
					total_width += ((*ctx.widths)[i] + ctx.col_diff);
				}

				if (ctx.option == '-') out << '+';
				else out << ' ';
				string_type rest(total_width + 1 + (ctx.columns_number - 2) * 5 , ctx.option);
				string_type small_rest(total_width + 2, ctx.option);

				if (ctx.option == '-')
				{
					for (size_t i = 1; i < ctx.first_line; i++)
					{
						if ((*ctx.widths)[ctx.pom] <= max_width)
						{
							if (!ctx.max_width_pom)
							{
								if ((*ctx.widths)[ctx.pom] + 3 + ctx.pom * 3 + ctx.width_pom == i)
								{
									if (ctx.pom == (*ctx.widths).size() - 1) ctx.max_width_pom = true;

									if (ctx.max_width_pom)
									{
										i = ctx.first_line;
									}
									else
									{
										out << '+';
										ctx.width_pom += (*ctx.widths)[ctx.pom];
										ctx.pom++;
									}
								}
								else
								{
									out << ctx.option;
								}
							}
							else
							{
								out << ctx.option;
							}
						}
						else
						{
							if (!ctx.max_width_pom)
							{
								if (max_width + 3 + ctx.pom * 3 + ctx.width_pom == i)
								{
									if (ctx.pom == (*ctx.widths).size() - 1) ctx.max_width_pom = true;
									if (ctx.max_width_pom)
									{
										i = ctx.first_line;
									}
									else
									{
										out << '+';
										ctx.width_pom += max_width;
										ctx.pom++;
									}

								}
								else
								{
									out << ctx.option;
								}
							}
							else
							{
								out << ctx.option;
							}
						}
					}
				}
				else if (total_width >= ctx.columns_number * max_width)
				{
					out << ANSI_COLOR_GRAY << small_rest << ANSI_COLOR_RESET;
					for (size_t i = small_rest.size(); i < rest.size(); i++) out << ' ';
				}
				else if (total_width < ctx.columns_number * max_width)
				{
			
					out << ANSI_COLOR_GRAY << small_rest << ANSI_COLOR_RESET;
					for (size_t i = rest.size(); i < rest.size(); i++) out << ' ';
			
				}
				if (ctx.option == '-') out << '+';
				else out << ' ';
				column_names = false;

			}
			ctx.pom++;
			for (size_t i = 0; i <= ctx.length_for_clear - ctx.pom_length + 3; i++)
				out << ' ';


			rep = false;
			
			if (repeat_for_rows)
			{
				if (cut_string_pom * 2 <= row[column_number].value.size())
				{
					repeat_for_rows = false;
					cut_string_pom = 0;
				}
				//out << "\r\n";
				rep = true;
				goto begin;
			}
		}

		ctx.pom = 0;
		ctx.width_pom = 0;
		ctx.max_width_pom = false;

		out << "\r\n";

		if (table.size() != 1)
		{

			if (ctx.option == '-')
			{
				out << '+';

				for (size_t i = 1; i < ctx.first_line; i++)
				{
					if ((*ctx.widths)[ctx.pom] <= max_width)
					{
						if (!ctx.max_width_pom)
						{
							if ((*ctx.widths)[ctx.pom] + 3 + ctx.pom * 3 + ctx.width_pom == i)
							{
								if (ctx.pom == (*ctx.widths).size() - 1) ctx.max_width_pom = true;

								if (ctx.max_width_pom)
								{
									i = ctx.first_line;
								}
								else
								{
									out << '+';
									ctx.width_pom += (*ctx.widths)[ctx.pom];
									ctx.pom++;
								}
							}
							else
							{
								out << ctx.option;
							}
						}
						else
						{
							out << ctx.option;
						}
					}
					else
					{
						if (!ctx.max_width_pom)
						{
							if (max_width + 3 + ctx.pom * 3 + ctx.width_pom == i)
							{
								if (ctx.pom == (*ctx.widths).size() - 1) ctx.max_width_pom = true;
								if (ctx.max_width_pom)
								{
									i = ctx.first_line;
								}
								else
								{
									out << '+';
									ctx.width_pom += max_width;
									ctx.pom++;
								}

							}
							else
							{
								out << ctx.option;
							}
						}
						else
						{
							out << ctx.option;
						}
					}
				}

				out << '+';
			}

			else
			{

				for (size_t i = 0; i < ctx.first_line; i++)
					out << "  ";


			}

			for (size_t i = 0; i <= ctx.length_for_clear - ctx.pom_length; i++)
				out << ' ';

		}
		out << "\r\n";
	}

} //urke