#include "pch.h"
#include "definitions.h"
#include "game_display.h"

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


game_display display(width, height);

int pom = 0;

enum direction{STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;

void ispis(game_display& zikica)
{
    system("cls");
    display.print(std::cout);
}

void Picture()
{
     /*system("cls");
     std::ostringstream ss;
     for (int p = 0; p < width; p++) ss << "#";
     ss << endl;
     for (int i = 1; i < height-1; i++)
     {
         for (int j = 0; j < width; j++)
         {
             if (j == 0 || j == width - 1)
             {
                 ss << "#";
             }
             else if (y == i && x == j)
             {
                 ss << "O";
                 pom++;
             }
             else if (fruitY == i && fruitX == j)
             {
                 ss << "$";
                 pom++;
             }
             for (int q = 0; q < snake_length; q++)
                 if (nizX[q] == j && nizY[q] == i)
                 {
                     ss << "o";
                     pom++;
                 }
             if (pom == 0) ss << " ";
             pom = 0;
         }
         ss << endl;
     }
     for (int p = 0; p < width; p++) ss << "#";

     cout << ss.str();*/
    //std::ostringstream ss;
    for (int p = 0; p < width; p++) display.put(p, 0, '#');
    for (int i = 1; i < height - 1; i++)
    {
        ispis(display);
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                display.put(i, j, '#');
            }
            else if (y == i && x == j)
            {
                display.put(i, j, 'O');
                pom++;
            }
            else if (fruitY == i && fruitX == j)
            {
                display.put(i, j, '$');
                pom++;
            }
            for (int q = 0; q < snake_length; q++)
                if (nizX[q] == j && nizY[q] == i)
                {
                    display.put(i, j, 'o');
                    pom++;
                }
            if (pom == 0) display.put(i, j, ' ');
            pom = 0;

        }
    }
    for (int p = 0; p < width; p++) display.put(p, width, '#');
    system("cls");
    display.print(std::cout);

}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            game_over = true;
            break;
        }
    }
}

void Work()
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

int main()
{
    

    /*for (int i = 0; i < 30; i++)
    {
        display.clear();
        display.put(i, 20, 'Q');
        system("cls");
        display.print(std::cout);
    }*/


    fruitX = rand() % 18 + 1;
    fruitY = rand() % 18 + 1;
    while (!game_over)
    {
        Picture();
        Input();
        Work();
        for (int i = 0; i < 10000000; i++);
    }
    cout << "jbg";
    return 0;
}
