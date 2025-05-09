#include<bits/stdc++.h>
using namespace std;

struct segtree {

  vector<int> seg;

  segtree(int n, vector<int> &a) {
    seg.resize(4*n);
    build(0, 0, n-1, a);
  }

  void build(int idx, int l, int r, vector<int> &a) {

    if(l==r) {
      seg[idx] = a[l];
      return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid, a);
    build(2*idx+2, mid+1, r, a);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);

  }

  void point_update(int pos, int val, int l, int r, int idx) {

    if(l==r) {
      seg[idx] = val;
      return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) point_update(pos, val, l, mid, 2*idx+1);
    if(pos > mid) point_update(pos, val, mid+1, r, 2*idx+2);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);

  }

  int query(int rl, int rr, int l, int r, int idx) {

    if(l > rr || r < rl) return INT_MAX;
    if(l >= rl && r <= rr) return seg[idx];
    int mid = (l+r)/2;
    int left = query(rl, rr, l, mid, 2*idx+1);
    int right = query(rl, rr, mid+1, r, 2*idx+2);
    return min(left, right);

  }

};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &i:a) cin >> i;
  segtree tree(n,a);

  for(int i=0; i<q; i++) {
    int t, x, y; cin >> t >> x >> y;
    x--;
    if(t==1) {
      tree.point_update(x, y, 0, n-1, 0);
    }
    else {
      y--;
      cout << tree.query(x, y, 0, n-1, 0) << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
