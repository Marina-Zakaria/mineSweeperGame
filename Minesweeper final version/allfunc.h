#ifndef ALLFUNC_H_INCLUDED
#define ALLFUNC_H_INCLUDED

int X,Y,i,j,num_of_questionMarks=0,game_over=0,timePassed=0,moves=0,newTime=0;
char startGame='\0';
int savedTime=0;
int number_of_players=0;
void take_coordinates(int *X,int *Y);
void   initialize_grid(char grid_shown_to_the_user[X][Y],char secret_grid[X][Y]);
void   print_grid_to_the_user(char grid_shown_to_the_user[X][Y]);
void take_first_move (int n,int minesX[n],int minesY[n],char secret_grid[X][Y],char grid_shown_to_the_user[X][Y]);
int found_pair(int x,int n,int array1[n],int y,int array2[n]);
void open_adjacent_empty(int i,int j,char secret_grid[X][Y],char grid_shown_to_the_user[X][Y]);
int in_range (int x,int n);
void next_move(char secret_grid[X][Y],char grid_shown_to_the_user[X][Y]);
int number_of_mines,num_of_flags;
void open_adjacent_empty(int i,int j,char secret_grid[X][Y],char grid_shown_to_the_user[X][Y]);
int check_if_win(char grid_shown_to_the_user[X][Y],char secret_grid[X][Y],int number_of_mines);
void open_twice(int x, int y,char grid_shown_to_the_user[X][Y],char secret_grid[X][Y]);
int check_open_twice(int x, int y,char grid_shown_to_the_user[X][Y]);
void loosing(char secret_grid[X][Y],char grid_shown_to_the_user[X][Y]);
void loadgame();
int creat_leaderBoard(char champ [],int score );
int sort_scores (int index,int arr[]);
char playAgain(); void newGame();


#endif // ALLFUNC_H_INCLUDED
