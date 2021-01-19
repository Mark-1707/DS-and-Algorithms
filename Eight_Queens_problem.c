/*
Eight-queens Problem
Run the eight-queens program on your computer:
(a)Write the missing Queens methods.
(b)Find out exactly how many board positions are investigated by including a counter that is incremented every time function solve_from is started.
(c)Run the program for the number of queens ranging from 4 to 15. Try to find a mathematical function that approximates the number of positions investigated as a function of the number of queens.
P2. Describe a rectangular maze by indicating its paths and walls within an array. Write a
backtracking program to find a way through the maze.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h> 

int board[8][8]; // you can pick any matrix size you want

int count = 0;

bool isPossible(int n,int row,int col){  // check whether 
                      // placing queen possible or not

// Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
  
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal
  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }
  count++;
  return true;
}
void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        printf(" %d ",board[i][j] );
      }
      printf("\n");
    }
    printf("\n");
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j)){  // if no attack, proceed
      board[row][j] = 1;      // mark row, column with 1
      nQueenHelper(n,row+1);  // call function to continue 
                              // further
    }
    
     board[row][j] = 0;      // unmark to backtrack
  }
  return;

}
void placeNQueens(int n){

  memset(board,0,8*8*sizeof(int)); // allocate 8*8 memory 
                                     // and initialize all 
                                     // cells with zeroes

  nQueenHelper(n,0);     // call the backtracking function 
                         // and print solutions
}

int main(){
    
    int n;
    scanf("%d",&n); // could use a default 8 as well
    
    placeNQueens(n);
    printf("\nBoard positions are investigated : %d \n",count);
    return 0;
}
