#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "allfunc.h"
#include "firstStep.h"
#include "nextMove.h"
#include "supportingFunc.h"
#include "adjacentCell.h"
#include "openTwice.h"
#include "leaderBoard.h"
#include "loadgame.h"

int main()
{
    // display options to the user


    system("COLOR EC");
    printf("\n\t\tWelcome to our first game 'Minesweeper'\n\t\tplease choose one of the following :\n\t\t\t(1)to start anew game\n\t\t\t(2)to load your last game\n\t\t\t(3)to see the player's list\n");
    // take a choice from the user
    fflush(stdin);
    scanf("%c",&startGame);
    system("cls");
    // evaluating the choice of the user
    if(startGame=='1')/* start a new game */
    {newGame();
        }
    else if(startGame== '2')
    {
       loadgame();
    }
    else if(startGame== '3')
    {
        FILE*howMany=fopen("number of players .txt","r");
        fscanf(howMany,"%d",&number_of_players);
        fclose(howMany);

        FILE*showRank=fopen("rank.txt","r");
        char line[100];
        int i;
        printf("\t\t\t*HALL OF HONOR*\n");
        for(i=0; i<=number_of_players; i++)
        {

            fscanf(showRank,"%s",line);
            printf("\t\t%s\t\t\t",line);
            fscanf(showRank,"%s",line);
            printf("%s\n",line);
        }

        printf("\n\n\n\n");
        fclose(showRank);
        char keepPlay;
        printf("\n\nPress c to continue / any key to exit\n\n");
        scanf(" %c",&keepPlay);
        if(keepPlay=='c'){
        main();
        }


    }

    //  loosing(secret_grid,grid_shown_to_the_user);// i called it twice to show the grid when the user lost
    else
    {   printf("the options are crystal clear please choose one of them :p");
        main();
    }
    return 0;
}





