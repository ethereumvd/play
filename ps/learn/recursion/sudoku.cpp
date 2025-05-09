#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> board = {
{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'} };

bool isvalid(vector<vector<char>> &board,char c, int row, int col) {
  for(int i=0; i<9; i++) {

    if(board[row][i] == c ||
       board[i][col] == c ||
       board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;

  }
  return true;
}

bool solve(vector<vector<char>> &board) {

  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      if(board[i][j]!='.') continue;
      for(char c = '1'; c <= '9'; c++) {
        if(isvalid(board,c, i, j)) {
          board[i][j] = c;
          if(solve(board)) return true;
          board[i][j] = '.';
        }
      }
      return false;
    }
  }
  return true;

}

int main() {

  if(solve(board)){
    for(auto &vec:board) {
    for(auto &ch:vec) cout << ch << " ";
    cout << "\n";
    }
  }

}
