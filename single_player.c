#include "header.h"

void main_single_player(void)
{
    int a,b,e,f=0;
    int count_com=0;
    int count_pla=0;
    char *p1[15];
    system("cls");
    printf("ENTER PLAYER 1'S NAME(maximum 15 characters): ");
    gets(p1);
    system("cls");
    player1();//display stickers
    gotoxy(0,22);
    printf("%s's score",&p1);//display heading of player1 score
    gotoxy(8,23);
    printf("%c",'0');
    gotoxy(63,22);
    printf("Comp's score");//display heading of computer score
    gotoxy(71,23);
    printf("%c",'0');
    for (b=0;b<=4;b++)//loop to turn both player's and computer's chosen sticker
    {
        int t2=stkr_com();
        gotoxy(0,14);
        puts("\t\t\t\t\t");
        int c[5];
        gotoxy(0,12);
        printf("\t\t\t\tITS %s's TURN         \n",&p1);
        puts("\tENTER THE STICKER'S NUMBER YOU WANT TO TURN AND PRESS ENTER:");
        PLAY:
        gotoxy(0,14);
        scanf("%d",&c[b]);//store th chosen number in c[b]
        gotoxy(0,14);
        printf("                                     ");
        printf("\n                                    ");
        printf("\n                                     ");
        gotoxy(0,15);
        if(b==1 && c[1]==c[0])//if player tries to turn the sticker that has already been turned, take c[b] again
        {
            error();
            goto PLAY;
        }
        else if(b==2 && (c[2]==c[0] || c[2]==c[1]))
        {
            error();
            goto PLAY;
        }
        else if(b==3 && (c[3]==c[0] || c[3]==c[1] || c[3]==c[2]))
        {
            error();
            goto PLAY;
        }
        else if(b==4 && (c[4]==c[0] || c[4]==c[1] || c[4]==c[2] || c[4]==c[3]))
        {
            error();
            goto PLAY;
        }
        switch (c[b])
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                {
                sleep(1.2);
                for(a=0;a<6;a++)//display the contents of the sticker
                {
                    if(a<3)
                    {
                        gotoxy(7*c[b]+c[b]-3-a,6);
                        printf("%c",stkr());
                    }
                    else
                    {
                        gotoxy(7*c[b]+c[b]-a,5);
                        printf("%c",stkr());
                    }
                }
                break;
                }
            default:
            {
                puts("ENTER THE NUMBER FROM 1 TO 5");
                goto PLAY;
                break;
            }
        }
        int t1=stkr();
        if(b>0)//for 2nd or above attempts of player1
        {
            if (t1==t2)//if player1 and computer turns the similar sticker
            {
                gotoxy(0,18);
                puts("\t\t\t\tIT'S A MATCH");
                count_pla+=1+b;//increase player1's score by number of stickers turned before the match
                count_com-=(b+1);//decrease computer's score by same number
                gotoxy(71,23);
                printf(" %d ",count_com);
                gotoxy(8,23);
                printf(" %d ",count_pla);
            }
            else
            {
                gotoxy(0,18);
                puts("\t\t\t\tNO MATCH    ");
            }
        }
        gotoxy(0,12);
        printf("\t\t\t\tITS Computer's TURN            \n");
        gotoxy(0,13);
        printf("\t\t\t\t\t\t\t\t\t");
        printf("\n");
        int u[5];
        for(;f<=4;f++)
        {
            PLAY1:
            srand(time(NULL));
            int r1=rand()%5;
            u[f]=r1+1;//generate random number between 1 and 5
            if(f==1 && u[1]==u[0])//if for second or above attempts, if same random number is generated
            {

                goto PLAY1;//generate another random number
            }
            else if(f==2 && (u[2]==u[0] || u[2]==u[1]))
            {

                goto PLAY1;
            }
            else if(f==3 && (u[3]==u[0] || u[3]==u[1] || u[3]==u[2]))
            {
                goto PLAY1;
            }
            else if(f==4 && (u[4]==u[0] || u[4]==u[1] || u[4]==u[2] || u[4]==u[3]))
            {

                goto PLAY1;
            }
            switch(u[f])
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    {
                        sleep(2.5);//pause for 2.5 seconds
                        for(a=0;a<6;a++)//display the contents of the sticker
                        {
                            if(a<3)
                            {
                                gotoxy(7*(u[f]+5)+(u[f]+5)-3-a,6);
                                printf("%c",stkr_com());
                            }
                            else
                            {
                                gotoxy(7*(u[f]+5)+(u[f]+5)-a,5);
                                printf("%c",stkr_com());
                            }
                        }
                    break;
                    }
            }
            break;
        }
        f+=1;
        t2=stkr_com();
        if(t2==t1)
        {
            gotoxy(0,18);
            puts("\t\t\t\tIT'S A MATCH");
            count_com+=1+b;
            count_pla-=(b+1);
            gotoxy(8,23);
            printf(" %d ",count_pla);
            gotoxy(71,23);
            printf(" %d ",count_com);
        }
        else
        {
            gotoxy(0,18);
            puts("\t\t\t\tNO MATCH    ");
        }
        if(b==4)
        {
            gotoxy(30,20);
            puts("PRESS ANY KEY TO VIEW THE WINNER");
            getch();//take a character from user
        }
    }
    if(count_com>count_pla)
    {
        system("cls");
        gotoxy(30,10);
        printf("THE WINNER IS COMPUTER");
        puts("\npress any key to continue.....");
    }
    else if(count_pla>count_com)
    {
        system("cls");
        gotoxy(30,10);
        printf("THE WINNER IS %s",&p1);
        puts("\npress any key to continue.....");
    }
    else
    {
        system("cls");
        gotoxy(30,10);
        printf("THE GAME ENDED IN A DRAW");
        puts("\npress any key to continue.....");
    }
getch();
}
