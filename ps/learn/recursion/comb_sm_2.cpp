#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void comb_sum(vector<int> &a, int idx, int target, vector<int> &dummy) {

  if(target < 0 || idx >= a.size()) return;
  if(target == 0) {
    ans.push_back(dummy);
    return;
  }

  for(int i=idx; i<a.size(); i++) {

    if(i > idx && a[i] == a[i-1]) continue;

    dummy.push_back(a[i]);
    comb_sum(a, i+1, target-a[i], dummy);
    dummy.pop_back();
  }

}

int main() {
  vector<int> v = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<int> dummy;
  sort(v.begin(),v.end());
  comb_sum(v, 0, target, dummy);
  for(auto &vec:ans) {
    for(auto &i:vec) cout << i << " ";
    cout << "\n";
  }

}
