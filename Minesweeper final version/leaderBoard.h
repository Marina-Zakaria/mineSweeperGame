#ifndef LEADERBOARD_H_INCLUDED
#define LEADERBOARD_H_INCLUDED
int creat_leaderBoard (char champ [],int score )
{
    char leaderBoard[100][100]={{'\0'}};
    char c[100];
    int scores [100];
    int players=0,index,flag=0;
    int TotalScore=0;




    FILE *names=fopen("names.txt", "r");
    FILE*scoree=fopen("scores.txt", "r");
    fscanf(scoree,"%d",&players);
    printf("%d",players);


    for (i=0; i<=players; i++)
    {

        fscanf(names,"%s",c);
        strcpy(leaderBoard[i],c);
    }

    for(j=0; j<=players; j++)
    {
        if(strcmp(champ,leaderBoard[j])== 0)
        {
            scores[j]+=score;
            flag = 1 ;
            index=j;
            break;
        }

    }




    for (i=0; i<=players; i++)
    {
        fscanf(scoree,"%d",&scores[i]);

    }
    fclose(scoree);
    fclose(names);

    if(!flag)
    {
        players++;
        strcpy(leaderBoard[players],champ);
        scores[players]=score;
        index=players;
        TotalScore=score;
    }
    else{
        scores[index]+=score;
        TotalScore=scores[index];
    }
    int name_index =(sort_scores(index,scores));
//sort numbers and get index of the position of new score to use it in array of leaderBoard

//end of fn
//fix array of leaderBoard
    for (i=index-1; i>=name_index; i--)
    {
        char tmp [100];
        strcpy(tmp,leaderBoard[i]);
        strcpy(leaderBoard[i],leaderBoard[i+1]);
        strcpy(leaderBoard[i+1],tmp);
    }
//fixed

// sort scores && sort names



    FILE*pointer=fopen("rank.txt","w");
    for(i=0; i<=players; i++)
    {
        fprintf(pointer,"%s\t",leaderBoard[i]);
        fprintf(pointer,"%d\n",scores[i]);
    }
    fclose(pointer);




    FILE*updatePointer=fopen("names.txt","w");
    for(j=0; j<=players; j++)
    {
        fprintf(updatePointer,"%s\n",leaderBoard[j]);
    }
    fclose(updatePointer);

    FILE*updatePointer2=fopen("scores.txt","w");
    fprintf(updatePointer2,"%d\n",players);
    for(j=0; j<=players; j++)
    {
        fprintf(updatePointer2,"%d\n",scores[j]);
    }

    fclose(updatePointer2);

    FILE*showRank=fopen("rank.txt","r");
    char line[100];
    printf("\t\t\t*LEADER BOARD*\n");
    for(i=0; i<=players; i++){

            fscanf(showRank,"%s",line);
            printf("\t\t%s\t\t\t",line);
            fscanf(showRank,"%s",line);
            printf("%s\n",line);
    }

    printf("\n\n\n\n");
    fclose(showRank);

    FILE*howMany=fopen("number of players .txt","w");
    fprintf(howMany,"%d\n",players);
    fclose(howMany);

    return TotalScore;

}
// please don't change any thing Any thing in this function




#endif // LEADERBOARD_H_INCLUDED
