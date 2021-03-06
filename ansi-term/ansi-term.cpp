#include "pch.h"
#include "ansi_codes.h"
#include "term_table.h"


void test_client()
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

    SOCKET conn = socket(AF_INET, SOCK_STREAM, 0);
    if (conn == INVALID_SOCKET)
    { 
        std::cerr << "Can't create a socket! Quitting" << std::endl;
        return;
    }

    // bind the ip adress and port to a socket

    sockaddr_in svr_addr;
    memset(&svr_addr, 0, sizeof(svr_addr));
    svr_addr.sin_family = AF_INET;
    svr_addr.sin_port = htons(54000);
    svr_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");///////////////////////////////////////////////////////////////////////////////////

    auto ret_val = connect(conn, (sockaddr*)&svr_addr, sizeof(svr_addr));
    if (ret_val != NO_ERROR)
    {
        std::cerr << "Can't connect a socket! Quitting" << std::endl;
        return;

    }



    // while loop: accept and echo message back to client

    char buf[4096];

    while (true)
    {
        // Echo message back to client
        string_type line;
        std::getline(std::cin, line);

        send(conn, line.c_str() + 1, line.size(), 0);

        ZeroMemory(buf, 4096);

        // Wait for client to send data

        int bytesRecieved = recv(conn, buf, 4096, 0);

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


    }

    // close the socket

    closesocket(conn);

    // cleanup winsock

    WSACleanup();
}

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
    memset(&hint, 0, sizeof(hint));
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
        std::cout << "\r\n" << buf << "\r\n";

        // Echo message back to client

        string_type odgovor("OK");

        send(clientSocket, odgovor.c_str(), odgovor.size() + 1, 0);

    }

    // close the socket

    closesocket(clientSocket);

    // cleanup winsock

    WSACleanup();
}


int main(int argc , char* args[])
{
    /*string_type arg1;
    if (argc > 1)
        arg1 = args[1];

    if (arg1 == "client")
        test_client();
    else
        test_socket();

    return 0;*/

    auto out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD out_mode = 0;
    GetConsoleMode(out_handle, &out_mode);
    out_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    //out_mode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(out_handle, out_mode);

    //std::cout << ANSI_CUR(5,5) ANSI_COLOR_RED ANSI_COLOR_BOLD "Hello " ANSI_COLOR_RESET " World! \n";

    size_t max_width = 50;

    std::cout << ANSI_CUR_PUSH;

    urke::rx_table_type tabela(6);
    
    tabela[0].emplace_back("kol1q");
    tabela[0].emplace_back("kol2 1234567q");
    tabela[0].emplace_back("kol3q");
    tabela[0].emplace_back("kol4 123456789 q");

    tabela[1].emplace_back("Val1q");
    tabela[1].emplace_back("Val2q");
    tabela[1].emplace_back("Val3  12345678910111213q");
    tabela[1].emplace_back("Val4q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    tabela[2].emplace_back("Val5q");
    tabela[2].emplace_back("Val6 123456789q");
    tabela[2].emplace_back("Val7  12345678910q");
    tabela[2].emplace_back("Val8q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    tabela[3].emplace_back("Val9q");
    tabela[3].emplace_back("Val10 q");
    tabela[3].emplace_back("Val11  12345q");
    tabela[3].emplace_back("Val12q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    tabela[4].emplace_back("Val13q");
    tabela[4].emplace_back("Val14 12345678910111213q");
    tabela[4].emplace_back("Val15  12345678q");
    tabela[4].emplace_back("Val16q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    tabela[5].emplace_back("Val17 1234q");
    tabela[5].emplace_back("Val18q");
    tabela[5].emplace_back("Val19   q");
    tabela[5].emplace_back("Val20  12345678910q", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    urke::rx_dump_table(tabela, std::cout, false, false, ' ', max_width, 0);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, false, false, ' ', max_width, 1);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, false, false, ' ', max_width, 2);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, false, false, ' ', max_width, 3);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");

    std::cout << ANSI_CUR_POP;
    std::cout << ANSI_CUR_PUSH;
    
   
    urke::rx_dump_table(tabela, std::cout, true, true, '-', max_width, 0);
    system("pause");

   tabela[1][3].prefix = ANSI_COLOR_YELLOW ANSI_COLOR_BOLD;
    system("pause");
    std::cout << ANSI_CUR_POP;
    urke::rx_dump_table(tabela, std::cout, true, true, ' ', max_width, 1);
    tabela[1][2].prefix = ANSI_COLOR_GREEN ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, false, ' ', max_width, 2);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '=', max_width, 2);
    tabela[1][0].prefix = ANSI_COLOR_RED ANSI_COLOR_BOLD;
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '-', max_width, 1);
    tabela[4][3].prefix = ANSI_COLOR_RED ANSI_COLOR_BOLD;
    system("pause");  
    urke::rx_dump_table(tabela, std::cout, true, true, '-', max_width * 5, 2);
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '=', max_width * 2, 1);
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, ' ', max_width - 3, 0);
    system("pause");
    urke::rx_dump_table(tabela, std::cout, true, true, '=', max_width * 4, 2);
    system("pause");


    urke::rx_dump_table(tabela, std::cout, true, false, ' ', max_width - 10, 3);
    tabela[1][1].prefix = ANSI_COLOR_BLUE ANSI_COLOR_BOLD;
    system("pause");

    
    /*tabela[0].emplace_back("a");
    tabela[0].emplace_back("b");
    tabela[0].emplace_back("ccc");
    urke::rx_dump_table(tabela, std::cout, true, true, '-');*/
}
