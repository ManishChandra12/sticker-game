void main_two_player(void)
{
    int a,b,e,f=0;
    int count_com=0;
    int count_pla=0;
    char *p1[15],*p2[15];
    system("cls");
    printf("ENTER PLAYER 1'S NAME(maximum 15 characters): ");
    gets(p1);
    printf("ENTER PLAYER 2'S NAME(maximum 15 characters): ");
    gets(p2);
    system("cls");
    player1();
    gotoxy(0,22);
    printf("%s's score",&p1);
    gotoxy(8,23);
    printf("%c",'0');
    gotoxy(63,22);
    printf("%s's score",&p2);
    gotoxy(71,23);
    printf("%c",'0');
    for (b=0;b<=4;b++)
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
        scanf("%d",&c[b]);
        gotoxy(0,14);
        printf("                                     ");
        printf("\n                                     ");
        printf("\n                                     ");
        gotoxy(0,15);
        if(b==1 && c[1]==c[0])
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
                    for(a=0;a<6;a++)
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
        if(b>0)
        {
            if (t1==t2)
            {
                gotoxy(0,18);
                puts("\t\t\t\tIT'S A MATCH");
                count_pla+=1+b;
                count_com-=(b+1);
                gotoxy(71,23);
                printf(" %d ",count_com);//display player2's score below its heading
                gotoxy(8,23);
                printf(" %d ",count_pla);//display player1's score below its heading
            }
            else
            {
                gotoxy(0,18);
                puts("\t\t\t\tNO MATCH    ");
            }
        }
        gotoxy(0,12);
        printf("\t\t\t\tITS %s's TURN            \n",&p2);
        printf("\n");

        int u[5];
        for(;f<=4;f++)
        {
            PLAY1:
            gotoxy(0,14);
            scanf("%d",&u[f]);//store player2's choice in u[f]
            gotoxy(0,14);
            printf("                                     ");
            printf("\n                                     ");
            printf("\n                                     ");
            gotoxy(0,15);
            if(f==1 && u[1]==u[0])//if for 2nd or above attempts, if player2 chooses same sticker, take another value of u[f]
            {
                error();
                goto PLAY1;
            }
            else if(f==2 && (u[2]==u[0] || u[2]==u[1]))
            {
                error();
                goto PLAY1;
            }
            else if(f==3 && (u[3]==u[0] || u[3]==u[1] || u[3]==u[2]))
            {
               error();
                goto PLAY1;
            }
            else if(f==4 && (u[4]==u[0] || u[4]==u[1] || u[4]==u[2] || u[4]==u[3]))
            {
                error();
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
                        sleep(1.2);//pause for 2.5 seconds
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
                default:
                {
                    puts("ENTER THE NUMBER FROM 1 TO 5");
                    goto PLAY1;
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
            printf(" %d ",count_pla);//display player1's score below its heading
            gotoxy(71,23);
            printf(" %d ",count_com);//display player2's score below its heading
        }
        else
        {
            gotoxy(0,18);
            puts("\t\t\t\tNO MATCH    ");
        }
        if(b==4)//after last sticker is turned
        {
            gotoxy(30,20);
            puts("PRESS ANY KEY TO VIEW THE WINNER");
            getch();//take a character from user and display the winner
        }
    }
    if(count_com>count_pla)
    {
        system("cls");
        gotoxy(30,10);
        printf("THE WINNER IS %s",&p2);
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
