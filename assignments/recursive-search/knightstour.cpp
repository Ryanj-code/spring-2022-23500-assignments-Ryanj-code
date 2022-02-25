#include <iostream>
#include <unistd.h>
#include <iomanip>

// Prints the board with setw(2) to format the print.
void print_board(int **board, int s){
  for(int i = 0; i < s; i++){
    for(int j = 0; j < s; j++){
      std::cout << std::setw(2) << board[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";
}

// Checks if there are any 0s left in the array, if there is return false, if not, return true.
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

// Solves the board by recursively checking the moves for a knight.
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

  // Checks all directions the knight can go.
  if(!solved(board, s)) solve(board, s, r - 2, c + 1, step + 1);
  if(!solved(board, s)) solve(board, s, r - 1, c + 2, step + 1);

  if(!solved(board, s)) solve(board, s, r + 2, c - 1, step + 1);
  if(!solved(board, s)) solve(board, s, r + 1, c - 2, step + 1);

  if(!solved(board, s)) solve(board, s, r + 2, c + 1, step + 1);
  if(!solved(board, s)) solve(board, s, r + 1, c + 2, step + 1);

  if(!solved(board, s)) solve(board, s, r - 2, c - 1, step + 1);
  if(!solved(board, s)) solve(board, s, r - 1, c - 2, step + 1);
  
  // Sets the tile back to 0.
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
  
  std::cout << "\nChecks if the values of the board is set to 0.\n";
  print_board(board, s);
  
  // Calls solve and prints the solved board.
  solve(board, s, 0, 0, 1);
  std::cout << "Solved Board:\n";
  print_board(board, s);

  // Deletes the memory.
  for(int i = 0; i < s; i++){
    delete[] board [i];
    board[i] = nullptr;
  }
  
  delete[] board;
  board = nullptr;
  
  return 0;
}
