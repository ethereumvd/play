#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void subst(int idx, vector<int> &a, vector<int> &dummy) {

  ans.push_back(dummy);
  if(idx > a.size()) return;

  for(int i=idx; i < a.size() ;i++) {

    if(i > idx && a[i] == a[i-1]) continue;
    dummy.push_back(a[i]);
    subst(i+1, a, dummy);
    dummy.pop_back();
  }

}

int main() {
  vector<int> v = {1, 2, 2};
  sort(v.begin(), v.end());
  vector<int> dummy;
  subst(0, v, dummy);
  for(auto &vec:ans) {
    for(auto &ch:vec) cout << ch << " ";
    cout << "\n";
  }
}
