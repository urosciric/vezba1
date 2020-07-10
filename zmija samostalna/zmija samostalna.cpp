#include "pch.h"
#include "map.h"
#include "game.h"
#include "in_the_back.h"
#include "player.h"
#include "keyboard.h"

const size_t height = 20;
const size_t width = 20;

int main()
{

    game the_game;

    srand((unsigned int)time(NULL));
    while (!the_game.game_over())
    {

        system("cls");

        the_game.read_keys();

        the_game.print_in_the_back();
        the_game.move_player();
        the_game.fill_in_the_back();

    }

    std::cout << "jbg" << "\r\n";

    system("pause");

}
