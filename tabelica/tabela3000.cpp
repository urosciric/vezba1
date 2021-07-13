#include <iostream>
#include "table3000.h"
#include "ansi_codes.h"
#include "pch.h"

	int main()
	{

		urke::table3000 tabelica;
        urke::term_table_options tto;

        urke::rx_table_type tabela(6);

        tabela[0].emplace_back("kol1q");
        tabela[0].emplace_back("kol2 1234567q");
        tabela[0].emplace_back("kol3q");
        tabela[0].emplace_back("kol4 123456789 q");

        tabela[1].emplace_back("Val1q");
        tabela[1].emplace_back("Val2q");
        tabela[1].emplace_back("Val3 12345678910111213q");
        tabela[1].emplace_back("Val4q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        tabela[2].emplace_back("Val5q");
        tabela[2].emplace_back("Val6 123456789q");
        tabela[2].emplace_back("Val7 12345678910q");
        tabela[2].emplace_back("Val8q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        tabela[3].emplace_back("Val9q");
        tabela[3].emplace_back("Val10 q");
        tabela[3].emplace_back("Val11 12345q");
        tabela[3].emplace_back("Val12q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        tabela[4].emplace_back("Val13q");
        tabela[4].emplace_back("Val14 12345678910111213q");
        tabela[4].emplace_back("Val15 12345678q");
        tabela[4].emplace_back("Val16q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        tabela[5].emplace_back("Val17 1234q");
        tabela[5].emplace_back("Val18q");
        tabela[5].emplace_back("Val19 q");
        tabela[5].emplace_back("Val20 12345678910q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

        tto.dot_lines = false;
        tto.max_width = 50;
        tto.options = 4;
        tto.header = false;

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        tto.dot_lines = true;
        tto.max_width = 70;
        tto.table_frame = '-';
        tto.options = 1;
        tto.header = true;

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        tto.max_width = 50;
        tto.options = 2;
        tto.header = false;

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        tto.options = 3;

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        tto.table_frame = '=';

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        tto.table_frame = '=';
        tto.max_width = 70;
        tto.options = 1;

        urke::rx_dump_table(tabela, std::cout, tto);
        tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;

        return 0;
	}