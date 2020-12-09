#include "pch.h"
#include "ansi_codes.h"
#include "term_table.h"

int main()
{

    auto out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD out_mode = 0;
    GetConsoleMode(out_handle, &out_mode);
    out_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    //out_mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(out_handle, out_mode);

    //std::cout << ANSI_CUR(5,5) ANSI_COLOR_RED ANSI_COLOR_BOLD "Hello " ANSI_COLOR_RESET " World! \n";

    urke::rx_table_type tabela(3);
    
    tabela[0].emplace_back("kol1");
    tabela[0].emplace_back("kol2 dugacka");
    tabela[0].emplace_back("kol3");
    tabela[0].emplace_back("kol4 nesto duza");

    tabela[1].emplace_back("Val1");
    tabela[1].emplace_back("Val2");
    tabela[1].emplace_back("Val3  sgsdgsadgsdgsdgsdg");
    tabela[1].emplace_back("Val4", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    tabela[2].emplace_back("Val5");
    tabela[2].emplace_back("Val6 cikacika");
    tabela[2].emplace_back("Val7  sgsdgsadgsdg");
    tabela[2].emplace_back("Val8", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    urke::rx_dump_table(tabela, std::cout, true, true, '-');
    

    tabela[1][3].prefix = ANSI_COLOR_YELLOW ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '=');
    tabela[1][2].prefix = ANSI_COLOR_GREEN ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, false, ' ');
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '=');
    tabela[1][0].prefix = ANSI_COLOR_RED ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '-');


}
