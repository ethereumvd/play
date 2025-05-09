#include<bits/stdc++.h>
using namespace std;
#define int long long 

struct segtree {

  vector<int> seg;
  vector<int> lazy;

  segtree(int n, vector<int> &a) {
    seg.resize(4*n);
    lazy.resize(4*n,0);
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
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];

  }

  int query(int pos, int idx, int l, int r) {

    propagate(idx, l, r);
    if(l==r) return seg[idx] ;
    int mid = (l+r)/2;
    if(pos <= mid) return query(pos, 2*idx+1, l, mid);
    return query(pos, 2*idx+2, mid+1, r);
    
  }

  void propagate(int idx, int l, int r) {

    if(lazy[idx]!=0) {

      int n_el = r - l + 1;
      seg[idx] += (lazy[idx] * n_el);
      if(r != l) {
        lazy[2*idx+1] += lazy[idx];
        lazy[2*idx+2] += lazy[idx];
      }
      
      lazy[idx] = 0;
    }

  }

  void range_update(int rl, int rr, int val, int l, int r, int idx) {

    propagate(idx, l, r);
    if(l > rr || r < rl) return;
    if(l >= rl && r <= rr) {
      lazy[idx] += val;
      propagate(idx, l, r);
      return;
    }
    int mid = (l+r)/2;
    range_update(rl, rr, val, l, mid, 2*idx+1);
    range_update(rl, rr, val, mid+1, r, 2*idx+2);
    return;
  }

};

void solve() {

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int &i:a) cin >> i;

  segtree tree(n,a);

  for(int i=0; i<q; i++) {
    int ty ; cin >> ty;
    if(ty == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      a--; b--;
      tree.range_update(a, b, u, 0, n-1, 0);
    }
    else {
      int pos ; cin >> pos; 
      pos--;
      cout << tree.query(pos, 0, 0, n-1) << "\n" ;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
