#ifndef OPENTWICE_H_INCLUDED
#define OPENTWICE_H_INCLUDED

int check_open_twice(int x, int y,char grid_shown_to_the_user[X][Y])
{
    if(grid_shown_to_the_user[x][y]>'0'&& grid_shown_to_the_user[x][y]<'9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// a function that handle the reopened cells
void open_twice(int x, int y,char grid_shown_to_the_user[X][Y],char secret_grid[X][Y])
{   // check if num of flags = the num in the cell
    int num_of_adjacent_flags=0;
    if(grid_shown_to_the_user[x-1][y-1]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x-1][y]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x-1][y+1]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x][y-1]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x][y+1]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x+1][y-1]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x+1][y]=='F')num_of_adjacent_flags++;
    if(grid_shown_to_the_user[x+1][y+1]=='F')num_of_adjacent_flags++;

    if((grid_shown_to_the_user[x][y]-'0')== num_of_adjacent_flags)
    {
        if(grid_shown_to_the_user[x-1][y-1]=='x' || grid_shown_to_the_user[x-1][y-1]=='?')//1
        {
            if(secret_grid[x-1][y-1]=='*')
            {
                grid_shown_to_the_user[x-1][y-1]='!';
                game_over=1 ;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");

            }
           else if(secret_grid[x-1][y-1]==' ')
            {
                grid_shown_to_the_user[x-1][y-1]=' ';
                open_adjacent_empty(x-1,y-1,secret_grid,grid_shown_to_the_user);
            }

            else if(secret_grid[x-1][y-1]<'9')
            {
                grid_shown_to_the_user[x-1][y-1]=secret_grid[x-1][y-1];
            }


        }


        if(grid_shown_to_the_user[x-1][y]=='x' || grid_shown_to_the_user[x-1][y]=='?')//2
        {
            if(secret_grid[x-1][y]=='*')
            {
                grid_shown_to_the_user[x-1][y]='!';
                game_over=1 ;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
            else if(secret_grid[x-1][y]==' ')
            {
                grid_shown_to_the_user[x-1][y]=' ';
                open_adjacent_empty(x-1,y,secret_grid,grid_shown_to_the_user);
            }

            else if(secret_grid[x-1][y]<'9')
            {
                grid_shown_to_the_user[x-1][y]=secret_grid[x-1][y];
            }


        }

        if(grid_shown_to_the_user[x-1][y+1]=='x' || grid_shown_to_the_user[x-1][y+1]=='?')//3
        {
            if(secret_grid[x-1][y+1]=='*')
            {
                grid_shown_to_the_user[x-1][y+1]='!';
                game_over=1 ;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
            else if(secret_grid[x-1][y+1]==' ')
            {
                grid_shown_to_the_user[x-1][y+1]=' ';
                open_adjacent_empty(x-1,y+1,secret_grid,grid_shown_to_the_user);
            }

            else if(secret_grid[x-1][y+1]<'9')
            {
                grid_shown_to_the_user[x-1][y+1]=secret_grid[x-1][y+1];
            }


        }

        if(grid_shown_to_the_user[x][y-1]=='x' || grid_shown_to_the_user[x][y-1]=='?')//4
        {
            if(secret_grid[x][y-1]=='*')
            {
                grid_shown_to_the_user[x][y-1]='!';
                game_over=1;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
            else if(secret_grid[x][y-1]==' ')
            {
                grid_shown_to_the_user[x][y-1]=' ';
                open_adjacent_empty(x,y-1,secret_grid,grid_shown_to_the_user);
            }

            else if(secret_grid[x][y-1]<'9')
            {
                grid_shown_to_the_user[x][y-1]=secret_grid[x][y-1];
            }


        }

        if(grid_shown_to_the_user[x][y+1]=='x' || grid_shown_to_the_user[x][y+1]=='?')//5
        {
            if(secret_grid[x][y+1]=='*')
            {
                grid_shown_to_the_user[x][y+1]='!';


                game_over=1;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
            else if(secret_grid[x][y+1]==' ')
            {
                grid_shown_to_the_user[x][y+1]=' ';
                open_adjacent_empty(x,y+1,secret_grid,grid_shown_to_the_user);
            }

           else if(secret_grid[x][y+1]<'9')
            {
                grid_shown_to_the_user[x][y+1]=secret_grid[x][y+1];
            }


        }

        if(grid_shown_to_the_user[x+1][y-1]=='x' || grid_shown_to_the_user[x+1][y-1]=='?')//6
        {
            if(secret_grid[x+1][y-1]=='*')
            {
                grid_shown_to_the_user[x+1][y-1]='!';


                game_over=1;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
           else if(secret_grid[x+1][y-1]==' ')
            {
                grid_shown_to_the_user[x+1][y-1]=' ';
                open_adjacent_empty(x+1,y-1,secret_grid,grid_shown_to_the_user);
            }

          else  if(secret_grid[x+1][y-1]<'9')
            {
                grid_shown_to_the_user[x+1][y-1]=secret_grid[x+1][y-1];
            }


        }

        if(grid_shown_to_the_user[x+1][y]=='x' || grid_shown_to_the_user[x+1][y]=='?')//7
        {
            if(secret_grid[x+1][y]=='*')
            {
                grid_shown_to_the_user[x+1][y]='!';


                game_over=1;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");
            }
            else if(secret_grid[x+1][y]==' ')
            {
                grid_shown_to_the_user[x+1][y]=' ';
                open_adjacent_empty(x+1,y,secret_grid,grid_shown_to_the_user);
            }

            else if(secret_grid[x+1][y]<'9')
            {
                grid_shown_to_the_user[x+1][y]=secret_grid[x+1][y];
            }


        }
        if(grid_shown_to_the_user[x+1][y+1]=='x' || grid_shown_to_the_user[x+1][y+1]=='?')//8
        {
            if(secret_grid[x+1][y+1]=='*')
            {
                grid_shown_to_the_user[x+1][y+1]='!';
                game_over=1;
                loosing(secret_grid,grid_shown_to_the_user);
                printf(" you lost :P\n");


            }
           else if(secret_grid[x+1][y+1]==' ')
            {
                grid_shown_to_the_user[x+1][y+1]=' ';
                open_adjacent_empty(x+1,y+1,secret_grid,grid_shown_to_the_user);
            }

           else if(secret_grid[x+1][y+1]<'9')
            {
                grid_shown_to_the_user[x+1][y+1]=secret_grid[x+1][y+1];
            }


        }

    }

}


#endif // OPENTWICE_H_INCLUDED
