#include<bits/stdc++.h>
using namespace std;

int n = 9;
vector<vector<char>> board(n,vector<char>(n,'.'));
vector<vector<vector<char>>> ans;

bool issafe(set<int> cols, set<int> pdia, set<int> ndia, int row, int col) {
    if(cols.find(col)!=cols.end() ||
       pdia.find(row+col)!=pdia.end() ||
       ndia.find(row-col)!=ndia.end()) {
      return false;
    }
  return true;

}

void nqueens(int row, set<int> cols, set<int> pdia, set<int> ndia) {

  for(int col=0; col < n; col++) {

    if(issafe(cols, pdia, ndia, row, col)) {

      cols.insert(col);
      pdia.insert(row+col);
      ndia.insert(row-col);
      board[row][col] = 'Q';

      nqueens(row+1, cols, pdia, ndia);

      cols.erase(col);
      pdia.erase(row+col);
      ndia.erase(row-col);
      board[row][col] = '.';
    } 
    else {
      continue;
    }
  }
  if(row == n-1) {
    ans.push_back(board);
    return;
  }

}


int main() {
  set<int> cols, ndia, pdia;
  nqueens(0, cols, pdia, ndia);

  for(auto &an:ans) {
    for(auto &row:an) {
      for(auto &ch:row){
        cout << ch << " " ;
      } 
      cout << "\n";
    }
    cout << "--------" << "\n";
  }

}
