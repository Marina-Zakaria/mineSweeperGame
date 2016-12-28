#ifndef FIRSTSTEP_H_INCLUDED
#define FIRSTSTEP_H_INCLUDED


// a function to take first move from the user and design the map depending on it

void take_first_move (int n,int minesX[n],int minesY[n],char secret_grid[X][Y],char grid_shown_to_the_user[X][Y])
{


    int x,y; // first coordinates
    // take coordinates
    printf("Let's play :D !! \nmake your first move \nenter x coordinate : ");
    fflush(stdin);
    scanf("%d",&x);
    printf("enter y coordinate : ");
    fflush(stdin);
    scanf("%d",&y);
    // check coordinates
    if (!in_range(x,X)||!in_range(y,Y)){
        print_grid_to_the_user(grid_shown_to_the_user);
        printf("these coordinates are out of range please input valid coordinates \n");
        take_first_move (number_of_mines, minesX,minesY,secret_grid,grid_shown_to_the_user);
        next_move(secret_grid,grid_shown_to_the_user);
    }
    moves=1; // initialize number of moves


    int k=0; // counter

    // put mines
    while (k<n)
    {
        srand(time(NULL)); // set random function to produce different values
        // make values in valid range
        i=rand()%X;
        j=rand()%Y;
        // exclude repeated values and the first opened cell coordinates
        // also exclude the first cell in a row or a column to make it easier for the user
        if (i!=x&&j!=y&&((X==2&&Y==2)||(i!=0&&j!=0))&&!found_pair(i,k,minesX,j,minesY))
        {
            minesX[k]=i;
            minesY[k]=j;
            secret_grid[i][j]='*';
            k++;
        }
    }



// put numbers in cells according to number of adjacent mines
    for(i=0; i<X; i++)
    {
        for (j=0; j<Y; j++)
        {
            if (secret_grid[i][j]=='*')
            {
                if (secret_grid[i+1][j]!='*'&&in_range(i+1,X))secret_grid[i+1][j]++;
                if (secret_grid[i-1][j]!='*'&&in_range(i-1,X))secret_grid[i-1][j]++;
                if (secret_grid[i+1][j+1]!='*'&&in_range(i+1,X)&&in_range(j+1,Y))secret_grid[i+1][j+1]++;
                if (secret_grid[i+1][j-1]!='*'&&in_range(i+1,X)&&in_range(j-1,Y))secret_grid[i+1][j-1]++;
                if (secret_grid[i-1][j+1]!='*'&&in_range(i-1,X)&&in_range(j+1,Y))secret_grid[i-1][j+1]++;
                if (secret_grid[i-1][j-1]!='*'&&in_range(i-1,X)&&in_range(j-1,Y))secret_grid[i-1][j-1]++;
                if (secret_grid[i][j+1]!='*'&&in_range(j+1,Y))secret_grid[i][j+1]++;
                if (secret_grid[i][j-1]!='*'&&in_range(j-1,Y))secret_grid[i][j-1]++;

            }
        }
    }
    // save the map
    FILE*file=fopen("secret map.txt", "w");
    fprintf(file,"This the map of the current game 'hope you like it :)'\n\n\n");

    for(i=0; i<X; i++)
    {
        for (j=0; j<Y; j++)
        {   if (secret_grid[i][j]=='0') secret_grid[i][j]=' ';
            fprintf(file,"%c    ",secret_grid[i][j]);
        }
        fprintf(file,"\n");
    }

    fclose(file);

    // open first cell
    if (secret_grid[x][y]==' ')
    {
        grid_shown_to_the_user[x][y]=' ';
        open_adjacent_empty(x,y,secret_grid,grid_shown_to_the_user);
        // if first cell is empty call a function to open adjacent empty cells
    }
    else grid_shown_to_the_user[x][y]=secret_grid[x][y];
    print_grid_to_the_user(grid_shown_to_the_user);




}








#endif // FIRSTSTEP_H_INCLUDED
