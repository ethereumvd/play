#include<bits/stdc++.h>
using namespace std;
//such an idiot bro, no need of 2d segment tree array 
struct segtree {

  vector<vector<int>> seg;
  vector<int> lazy;

  segtree(int n, vector<int> &a) {
    seg.resize(4*n,vector<int>(2,0));
    lazy.resize(4*n,0);
    build(0, 0, n-1, a);
  }

  void build(int idx, int l, int r, vector<int> &a) {

    if(l == r) {
      seg[idx][0] = a[l];
      seg[idx][1] = l;
      return;
    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid, a);
    build(2*idx+2, mid+1, r, a);
    seg[idx][0] = max(seg[2*idx+1][0], seg[2*idx+2][0]);
    if(seg[2*idx+1][0] >= seg[2*idx+1][0]) seg[idx][1] = seg[2*idx+1][1];
    else seg[idx][1] = seg[2*idx+2][1];

  }

  int query(int val, int n) {
    return query(val, 0, n-1, 0);

  }

  int query(int val, int l, int r, int idx) {

    if(seg[idx][0] < val) {
      return -1;
    } 
    if(l == r) {
      if(seg[idx][0] >= val) return seg[idx][1];
      return -1;
    }

    int mid = (l+r)/2;
    int left = query(val, l, mid, 2*idx+1);
    if(left != -1) return left;
    int right = query(val, mid+1, r, 2*idx+2);
    return right;

  }

  void update(int val, int pos, int l, int r, int idx) {

    if(l==r) {
      seg[idx][0] -= val;
      return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) update(val, pos, l, mid, 2*idx+1);
    else update(val, pos, mid+1, r, 2*idx+2);
    seg[idx][0] = max(seg[2*idx+1][0],seg[2*idx+2][0]);

  }

  void update(int val, int pos, int n) {
    update(val, pos, 0, n-1, 0);
  }

};

void solve() {

  int n, m; cin >> n >> m;
  vector<int> h(n), r(m);
  for(int &i:h) cin >> i;
  for(int &i:r) cin >> i;

  segtree tree(n,h);

  for(int i=0; i<m; i++) {

    int idx = tree.query(r[i], n);
    if(idx == -1) cout << 0 << " ";
    else {
      cout << idx + 1 << " ";
      tree.update(r[i], idx, n);
    }

  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
