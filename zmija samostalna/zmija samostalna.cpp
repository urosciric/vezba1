#include "pch.h"
#include "map.h"
#include "game.h"
#include "in_the_back.h"
#include "player.h"
#include "keyboard.h"
#include "game_display.h"

size_t milsecs = 1000;

void args(int argc, char* argv[], size_t& height, size_t& width, size_t& fast_foward)
{
    if (argc > 1)
    {

        if (strcmp(argv[1], "help") == 0)
        {

            std::cout << "This is help!" << "\r\n";
            std::cout << "You can type number between 4 and 50!" << "\r\n";
            std::cout << "If you type just one number map's height and width will be that walue!" << "\r\n";
            std::cout << "if you type more numbers your last number needs to be less than number of them and then height and width will be the number that is on position that is declared with last number!" << "\r\n";
            std::cout << "You can't type words amogn help or height and width will automaticly be 3!" << "\r\n";
            fast_foward++;
            system("pause");

        }

        else if (atoi(argv[1]) > 50 && atoi(argv[1]) < 4)
        {
            std::cout << "Out of bounce!" << "\r\n" << "For more info type help." << "\r\n";
            fast_foward++;
            system("pause");
        }

        else if (argc == 2 || argc == 3)
        {

            size_t temp = 0;

            for (int i = 4; i <= 50; i++)
                if (atoi(argv[1]) == i)
                    temp++;
            if (temp != 0)
                height = width = atoi(argv[1]);
            else
            {

                height = width = 3;
                std::cout << "Out of bounce!" << "\r\n" << "For more info type help." << "\r\n";
                fast_foward++;
                system("pause");

            }

        }

        else if (argc > 3 && atoi(argv[argc - 1]) < argc)
        {

            size_t temp = 0;


            if (atoi(argv[atoi(argv[argc - 1])]) <= 50 && atoi(argv[atoi(argv[argc - 1])]) >= 4)
                height = width = atoi(argv[atoi(argv[argc - 1])]);
            else
            {

                height = width = 3;
                std::cout << "Out of bounce!" << "\r\n" << "For more info type help." << "\r\n";
                fast_foward++;
                system("pause");

            }

        }

        else
            height = width = 3;

    }

}

void pause(size_t dur)
{
    clock_t wait = dur * milsecs / 10 + clock(); 
    while (wait > clock()) continue;
}


int main(int argc, char* argv[])
{
    system("pause");
    size_t height = 20;
    size_t width = 20;

    size_t fast_foward = 0;

    /////////////////////////////////////////////////////////////
    args(argc, argv, height, width, fast_foward);
    /////////////////////////////////////////////////////////////

    if (fast_foward == 0)
    {

        game the_game;
        game_display display;

        display.initialize_dsplay();

        if (the_game.init_game(width, height))
        {
            srand((unsigned int)time(NULL));
            while (!the_game.game_over())
            {

                display.reset_coordinates();

                the_game.read_keys();

                the_game.print_in_the_back();
                the_game.fill_in_the_back();
                the_game.move_player();

                pause(1);

                milsecs--;

            }

            system("cls");


            the_game.print_in_the_back();

            std::cout << "jbg" << "\r\n";

            system("pause");

            display.clear();

        }
    }
    else
    {
        std::cout << "greska\r\n";
    }

}
