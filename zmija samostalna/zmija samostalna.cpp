#include <iostream>
#include "pch.h"
#include "map.h"
#include "game.h"
#include "in_the_back.h"

const size_t height = 20;
const size_t width = 20;

int main()
{

    game the_game;

    srand(time(NULL));
    while (1 > 0)
    {

        the_game.print_in_the_back();
        the_game.fill_in_the_back();

        system("cls");

    }

}
