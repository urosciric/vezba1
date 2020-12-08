#include "pch.h"
#include "ansi_codes.h"

int main()
{

    auto out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD out_mode = 0;
    GetConsoleMode(out_handle, &out_mode);
    out_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    //out_mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(out_handle, out_mode);

    std::cout << ANSI_CUR(5,5) ANSI_COLOR_RED ANSI_COLOR_BOLD "Hello " ANSI_COLOR_RESET " World! \n";
}
