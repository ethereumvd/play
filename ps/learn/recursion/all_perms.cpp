#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void permute(vector<int> &a, vector<bool> &idxs, vector<int> &dummy, int n) {
  if(dummy.size() == n) {
    ans.push_back(dummy);
    return;
  }
  for(int i=0; i<n; i++) {
    if(idxs[i]) continue;

    dummy.push_back(a[i]);
    idxs[i] = true;

    permute(a, idxs, dummy, n);
    
    dummy.pop_back();
    idxs[i] = false;
  }
}

int main() {

  vector<int> v = {1, 2, 3};
  int n = v.size();
  vector<bool> idxs(n,false);
  vector<int> dummy;
  permute(v, idxs, dummy, n);
  for(auto &vec:ans) {
    for(auto &el:vec) cout << el << " ";
    cout << "\n";
  }
}
