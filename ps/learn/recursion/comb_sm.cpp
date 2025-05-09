#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void comb_sum(vector<int> &a, int idx, int target , vector<int> &dummy) {

  if(idx >= a.size() || target < 0) return;
  if(target == 0) {
    ans.push_back(dummy);
    return;
  }
  dummy.push_back(a[idx]);
  comb_sum(a, idx, target-a[idx], dummy);
  dummy.pop_back();
  comb_sum(a, idx+1, target, dummy);//very important why target and not target-a[idx+1]

}

int main() {
  vector<int> v = {2,3,5};
  vector<int> dummy;
  int target = 8;
  comb_sum(v, 0, target, dummy) ;
  for(auto &vec:ans) {
    for(auto &i:vec) cout << i << " " ;
    cout << "\n";
  }
}
