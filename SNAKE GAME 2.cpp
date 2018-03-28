#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iosfwd>
#include <ctime>
using namespace std;
bool gameover;
const int width = 20;
const int height =20;
int x , y , fruitx , fruity ,score;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void setup()
{
    gameover = false ;
    dir = STOP ;
    x=width/2;
    y=height/2;
    fruitx=rand  () % width;
    fruity = rand() % height;
    score = 0;

}
void Draw()
{
    system("cls"); //system ("clear");
    for (int i =0 ; i<width+2 ;i++)
        cout<<"#";
    cout<<endl;

    for(int i=0 ; i<height ;i++)
    {
        for(int j=0 ; j<height ;j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
                cout<<"o";
            else if (i==fruity && j==fruitx)
                cout<<"f";
            else
                cout<<" ";
            if(j==width-1)
                cout<<"#";
        }
        cout<<endl;
    }


    for (int i =0 ; i<width+2 ;i++)
        cout<<"#";
    cout<<endl;
}
void Input()
{
    if(_kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameover = true;
				break;
		}

	}

}
void logic()
{
    switch (dir)
	{
        case 'STOP':
            break;
		case 'LEFT':
			x --;
			break;
		case 'UP':
			y --;
			break;
		case 'RIGHT':
			x ++;
			break;
		case 'DOWN':
			y ++;
			break;
		default:
			break;
	}

    }


int main()
{
    setup();
    while(!gameover)
    {
        Draw();
        Input();
        logic();
        //sleep(10); sleep(10);
    }


    return 0;
}
/*
bool gameover;
const int width = 20;
const int height = 10;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int x, y, foodx, foody, score;


void setUp();
//1)set the snake at the centre of the map.
//2)set the food position

void draw();
/*
draw the map:
#########
#  	    #
#########
*/

/*void input();
//get the input of W, A, S, D from the keyboard.
//make switch case.

void logic();
//1)direction of the snake using W,A,S,D.
//2)Random food position
//3)Eat the food and generate another position.
//4)Hit the wall = GameOver.
//5)Tail of the snake grow when eat the food.



using namespace std;

int main()
{
	srand(time(0));
	setUp();
	while(!gameover)
	{
		draw();
		input();
		logic();

	}



	return 0;
}

void setUp()
{

	gameover = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	foodx = rand()%width;
	foody = rand()%height;

}

void draw()
{
	system("clear");

	for(int i = 0; i < width; i++)
		cout << "#";
	cout << endl;

	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i <width; i++)
		{
			if(i ==0)
				cout << "#";
			else if(i == width -1)
				cout << "#";
			else if(i == x && j == y)
				cout << "O";
			else if(i == foodx && j == foody)
				cout << "F";
			else
				cout << " ";
		}

		cout << endl;
	}
	cout<<endl;

	for(int i = 0; i < width; i++)
		cout << "#";
	cout << endl;
}


void input()
{

	if(_kbhit())
	{
		switch(getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameover = true;
		}

	}
}
void logic()
{
	switch (dir)
	{
		case 'LEFT':
			x --;
			break;
		case 'UP':
			y --;
			break;
		case 'RIGHT':
			x ++;
			break;
		case 'DOWN':
			y ++;
			break;
		default:
			break;
	}

	if(x > width || x < 0)
		gameover = true;
	if(y > height || y < 0)
		gameover =true;

	if(x == foodx && y == foody)
	{
		score = score + 10;
		foodx = rand()%width;
		foody = rand()%height;
	}

}
*/
