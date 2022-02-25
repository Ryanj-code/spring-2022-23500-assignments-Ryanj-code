#include <iostream>
#include <unistd.h>
#include <iomanip>

void print_board(int **board, int s){
  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      std::cout << std::setw(2) << board[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";
}

bool solved(int **board, int s){
  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      if(board[i][j] == 0){
	return false;
      }
    }
  }
  
  return true;
}

void solve(int **board, int s, int r, int c, int step){
  if(r < 0 || c < 0 || r >= s || c >= s){
    return;
  }

  if(board[r][c] != 0){
    return;
  }

  if(solved(board, s)){
    return;
  }

  board[r][c] = step;
  
  if(!solved(board, s)) solve(board, s, r - 2, c + 1, step + 1);
  if(!solved(board, s)) solve(board, s, r - 1, c + 2, step + 1);

  if(!solved(board, s)) solve(board, s, r + 2, c - 1, step + 1);
  if(!solved(board, s)) solve(board, s, r + 1, c - 2, step + 1);

  if(!solved(board, s)) solve(board, s, r + 2, c + 1, step + 1);
  if(!solved(board, s)) solve(board, s, r + 1, c + 2, step + 1);

  if(!solved(board, s)) solve(board, s, r - 2, c - 1, step + 1);
  if(!solved(board, s)) solve(board, s, r - 1, c - 2, step + 1);
  
  if(!solved(board, s)) board[r][c] = 0;
}

int main(){
  const int s = 5;
  
  int **board = new int *[s];
  for(int i = 0; i < s; i++){
    board[i] = new int[s];
  } // Dynamically allocates the array.

  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      board[i][j] = 0;
    }
  } // Sets all values in the board to 0.
  
  std::cout << "\n\n";

  print_board(board, s);
  
  solve(board, s, 0, 0, 1);
  
  print_board(board, s);
  
  for(int i = 0; i < s; i++){
    delete[] board [i];
    board[i] = nullptr;
  }
  
  delete[] board;
  board = nullptr;
  
  return 0;
}
