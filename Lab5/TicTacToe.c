/*
          CO222-2019 Lab05
          Author: E16156

          TicTacToe game
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
//int SIZE;
void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int a[SIZE][SIZE]);


int main(){
    /*printf("Enter the size:");
    scanf("%d",&SIZE);*/
    int inBoard[SIZE][SIZE]; //declaring an array
    printf("Please enter the board:\n");
    scanBoard(inBoard); //scanBoard
    printf("Here is the board:\n");
    printBoard(inBoard);//printBoard

    //printing the result
    if(getWinner(inBoard)==0)
        printf("Noughts win\n");
    else if(getWinner(inBoard)==1)
        printf("Crosses win\n");
    else
        printf("There are no winners\n");
return 0;
}
//scan function
void scanBoard(int a[SIZE][SIZE]){// check if the input is 0|| 1 || 2
    int i,j;//get the relevant element
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<SIZE;i++){ // else give the
        for(j=0;j<SIZE;j++){
             if((a[i][j]==0)||(a[i][j]==1)||(a[i][j]==2)){
             }else{
                printf("Enter valid input.\n");// inputs should be 0,1 or 2
                exit(0);//else give error message and terminate the program
            }
        }
    }
}
//print function
void printBoard(int b[SIZE][SIZE]){
    int i,j;//printing board
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
               if(b[i][j]==1){
                   printf("X ");//for 1
               }else if(b[i][j]==2){
                   printf(". ");//for 2
               }else{
                   printf("O ");//for 0
               }
        }
        printf("\n");
    }
}

//find the winner of the game
//assume both two players can't win the game at the same time.
//It can't happen in a real game
int getWinner(int  a[SIZE][SIZE]){
    int i,j;
    int winner=2,sumI,sumJ,sumD,sumT;
    //if winner is naughts, winner=0
    //if winner is crosses, winner=1
    //if there is no winner, winner=2
    for(i=0;i<SIZE;i++){// if one row has same number
           sumI=0;
           for(j=0;j<SIZE;j++){
               if((a[i][0])!=(a[i][j])){
                   break;
               }else{
                   sumI++;
                   if(sumI==SIZE){
                        winner=a[i][j];
                   }
               }
           }
    }
    for(j=0;j<SIZE;j++){// if one column has same number
           sumJ=0;
           for(i=0;i<SIZE;i++){
               if((a[0][j])!=(a[i][j])){
                   break;
               }else{
                   sumJ++;
                   if(sumJ==SIZE){
                        winner=a[i][j];
                   }
               }
           }
    }
    sumD=0;
    for(i=0;i<SIZE;i++){//if diagonal has same number
            if(a[0][0]!=a[i][i]){
                break;
            }else{
                sumD++;
                if(sumD==SIZE){
                    winner=a[0][0];
                }
            }
    }

    sumT=0;
    for(i=0;i<SIZE;i++){//if diagonal has same number
        if(a[0][SIZE-1]!=a[i][SIZE-1-i]){
            break;
        }else{
            sumT++;
            if(sumT==SIZE){
                winner=a[0][SIZE-1];
            }
        }
    }
return winner;// return the winner to the main function
}
