#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define endl cout<<"\n"
int board[11][11];

bool ispossibleposition(int n,int row,int col){
    // case -1 lie in the same column
    for(int i=row-1; i>=0; i--){
        if(board[i][col]==1) return false;
    }
    // case - upper left diagonal
    for(int i=row-1,j=col-1; i>=0 and j>=0; i--,j--){
        if(board[i][j]==1) return false;
    }
    // case-3 upper right diagonal 
    for(int i=row-1,j=col+1; i>=0 and j<n; i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

void placenqueenhelper(int n,int row){
    if(n==row){
        // we have reached some solution 
        // print the solution and just return
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
        }
        endl;
        return;
    }
    // place n queen at all the possible position and move to the smaller problem
    for(int j=0; j<n; j++){
        if(ispossibleposition(n,row,j)){
            board[row][j]=1;
            placenqueenhelper(n,row+1);
            // mark the board with 0 again for the backtracking
            board[row][j]=0;
        }
    }
    return;
}
void placenqueen(int n){
   // using memset initialise it with 0
   memset(board,0,11*11*sizeof(int));

   // calling nqueen helper function and passing the n and oth row
   placenqueenhelper(n,0);
}

int32_t main(){
    int n; cin>>n;
    placenqueen(n);
    return 0;
}







/*

solution -2
#include <bits/stdc++.h>
using namespace std;

void nQueenHelper(int current_row, int n, int **chessBoard, int *up,
                  int *left_diagonal, int *right_diagonal) {
  if (current_row == n) {
    // We have reached some solution
    // Print the board
    // Return
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << chessBoard[i][j] << " ";
      }
    }
    cout << endl;
    return;
  }

  // Place at all possible positions and move to smaller problem
  for (int j = 0; j < n; j++) {
    if (up[j] != 1 && right_diagonal[current_row + j] != 1 &&
        left_diagonal[n - 1 + current_row - j] != 1) {
      chessBoard[current_row][j] = 1;
      up[j] = 1;
      right_diagonal[current_row + j] = 1;
      left_diagonal[n - 1 + current_row - j] = 1;
      nQueenHelper(current_row + 1, n, chessBoard, up, left_diagonal,
                   right_diagonal);
      chessBoard[current_row][j] = 0;
      up[j] = 0;
      right_diagonal[current_row + j] = 0;
      left_diagonal[n - 1 + current_row - j] = 0;
    }
  }
}

void nQueen(int n) {
  int **chessBoard = new int *[n];
  for (int i = 0; i < n; i++) {
    chessBoard[i] = new int[n];
    for (int j = 0; j < n; j++) {
      chessBoard[i][j] = 0;
    }
  }
  int *up = new int[n - 1];
  memset(up, 0, n - 1);
  int *left_diagonal = new int[(2 * n) - 1];
  memset(left_diagonal, 0, (2 * n) - 1);
  int *right_diagonal = new int[(2 * n) - 1];
  memset(right_diagonal, 0, (2 * n) - 1);
  nQueenHelper(0, n, chessBoard, up, left_diagonal, right_diagonal);
  for (int i = 0; i < n; i++) {
    delete[] chessBoard[i];
  }
  delete[] chessBoard;
  up = nullptr;
  left_diagonal = nullptr;
  right_diagonal = nullptr;
  delete[] up;
  delete[] left_diagonal;
  delete[] right_diagonal;
}

int main() {
  int n;
  cin >> n;
  nQueen(n);
  return 0;
}

*/