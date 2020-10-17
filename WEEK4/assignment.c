#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
                    "#     #     ####"
                    "# ####* ### ####"
                    "#    ###### ####"
                    "#### # #### ####"
                    "#    # #### ####"
                    "#### # #### ####"
                    "####        ####"
                    "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];

    for (int i=0; i<HT ; i++) {   // filling the 2D char array
        maze[i]=&mazeStr[i*WD];
    }
    if (solveMaze(maze, HT, WD, 0, 0))
        printMaze(maze, HT, WD);
    else
        printf("No solution\n");

    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int y, int x){
    if (maze[y][x] == '*')
        return 1;
    if (y>=0 && y<HT && x>=0 && x<WD && maze[y][x]==' '){
        maze[y][x] = '.';
        if (y+1<HT && solveMaze(maze, HT, WD, y+1, x) == 1)
            return 1;
        if (x+1<WD && solveMaze(maze, HT, WD, y, x+1) == 1)
            return 1;
        if (y-1>=0 && solveMaze(maze, HT, WD, y-1, x) == 1)
            return 1;
        if (x-1>=0 && solveMaze(maze, HT, WD, y, x-1) == 1)
            return 1;
        maze[y][x] = '#';
            return 0;
    }
    return 0;

    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes
    // pay attention to the bounds of the arrays
    // make sure you don't enter an infinite recursion

}


void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
        for(int j=0; j<WD-1; j++)
          printf("%c",maze[i][j]);
        printf("%c\n",maze[i][WD-1]);
    }
}