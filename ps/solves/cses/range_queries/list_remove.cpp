#include<bits/stdc++.h>
using namespace std;

struct segtree {

  vector<int> seg;

  segtree(int n, vector<int> &a) {
    seg.resize(4*n);
  }

  void build(int idx, int l, int r, vector<int> &a) {

    if(l == r) {
      seg[idx] = a[l];
      return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid, a);
    build(2*idx+2, mid+1, r, a);

  }

};

void solve() {
  int n; cin >> n; 
  vector<int> x(n), p(n), elim(n,1);
  for(int &i:x) cin >> i;
  for(int &i:p) cin >> i;

  
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
