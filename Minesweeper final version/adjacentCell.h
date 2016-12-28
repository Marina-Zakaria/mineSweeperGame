#ifndef ADJACENTCELL_H_INCLUDED
#define ADJACENTCELL_H_INCLUDED

// function to open adjacent empty cells based on DFS
void open_adjacent_empty(int i,int j,char secret_grid[X][Y],char grid_shown_to_the_user[X][Y])
{



    if((grid_shown_to_the_user[i+1][j]=='x'|| grid_shown_to_the_user[i+1][j]=='?') &&in_range(i+1,X)) //1
    {
        if(grid_shown_to_the_user[i+1][j]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i+1][j]==' ')
        {
            grid_shown_to_the_user[i+1][j]=' ';

            open_adjacent_empty(i+1,j,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i+1][j]<'9'&&secret_grid[i+1][j]!='*')
        {
            grid_shown_to_the_user[i+1][j]=secret_grid[i+1][j];
        }
    }
    if((grid_shown_to_the_user[i-1][j]=='x'|| grid_shown_to_the_user[i-1][j]=='?')&&in_range(i-1,X)) //2
    {
        if(grid_shown_to_the_user[i-1][j]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i-1][j]==' ')
        {
            grid_shown_to_the_user[i-1][j]=' ';

            open_adjacent_empty(i-1,j,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i-1][j]<'9'&&secret_grid[i-1][j]!='*')
        {
            grid_shown_to_the_user[i-1][j]=secret_grid[i-1][j];
        }
    }
    if((grid_shown_to_the_user[i][j+1]=='x'|| grid_shown_to_the_user[i][j+1]=='?')&&in_range(j+1,Y)) //3
    {
        if(grid_shown_to_the_user[i][j+1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i][j+1]==' ')
        {
            grid_shown_to_the_user[i][j+1]=' ';

            open_adjacent_empty(i,j+1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i][j+1]<'9'&&secret_grid[i][j+1]!='*')
        {
            grid_shown_to_the_user[i][j+1]=secret_grid[i][j+1];
        }
    }
    if((grid_shown_to_the_user[i][j-1]=='x' || grid_shown_to_the_user[i][j-1]=='?')&&in_range(j-1,Y)) //4
    {
        if(grid_shown_to_the_user[i][j-1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i][j-1]==' ')
        {
            grid_shown_to_the_user[i][j-1]=' ';

            open_adjacent_empty(i,j-1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i][j-1]<'9'&&secret_grid[i][j-1]!='*'&&in_range(j-1,Y))
        {
            grid_shown_to_the_user[i][j-1]=secret_grid[i][j-1];
        }
    }
    if((grid_shown_to_the_user[i+1][j+1]=='x' || grid_shown_to_the_user[i+1][j+1]=='?')&&in_range(j+1,Y)&&in_range(i+1,X)) //5
    {
        if(grid_shown_to_the_user[i+1][j+1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i+1][j+1]==' ')
        {
            grid_shown_to_the_user[i+1][j+1]=' ';

            open_adjacent_empty(i+1,j+1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i+1][j+1]<'9'&&secret_grid[i+1][j+1]!='*')
        {
            grid_shown_to_the_user[i+1][j+1]=secret_grid[i+1][j+1];
        }
    }
    if((grid_shown_to_the_user[i-1][j+1]=='x' || grid_shown_to_the_user[i-1][j+1]=='?')&&in_range(j+1,Y)&&in_range(i-1,X)) //6
    {
        if(grid_shown_to_the_user[i-1][j+1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i-1][j+1]==' ')
        {
            grid_shown_to_the_user[i-1][j+1]=' ';

            open_adjacent_empty(i-1,j+1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i-1][j+1]<'9'&&secret_grid[i-1][j+1]!='*')
        {
            grid_shown_to_the_user[i-1][j+1]=secret_grid[i-1][j+1];
        }
    }
    if((grid_shown_to_the_user[i+1][j-1]=='x' || grid_shown_to_the_user[i+1][j-1]=='?')&&in_range(j-1,Y)&&in_range(i+1,X)) //7
    {
        if(grid_shown_to_the_user[i+1][j-1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i+1][j-1]==' ')
        {
            grid_shown_to_the_user[i+1][j-1]=' ';

            open_adjacent_empty(i+1,j-1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i+1][j-1]<'9'&&secret_grid[i+1][j-1]!='*')
        {
            grid_shown_to_the_user[i+1][j-1]=secret_grid[i+1][j-1];
        }
    }
    if((grid_shown_to_the_user[i-1][j-1]=='x' || grid_shown_to_the_user[i-1][j-1]=='?')&&in_range(j-1,Y)&&in_range(i-1,X)) //8
    {
        if(grid_shown_to_the_user[i-1][j-1]=='?')
        {
            num_of_questionMarks--;
        }
        if (secret_grid[i-1][j-1]==' ')
        {
            grid_shown_to_the_user[i-1][j-1]=' ';

            open_adjacent_empty(i-1,j-1,secret_grid,grid_shown_to_the_user);
        }
        else if(secret_grid[i-1][j-1]<'9'&&secret_grid[i-1][j-1]!='*')
        {
            grid_shown_to_the_user[i-1][j-1]=secret_grid[i-1][j-1];
        }
    }





}

#endif // ADJACENTCELL_H_INCLUDED
