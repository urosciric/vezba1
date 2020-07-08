#include "pch.h"
#include "definitions.h"
#include "Game.h"

#define MAXN 23

using namespace std;


int nizX[MAXN];
int nizY[MAXN];

int height = 20;
int width = 20;
int x = height / 2;
int y = width / 2;
int fruitX;
int fruitY;
int snake_length=0;
bool game_over = false;




int pom = 0;

enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;

void ispis(game& the_game)
{
    system("cls");
    the_game.get_display().print(std::cout);
}

void Special_elements(game& the_game)
{
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (y == i && x == j)
            {
                the_game.get_display().put(i, j, 'O');
                pom++;
            }
            else if (fruitY == i && fruitX == j)
            {
                the_game.get_display().put(i, j, '$');
                pom++;
            }
            for (int q = 0; q < snake_length; q++)
            {
                if (nizX[q] == j && nizY[q] == i)
                {
                    the_game.get_display().put(i, j, 'o');
                    pom++;
                }
            }
        }
    }
}

void Picture(game& the_game)
{
    for (int p = 0; p < width; p++) the_game.get_display().put(0, p, '#');
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1) the_game.get_display().put(i, j, '#');
        }
    }
    for (int p = 0; p < width; p++) the_game.get_display().put(height - 1, p, '#');
    system("cls");
    the_game.get_display().print(std::cout);
    the_game.get_display().clear();
}

void Input(game& the_game)
{
    the_game.get_inputs().read_keys();
    
    switch (the_game.get_inputs().get_current())
    {
    case game_key::left:
        dir = LEFT;
        break;
    case game_key::right:
        dir = RIGHT;
        break;
    case game_key::up:
        dir = UP;
        break;
    case game_key::down:
        dir = DOWN;
        break;
    case game_key::exit:
        game_over = true;
        break;
    }
}

void Work(game& the_game)
{
    switch (dir)
    {
    case LEFT:
        x--;
        if (x == fruitX && y == fruitY)
        {
            fruitX = rand() % 18 + 1;
            fruitY = rand() % 18 + 1;
            snake_length++;
        }
        for (int i = snake_length - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                nizX[i] = nizX[i - 1];
                nizY[i] = nizY[i - 1];
            }
            else
            {
                nizX[i] = x + 1;
                nizY[i] = y;
            }
        }
        break;
        //////////////////////////////////////////////////////////
    case RIGHT:
        x++;
        if (x == fruitX && y == fruitY)
        {
            fruitX = rand() % 18 + 1;
            fruitY = rand() % 18 + 1;
            snake_length++;
        }
        for (int i = snake_length - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                nizX[i] = nizX[i - 1];
                nizY[i] = nizY[i - 1];
            }
            else
            {
                nizX[i] = x - 1;
                nizY[i] = y;
            }
        }
        break;
        //////////////////////////////////////////////////////////
    case UP:
        y--;
        if (x == fruitX && y == fruitY)
        {
            fruitX = rand() % 18 + 1;
            fruitY = rand() % 18 + 1;
            snake_length++;
        }
        for (int i = snake_length - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                nizX[i] = nizX[i - 1];
                nizY[i] = nizY[i - 1];
            }
            else
            {
                nizX[i] = x;
                nizY[i] = y + 1;
            }
        }
        break;
        //////////////////////////////////////////////////////////
    case DOWN:
        y++;
        if (x == fruitX && y == fruitY)
        {
            fruitX = rand() % 18 + 1;
            fruitY = rand() % 18 + 1;
            snake_length++;
        }
        for (int i = snake_length - 1; i >= 0; i--)
        {
            if (i != 0)
            {
                nizX[i] = nizX[i - 1];
                nizY[i] = nizY[i - 1];
            }
            else
            {
                nizX[i] = x;
                nizY[i] = y - 1;
            }
        }
        break;
    }
    if (x == 0 || y == 0 || x == width - 1 || y == height - 1) game_over = true;
}


class a_klasa
{
public:
    a_klasa()
    {
        std::cout <<"konstruktor a\r\n";
    }
    // copy konstruktor
    a_klasa(const a_klasa& right)
    {
        std::cout << "copy konstruktor a\r\n";
    }
    ~a_klasa()
    {
        std::cout << "destruktor a\r\n";
    }
};

class b_klasa
{
    a_klasa unutra;
public:
    int a;
    b_klasa()
    {
        a = 99;
        std::cout << "konstruktor b\r\n";
    }
    // copy konstruktor
    b_klasa(const b_klasa& right)
        : unutra(right.unutra)
    {
        std::cout << "copy konstruktor b\r\n";
    }
    ~b_klasa()
    {
        std::cout << "destruktor b\r\n";
    }
};

void pom_func(b_klasa& b)
{

}

void konstruktor_example()
{
    b_klasa temp;
    pom_func(temp);
}

int main()
{
    srand(time(NULL));
    //konstruktor_example();
    game the_game(width, height);

    fruitX = rand() % 18 + 1;
    fruitY = rand() % 18 + 1;
    while (!the_game.is_game_over())
    {
        the_game.get_inputs().read_keys();

        the_game.print();

        std::ostringstream ss;
        the_game.get_display().print(ss);
        system("cls");
        std::cout << ss.str();
        /*Special_elements(the_game);
        Picture(the_game);
        Input(the_game);
        Work(the_game);*/
        for (int i = 0; i < 10000000; i++);
    }
    cout << "jbg";
    return 0;
}
