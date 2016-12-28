#ifndef SUPPORTINGFUNC_H_INCLUDED
#define SUPPORTINGFUNC_H_INCLUDED

// function to take the size of the grid from the user
void take_coordinates(int *X,int *Y)
{
    system("COLOR F0");
    printf("\t\tprogrammers say Hello from the other side :D \n\t\tPlease enter the size of the grid \n\t\tEnter number of rows : "); //greeting message
    fflush(stdin);
    scanf("%d",X);
    printf("\n\t\tEnter number of columns : ");
    fflush(stdin);
    scanf("%d",Y);
    if (*X<2||*Y<2) // check the input of the user
    {
        system("cls");
        printf("\n\t\tminimum size 2*2 \n\t\tplease reenter a suitable size\n "); // send a warning msg if wrong input
        take_coordinates(X,Y); // second chance to enter right size
    }
    else if (*X>30||*Y>30) // check the input of the user
    {
        system("cls");
        printf("\n\t\tmaximum size 30*30 \n\t\t please reenter a suitable size\n\n\n "); // send a warning msg if wrong input
        take_coordinates(X,Y); // second chance to enter right size
    }

}

// function that initializes a new grid
void initialize_grid(char grid_shown_to_the_user[X][Y],char secret_grid[X][Y])
{

    for(i=0; i<X; i++)
    {
        for (j=0; j<Y; j++)
        {
            grid_shown_to_the_user[i][j]='x';
            secret_grid[i][j]='0';
        }
    }


}

// a function that prints the grid to the user (called after every move )
void print_grid_to_the_user(char grid_shown_to_the_user[X][Y])
{
    system("cls");
    printf("       ");
    for(i=0; i<Y; i++)
    {
        printf("[%2d] ",i);
    }
    printf("\n\n");
    for(i=0; i<X; i++)
    {
        printf("[%2d]  ",i);
        for (j=0; j<Y; j++)
        {
            printf("%c %2c ",179,grid_shown_to_the_user[i][j]);
        }
        printf("%c\n\n",179);
    }
    // display time passed
    timePassed=clock();
    float time =(float)(timePassed-newTime)/CLOCKS_PER_SEC;// the diffrence between the time right now and before starting the game
    printf("Time passed : %d min %d sec\n",(int)time/60,(int)time%60);
    // display flags left , num of moves and num of ?
    printf("number of flags %d\n",num_of_flags);
    printf("number of moves %d\n",moves);
    printf("number of question marks %d\n\n\n",num_of_questionMarks);

}



// a function to find a  mapped pair in 2 arrays

int found_pair(int x,int n,int array1[n],int y,int array2[n])
{

    int i,found=0;
    for (i=0; i<n&&n!=0; i++)
    {
        if (x==array1[i]&&y==array2[i])
        {
            found=1;
            break;
        }
    }

    return found;
}


// a function to make sure that the coordinates are in range of the grid


int in_range (int x,int n)
{
    if (x<n&&x>=0)
        return 1;
    else return 0;
}

// a function to check if the user has won called after every move

int check_if_win(char grid_shown_to_the_user[X][Y],char secret_grid[X][Y],int number_of_mines)
{
    int k=0; //counter
    for(i=0; i<X; i++)
    {
        for(j=0; j<Y; j++)
        {
            if ((grid_shown_to_the_user[i][j]=='x' || grid_shown_to_the_user[i][j]=='?')&&secret_grid[i][j]!='*') return 0;
            else if  (grid_shown_to_the_user[i][j]=='x'||grid_shown_to_the_user[i][j]=='?'||grid_shown_to_the_user[i][j]=='F')
            {
                if(secret_grid[i][j]=='*')k++;
            }
        }
    }

    if(k==number_of_mines)
    {
        int score = (int)(pow(X,4) * pow(Y,4))/(moves*(timePassed-newTime)/CLOCKS_PER_SEC); //calculate score
        char champ[50];
        system("COLOR 0A");
        print_grid_to_the_user(secret_grid);
        printf("enter your name \n ");// takes the name of the player
        fflush(stdin);
        scanf(" %s",champ);
        // make the name insensitive case
        for(i=0; i< strlen(champ); i++)
        {
            if(isupper(champ[i]))
            {
                champ[i]+=32;
            }
        }
        int totalScore=creat_leaderBoard (champ,score);// function call to add the score to the leader board
        printf("\nyour score in this game is %d\n",score);
        printf("\nyour Total score is %d\n\n",totalScore);

        return 1;
    }
    else return 0;

}
// function called in case of loosing the game
void loosing(char secret_grid[X][Y],char grid_shown_to_the_user[X][Y])
{
    int m,n;// counters
    if(game_over==1)
    {
        for(m=0; m<X; m++ )
        {
            for(n=0; n<Y; n++)
            {
                if(grid_shown_to_the_user[m][n]=='F' && secret_grid[m][n]!='*')
                {
                    grid_shown_to_the_user[m][n]='_';
                }
                if (secret_grid[m][n]=='*'&&grid_shown_to_the_user[m][n]!='!' ) grid_shown_to_the_user[m][n]='*';
            }
        }
        print_grid_to_the_user(grid_shown_to_the_user);
    }

}


int sort_scores (int index,int arr[])
{
    int temp=arr[index];
    for (i=index-1; i>=0; i--)
    {
        if(arr[i]<temp)
        {
            arr[i]^=arr[i+1];
            arr[i+1]^=arr[i];
            arr[i]^=arr[i+1];
        }
        else
        {
            arr[i+1]=temp;
            break;
        }
    }
    return i+1;
}

char playAgain()
{
    printf("Play again? \ny:Yes\tn:NO\n\t");//keep playing
    char playAgain;
    fflush(stdin);
    scanf(" %c",&playAgain);
    return playAgain;

}

void newGame (){

        system("cls");
        take_coordinates(&X,&Y); // function call to take the size of the grid
        char grid_shown_to_the_user[X][Y]; // declare a 2D array to show the moves to the user
        char secret_grid[X][Y]; // declare a 2D array which contain the map of the game to use as reference during the game but can not be seen by the user
        initialize_grid(grid_shown_to_the_user,secret_grid);// function call to initialize a grid
        number_of_mines = 1+(X*Y)/10; // calculate number of mines depending on the size of thee grid
        num_of_flags=1+(X*Y)/10;// setting number of flags equal to number of mines
        newTime=clock();//recording time before playing
        system("COLOR F9");
        print_grid_to_the_user(grid_shown_to_the_user); // function call to print the grid to the user totally closed

        // declare 2 arrays to store coordinates of mines
        int minesX[number_of_mines];
        int minesY[number_of_mines];
        // call function to take first move from the user
        take_first_move (number_of_mines, minesX,minesY,secret_grid,grid_shown_to_the_user);
        // function call to continue the game till it is over
        next_move(secret_grid,grid_shown_to_the_user);


}





#endif // SUPPORTINGFUNC_H_INCLUDED
