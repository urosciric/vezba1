#include "pch.h"
#include "ansi_codes.h"
#include "term_table.h"


void test_socket()
{

    // initialize winsock

    WSADATA wsDATA;
    WORD ver = MAKEWORD(2, 2);

    int WSOK = WSAStartup(ver, &wsDATA);
    if (WSOK != 0)
    {
        std::cerr << "Can't initialize winsock! Quitting" << std::endl;
        return;
    }

    // create socket

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        std::cerr << "Can't create a socket! Quitting" << std::endl;
        return;
    }

    // bind the ip adress and port to a socket

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // tell winsock the socket is for listening

    listen(listening, SOMAXCONN);

    // wait for a connection

    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    if (clientSocket == INVALID_SOCKET)
    {
        std::cerr << "Can't create a socket! Quitting" << std::endl;
        return;
    }

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        std::cout << host << "connected on port" << service << std::endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        std::cout << host << "connected on port" << ntohs(client.sin_port) << std::endl;
    }

    // close listening socket

    closesocket(listening);

    // while loop: accept and echo message back to client

    char buf[4096];

    while (true)
    {

        ZeroMemory(buf, 4096);

        // Wait for client to send data

        int bytesRecieved = recv(clientSocket, buf, 4096, 0);

        if (bytesRecieved == SOCKET_ERROR)
        {
            std::cerr << "Error in recv().  Quitting" << std::endl;
            break;
        }

        else if (bytesRecieved == 0)
        {
            std::cout << "Client disconnected" << std::endl;
            break;
        }

        // Echo message back to client

        send(clientSocket, buf, bytesRecieved + 1, 0);

    }

    // close the socket

    closesocket(clientSocket);

    // cleanup winsock

    WSACleanup();
}

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
