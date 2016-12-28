

void take_first_move (int n,int minesX[n],int minesY[n],char secret_grid[X][Y],char grid_shown_to_the_user[X][Y])
{
    int x,y;
    printf("Let s play :D !! \nmake your first move \n");
    scanf("%d %d",&x,&y);
    int k=0;
    // put mines
    while (k<n)
    {
        i=rand()%X;
        j=rand()%Y;
        if (!((i==x&&j==y)||found_pair(i,k,minesX,j,minesY)))
        {
            minesX[k]=i;
            minesY[k]=j;
            k++;
        }
    }

    for(i=0; i<X; i++)
    {
        for (j=0; j<Y; j++)
        {
            if (found_pair(i,n,minesX,j,minesY))
            {
                secret_grid[i][j]='M';


            }
        }
    }

// put numbers
    for(i=0; i<X; i++)
    {
        for (j=0; j<Y; j++)
        {
            if (secret_grid[i][j]=='M')
            {
                if (secret_grid[i+1][j]!='M'&&in_range(i+1,X))secret_grid[i+1][j]++;
                if (secret_grid[i-1][j]!='M'&&in_range(i-1,X))secret_grid[i-1][j]++;
                if (secret_grid[i+1][j+1]!='M'&&in_range(i+1,X)&&in_range(j+1,Y))secret_grid[i+1][j+1]++;
                if (secret_grid[i+1][j-1]!='M'&&in_range(i+1,X)&&in_range(j-1,Y))secret_grid[i+1][j-1]++;
                if (secret_grid[i-1][j+1]!='M'&&in_range(i-1,X)&&in_range(j+1,Y))secret_grid[i-1][j+1]++;
                if (secret_grid[i-1][j-1]!='M'&&in_range(i-1,X)&&in_range(j-1,Y))secret_grid[i-1][j-1]++;
                if (secret_grid[i][j+1]!='M'&&in_range(j+1,Y))secret_grid[i][j+1]++;
                if (secret_grid[i][j-1]!='M'&&in_range(j-1,Y))secret_grid[i][j-1]++;

            }
        }
    }
    print_grid_to_the_user(secret_grid);
    printf("\n\n");

    if (secret_grid[x][y]=='0')
    {
        grid_shown_to_the_user[x][y]=' ';
        open_adjacent_empty(x,y,secret_grid,grid_shown_to_the_user);
    }
    else grid_shown_to_the_user[x][y]=secret_grid[x][y];
    print_grid_to_the_user(grid_shown_to_the_user);
}


