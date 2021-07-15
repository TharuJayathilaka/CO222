#include <stdio.h>

#define X_MAX   6
#define Y_MAX   6

/* These are called macros, do 'gcc -E maze.c | less' to see how they work
 * They will be replaced before the code is compiled
 */
#define VISITED(x, y)      maze[x][y] = 2;
#define CAN_VISIT(x, y)   (maze[x][y] == 0)

/* MAKE SURE THE MATRIX MATCH X_ AND Y_MAX */
int maze[X_MAX][Y_MAX] = {{0, 0, 0, 0, 0, 1},
			  {1, 1, 1, 1, 0, 0},
			  {0, 0, 0, 0, 0, 0},
			  {0, 1, 1, 1, 1, 1},
			  {0, 0, 0, 0, 1, 1},
			  {1, 1, 1, 0, 0, 0}};


#define X_TARGET   (X_MAX - 1)
#define Y_TARGET   (Y_MAX - 1)
#define X_START    0
#define Y_START    0
/* if you can find a path to given X_TARGET, Y_TARGET then
 * findpath should  return 1.
 * 0 otherwise
 */
int sol[X_MAX][Y_MAX];
int findAndPrint(int x, int y)
{
  if(x == X_TARGET && y == Y_TARGET && CAN_VISIT(x,y)) {
    sol[x][y]=1;//(maze[x][y] == 0)
    return 1; // we came to the point. Should display the path
  }
  //VISITED(x,y); // make the problem small.  //maze[x][y] = 2;
  // remove this and see what will happen
  if(x>=0 && y>=0 && x<X_MAX && y<Y_MAX && sol[x][y]==0 && maze[x][y] ==0 ){
    sol[x][y]=1;  // check safety
    if(findAndPrint(x+1,y)){  // can go down?
        printf("(%d, %d) ",x+1,y);
        return 1;
    }
    if(findAndPrint(x,y+1)){  //can go right?
        printf("(%d, %d) ",x,y+1);
        return 1;
    }
    if(findAndPrint(x-1,y)){  //can go up?
        printf("(%d, %d) ",x-1,y);
        return 1;
    }
    if(findAndPrint(x,y-1)){  //can go left?
        printf("(%d, %d) ",x,y-1);
        return 1;
    }
    sol[x][y]=0;
    return 0;
  }
    return 0;// tried all no path

}
int main()
{
  printf("%s", findAndPrint(0, 0) == 1 ? "\n" : "No path\n");

  // printing the way can get easily.
}
