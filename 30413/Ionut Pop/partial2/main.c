#include <stdio.h>
#include <stdlib.h>

int n, m;
int nr_of_paths;


void backtracking(int x, int y){
    if (x==n-1 && y==m-1)
        ++nr_of_paths;
    if(x>=0 && x<n && y>=0 && y<m){
        backtracking(x, y+1);   //go east
        backtracking(x+1, y);   //go south
        backtracking(x+1, y+1); //go south-east
        }
}


int main()
{
    scanf("%d%d", &n, &m);

    //going from the bottom left to top right has the same number of paths
    //as going from top left to bottom right (the matrix is reversed)
    //=> we go from (0, 0) to (n-1, m-1)
    //=> the new directions are are south, east and south-east

    backtracking(0, 0);

    printf("nr of paths = %d", nr_of_paths);

    return 0;
}
