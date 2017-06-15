#include "header.h"
#include "single_player.c"
#include "two_player.c"
int main()
{
    int m;
    char e,k;
    PLAY0:
    gotoxy(30,5);
    puts("MAIN MENU");
    gotoxy(28,6);
    printf("%s","*************");
    gotoxy(30,10);
    puts("1.PLAY GAME");//display options
    gotoxy(30,11);
    puts("2.HOW TO PLAY");//display options
    gotoxy(30,12);
    puts("3.EXIT");//display options
    printf("\n\n");
    printf("\t\tENTER THE CORRESPONDING NUMBER TO YOUR CHOICE:");
    e=getch();
    switch(e)
    {
        case '1':
        {
            system("cls");
            gotoxy(30,10);
            puts("1.PLAY VERSUS HUMAN");
            gotoxy(30,11);
            puts("2.PLAY VERSUS COMPUTER");
            printf("\n\n");
            printf("\t\tENTER THE CORRESPONDING NUMBER TO YOUR CHOICE:");
            k=getch();
            switch(k)
            {
                case '1':
                    {
                    main_two_player();//call the function for two players
                    break;
                    }
                case '2':
                    {
                    main_single_player();//call the function for single player
                    break;
                    }
                default:
                    {
                    puts("PRESS ONLY THE CORRESPONDING NUMBER");
                    break;
                    }
            }
        break;
        }
        case '2'://display rule
        {
            system("cls");
            printf("\n\nTHERE ARE A TOTAL OF TEN STICKERS, FIVE YOURS AND FIVE OTHER PLAYER'S (OR       COMPUTER'S), TURNED IN SUCH A WAY THAT ITS BACK PORTION FACES US. TURN ANY      STICKER AS YOU DESIRE BY PRESSING THE NUMBER PRINTED ON ITS BACK. THEN OTHER    PLAYER (OR COMPUTER) TURNS ANOTHER STICKER. IF BOTH THE STICKERS MATCH, THE     PLAYER WHO TURNS THE STICKER LATER, GETS POINTS WHICH IS EQUAL TO THE MAXIMUM   NUMBER OF STICKERS TURNED TILL THAT MATCH. MOREOVER, ANOTHER PLAYER GETS THE    SAME NUMBER OF NEGATIVE POINTS. PLAYER WITH HIGHER SCORE AFTER THE TURN OF ALL  TEN STICKERS, WINS.");
            puts("\n\nPRESS ANY KEY TO GO BACK TO MAIN MENU");
            getch();
            system("cls");
            goto PLAY0;
            break;
        }
        case '3':
            exit(1);//goto the end of the program
        default:
        {
            puts("\n\t\tPRESS ONLY THE CORRESPONDING NUMBER");
            goto PLAY0;
            break;
        }
    }
    system("cls");
    puts("DO YOU WANT TO PLAY AGAIN?");
    puts("1.YES");
    puts("2.NO");
    PLAY3:
    printf("\t\tENTER THE CORRESPONDING NUMBER TO YOUR CHOICE:");
    m=getch();
    switch(m)
    {
        case '1':
            system("cls");
            goto PLAY0;//start a new game
            break;
        case '2':
            break;
        default:
            puts("PRESS 1 OR 2");
            goto PLAY3;
    }
getch();
return 0;
}
