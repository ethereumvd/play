#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> ans;

bool k_perm(vector<int> &a, vector<bool> &taken, vector<int> &dummy, int k) {

  if(dummy.size()==a.size()) {
    cnt++;
    if(cnt == k) {
      ans = dummy;
      return true;
    }
    return false;
  }
  for(int i=0; i<a.size(); i++) {
    if(taken[i]) continue;
    dummy.push_back(a[i]);
    taken[i] = true;
    if(k_perm(a, taken, dummy, k)) return true;
    dummy.pop_back();
    taken[i] = false;
  }
  return false;
}

int main() {
  int n = 9;
  vector<int> v(n);
  iota(v.begin(),v.end(),1);
  int k = 18;
  vector<bool> taken(n, false);
  vector<int> dummy;
  if(k_perm(v, taken, dummy, k)) {
    for(auto &i:ans) cout << i << " ";
  }
}
