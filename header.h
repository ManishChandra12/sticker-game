#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>

void gotoxy(int,int);
void sleep(time_t);
void player1();
int stkr();
int stkr_com();
void main_single_player(void);
void main_two_player(void);
void error();
COORD coord={0,0}; //initialize the cursor posiion to (0,0)
void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//set the cursor position to corresponding address
}
void sleep(time_t delay)//pause the screen for specified time
{
    time_t timer0,timer1;
    time(&timer0);
    do
    {
        time(&timer1);
    }
    while((timer1-timer0)<delay);
}
int stkr()
{
    srand(time(NULL));//take seed from time() function
    int x1=((rand()) % 5);
    int x=x1+1;//generate random number between 1 and 5
    return x;
}
int stkr_com()
{
    srand(time(NULL));
    int y1=((rand()) % 5);
    int y=y1+1;
    return y;
}
void player1()
{
    int a;
    printf("%c",' ');
    for (a=1;a<=78;a++)
        printf("%c",'_');//display upper horizontal line with '-'
    printf("\n");
    for (a=1;a<=100;a++)
        printf("%c\t",'|');//display vertical lines with'|'
    for (a=1;a<=10;a++)
    {
        gotoxy(79,a);
        printf("%c",'|');//display rightmost vertical line with '|'
    }
    for (a=0;a<=79;a++)
    {
        gotoxy(a,11);
        printf("%c",'-');//display lower horizontal line with '-'
    }
    int j=4;
    for (a=1;a<=5;a++)
    {
        gotoxy(j,6);
        printf("%d",a);//display sticker's numbers at their centre
        j+=8;
    }
    int s=44;
    for (a=1;a<=5;a++)
    {
        gotoxy(s,6);
        printf("%d",a);
        s+=8;
    }
}
void error()
{
    puts("THE STICKER HAS ALREADY BEEN TURNED");
    puts("ENTER OTHER UNTURNED STICKER'S NUMBER");
}
#endif
