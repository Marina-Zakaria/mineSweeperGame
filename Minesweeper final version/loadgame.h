#ifndef LOADGAME_H_INCLUDED
#define LOADGAME_H_INCLUDED
void loadgame (){
        system("COLOR F9");
        int m,n;
        number_of_mines = 1+(X*Y)/10;
        FILE*file=fopen("save.txt","r");
        FILE*fmap=fopen("svaemap.txt","r");
        fscanf(file,"%d",&X);
        fscanf(file,"%d",&Y);
        fscanf(file,"%d",&num_of_flags);
        fscanf(file,"%d",&moves);
        fscanf(file,"%d",&num_of_questionMarks);
        fscanf(file,"%d",&number_of_mines);
        fscanf(file,"%d",&timePassed);
        savedTime=timePassed;
        char grid_shown_to_the_user[X][Y];
        char secret_grid[X][Y];
        char c;
        for(m=0; m<X; m++){
            for(n=0; n<Y; n++){
                c=fgetc(fmap);
                secret_grid[m][n]=c;
        }
        }
        for(m=0; m<X; m++){
            for(n=0; n<Y; n++){
                c=fgetc(fmap);
                grid_shown_to_the_user[m][n]=c;
        }
        }
        print_grid_to_the_user(grid_shown_to_the_user);
        fclose(file);
        fclose(fmap);
        next_move(secret_grid,grid_shown_to_the_user);

}

#endif // LOADGAME_H_INCLUDED
