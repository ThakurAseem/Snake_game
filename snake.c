#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
//checking for operating system
#ifdef _WIN32
    //code for Windows (32-bit and 64-bit, this part is common)
    #include <conio.h>
    #define CLEARSCREEN system("cls")
    #define CHECKKEY _kbhit()
    #define NBGETCHAR getch()

#elif __APPLE__
    //code for mac
    #define CLEARSCREEN system("clear")
    #define CHECKKEY
    #define NBGETCHAR

#elif __linux__
    //code for linux
    #define CLEARSCREEN system("clear")
    #define CHECKKEY
    #define NBGETCHAR
#else
#   error "Unknown compiler"
#endif


/*Declaring every function in the start*/
void restart();
int main();
void over();
void setup();
void draw();
void input();
void logic();

//Global variables
const int width=20,height=10;
int gameover;
int score;
int x,y,fruitX,fruitY;
enum dect{STOP=0,LEFT,RIGHT,TOP,DOWN};
enum dect dir;
char mouth;

/*Declare the initial values of the code in setup function */
void setup(){
    gameover=0;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand() % width;
    fruitY=rand() % height;
    score=0;
    mouth='>';
}

/*To draw the box and snake body*/
void draw(){
    system("cls");
    for(int i=0 ; i <= width+1 ; i++){
        printf("#");
    }
    printf("\n");
    for(int i=0 ; i < height ; i++){
        for(int j=0 ; j < width ; j++){
            if(j==0){
                printf("#");
            }
            if(i== y && j== x){
                printf("%c",mouth);
            }
            else if(i==fruitY && j==fruitX){
                printf("@");
            }
            else{
             printf(" ");
            }
            if(j==width-1)
                printf("#");
        }
         printf("\n");
    }
    for(int i=0 ; i <= width+1 ; i++){
        printf("#");
    }
    printf("\n");
    printf("Score: %d\n",score);
}

/*Function for taking keyword input*/
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			mouth='<';
			break;
		case 'd':
			dir = RIGHT;
			mouth='>';
			break;
		case 'w':
			dir = TOP;
			mouth='^';
			break;
		case 's':
			dir = DOWN;
			mouth='v';
			break;
		case 'x':
			over();
			break;
		}
	}
}

/*Function used for the movement of the snake*/
void logic(){
   switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case TOP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
   if(x > width || x<0 )
     over();
   if(y > height || y<0)
     over();
   if(x==fruitX && y==fruitY){
    score+=5;
    fruitX=rand() % width;
    fruitY=rand() % height;
   }
}
//Screen which is seen when u hit the wall or yourself at the end of game
void over(){
	system("cls");
			printf("\n");
			printf("\t   ((((      ()     ()      () (((((((      (()) (        ) ((((((  ()))))\n");
			printf("\t (     (    (  )    ( )    ( ) (           (    ) (      )  (       ()   ))\n");
			printf("\t(          ((()))   (  )  (  ) ((((       (      ) (    )   (((     ()))))\n");
			printf("\t (  ((((  (      )  (   )(   ) (           (    )   (  )    (       ()   ))\n");
			printf("\t   ((  ( (        ) (        ) (((((((      (())     ()     ((((((  ()    ))\n");

   printf("\n\n");
      restart();
}

//Function for the restart of the game
void restart(){
    char KEY;
    int valid=0;
    while(!valid){
    printf("If u wanna play the game again press Y else Press N\n");
    scanf("%c",&KEY);
    if(KEY=='y' || KEY=='Y'){
        main();
        valid=1;
    }
    else if(KEY=='n'  || KEY=='N'){
        gameover=1;
        valid=1;
    }
    else{
        system("cls");
        printf("Plzz press the valid key");
        valid=0;
    }
    }
    system("cls");
}



int main(){
    setup();
    while(!gameover){
        draw();     //To draw the snake mouth and the box
        input();    //function for taking keyboard input
        logic();    //Function for the moment of the snake
    }

return 0;
}
