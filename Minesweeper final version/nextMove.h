#ifndef NEXTMOVE_H_INCLUDED
#define NEXTMOVE_H_INCLUDED

void next_move(char secret_grid[X][Y],char grid_shown_to_the_user[X][Y])
{
    int m,n;//counters
    int x,y; // coordinates taken from the user
    i=0;
    char flag_or_question_or_save; // variable to determine the action the user wants to take

    while (game_over==0)
    {
        moves ++; // decrease number of moves
        if(check_if_win(grid_shown_to_the_user,secret_grid,number_of_mines)) // function call to check if the user has won
        {
            printf("well done !\n\n");
            char play= playAgain();
            do
            {
                if(play=='y')
                {
                    moves=0;
                    num_of_questionMarks=0;
                    newGame();

                }
                else if (play=='n')
                {
                    system("cls");
                    printf("\tnever mind come back soon :)\n\n\n");
                    exit(0);
                }
                else
                {
                    system("cls");
                    printf("you did not answer my question\n");
                    play=playAgain();

                }
            }
            while(play != 'y' || play != 'n');

            if (play=='n')
            {
                system("cls");
                system("COLOR 0E");
                printf("\tt\never mind come back soon :)\n\n\n");
                exit (0);
            }


            else
            {
                num_of_questionMarks=0;
                moves=0;
                newGame();

            }
        }
        printf("\nNext move!: Don't forget ((f) for flag/(?) for question mark /(0) to open a cell )\n press 's' if you want to save the game");
        fflush(stdin);
        scanf(" %c",&flag_or_question_or_save);
        if(flag_or_question_or_save=='s')
        {
            // save the game
            FILE*file=fopen("save.txt", "w");
            FILE*fmap=fopen("svaemap.txt","w");
            fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",X,Y,num_of_flags,moves-1,num_of_questionMarks,number_of_mines,timePassed);
            for(m=0; m<X; m++)
            {
                for(n=0; n<Y; n++)
                {
                    fprintf(fmap,"%c",secret_grid[m][n]);
                }
            }
            for(m=0; m<X; m++)
            {
                for(n=0; n<Y; n++)
                {
                    fprintf(fmap,"%c",grid_shown_to_the_user[m][n]);
                }
            }


            fclose(file);
            // end save
            printf("\nsee you later !!\n");
            break;
        }
        else if (flag_or_question_or_save!= 'f' &&flag_or_question_or_save!='0'&&flag_or_question_or_save!='?')
        {
            // if wrong input print warning message to the user
            moves--;
            print_grid_to_the_user(grid_shown_to_the_user);
            printf("you can not do that \nyou'd better play with my rules :P\n ");

            continue ;
        }
        else
        {
            // take coordinates from the user
            printf("enter x coordinate : ");
            fflush(stdin);

            // to make sure it only takes int no characters
            while (scanf("%d",&x)!=1)
            {
                print_grid_to_the_user(grid_shown_to_the_user);
                printf("no that is not a valid coordinate enter a number \n enter x coordinate : ");
                while(getchar() != '\n');
            }

            printf("enter y coordinate : ");
            fflush(stdin);
            while (scanf("%d",&y)!=1)
            {
                print_grid_to_the_user(grid_shown_to_the_user);
                printf("no that is not a valid coordinate enter a number \n enter y coordinate : ");
                while(getchar() != '\n');
            }


        }

        if(in_range(x,X)&& in_range(y,Y))
        {
            // mark a cell with a flag
            if( flag_or_question_or_save=='f')
            {
                // if marked already remove the flag and increase number of flags allowed
                if(grid_shown_to_the_user[x][y]=='F')
                {
                    grid_shown_to_the_user[x][y]='x';
                    num_of_flags++;

                    print_grid_to_the_user(grid_shown_to_the_user);

                }
                //if not marked flag it and decrease number of flags allowed
                else if(grid_shown_to_the_user[x][y]=='x'||grid_shown_to_the_user[x][y]=='?')
                {
                    if(grid_shown_to_the_user[x][y]=='?')
                    {
                        num_of_questionMarks--;
                    }
                    grid_shown_to_the_user[x][y]='F';
                    num_of_flags--;


                    print_grid_to_the_user(grid_shown_to_the_user);//mazen add it to reduce number of queries if there

                }
                else
                {
                    moves--;
                    print_grid_to_the_user(grid_shown_to_the_user);
                    printf("you can not do that you'd better play with my rules :P \n");



                }
                continue ;

            }
            // mark a cell with ?
            else if( flag_or_question_or_save=='?')
            {
                // if marked already remove the ? and decrease number of ?
                if(grid_shown_to_the_user[x][y]=='?')
                {
                    num_of_questionMarks--;
                    grid_shown_to_the_user[x][y]='x';
                    print_grid_to_the_user(grid_shown_to_the_user);
                }
                //if not marked put ? on it and increase number of ?
                else if(grid_shown_to_the_user[x][y]=='x')
                {
                    grid_shown_to_the_user[x][y]='?';
                    num_of_questionMarks++;
                    print_grid_to_the_user(grid_shown_to_the_user);
                }
                else
                {
                    moves--;
                    print_grid_to_the_user(grid_shown_to_the_user);
                    printf("you'd better play with my rules :p \n");
                }
                continue ;
            }
            // to open a cell
            else if( flag_or_question_or_save=='0'&&grid_shown_to_the_user[x][y]!='F')
            {
                if(grid_shown_to_the_user[x][y]=='?')
                {
                    num_of_questionMarks--;
                }
                // if the cell has a mine
                if(secret_grid[x][y]=='*')
                {
                    system("COLOR 0C");
                    grid_shown_to_the_user[x][y]='!';
                    game_over =1 ;
                    loosing(secret_grid,grid_shown_to_the_user);// function call in case of loosing the game
                    printf(" you lost :P\n");
                    char play = playAgain();
                    do
                    {
                        if(play=='y')
                        {
                            game_over=0;
                            num_of_questionMarks=0;
                            moves=0;
                            newGame();

                        }
                        else if (play=='n')
                        {
                            system("cls");
                            printf("\tnever mind come back soon :)\n\n\n");
                            exit(0);
                        }
                        else
                        {
                            system("cls");
                            printf("you did not answer my question\n");
                            play=playAgain();

                        }
                    }
                    while(play != 'y' || play != 'n');

                    if (play=='n')
                    {
                        system("cls");
                        system("COLOR 0E");
                        printf("\tt\never mind come back soon :)\n\n\n");
                        exit (0);
                    }


                    else
                    {
                        game_over=0;
                        moves=0;
                        num_of_questionMarks=0;
                        newGame();

                    }


                }
                // if the cell has a number
                else if(secret_grid[x][y]<'9'&& secret_grid[x][y]!=' ')
                {
                    // check if it was opened already
                    if(!check_open_twice(x,y,grid_shown_to_the_user))
                    {
                        grid_shown_to_the_user[x][y]=secret_grid[x][y];
                        print_grid_to_the_user(grid_shown_to_the_user);
                    }
                    else
                    {
                        open_twice(x,y,grid_shown_to_the_user,secret_grid);
                        // function call to handle the case if the cell was opened already
                        if(!game_over) print_grid_to_the_user(grid_shown_to_the_user);
                    }
                }
                else if (secret_grid[x][y]==' ')
                {

                    grid_shown_to_the_user[x][y]=' ';
                    open_adjacent_empty(x,y,secret_grid,grid_shown_to_the_user);
                    print_grid_to_the_user(grid_shown_to_the_user);
                }



            }
            else
            {
                moves--;
                print_grid_to_the_user(grid_shown_to_the_user);
                printf("you can not do that \nyou'd better play with my rules :P \n");
                continue ;
            }

        }
        else
        {
            moves--;
            print_grid_to_the_user(grid_shown_to_the_user);
            printf("you can not do that \nyou'd better play with my rules :P\n ");
        }

    }


}



#endif // NEXTMOVE_H_INCLUDED
