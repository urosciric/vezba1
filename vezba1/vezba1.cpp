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
    game the_game(&my_maze);
    while (!the_game.is_game_over())
    {
        the_game.get_inputs1().read_keys();
        the_game.get_inputs2().read_keys();

        the_game.print();

        std::ostringstream ss;
        the_game.get_display().print(ss);
        //for(int i=0;i<100000;i++)
        system("cls");
        std::cout << ss.str();
    }
    cout << "jbg";
    return 0;
}
