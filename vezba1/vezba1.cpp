#include "pch.h"
#include "definitions.h"
#include "Game.h"
#include "hardcore_maze.h"

using namespace std;

int height = 30;
int width = 30;

int main()
{
    srand(time(NULL));
    //konstruktor_example();

    hardcore_maze2 my_maze(width, height);
    player1 play1(5, 5);
    player2 play2(3, 10);

    game the_game(&my_maze);
    the_game.add_player(&play1);
    the_game.add_player(&play2);

    while (!the_game.is_game_over())
    {
        the_game.get_inputs().read_keys();

        the_game.print();

        std::ostringstream ss;
        the_game.get_display().print(ss);
        for (int i = 0; i < 100000; i++);
        system("cls");
        std::cout << ss.str();
    }
    cout << "jbg";
    return 0;
}
