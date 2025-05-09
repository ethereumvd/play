#include<bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {

  vector<int> seg;

  segtree(int n) {
    seg.resize(4*n);
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
    return;

  }

  int query(int l, int r, int seg_l, int seg_r, int idx) {

    if(seg_l >= l && seg_r <= r) return seg[idx];
    if(seg_l > r || seg_r < l) return 0;
    int mid = (seg_l+seg_r)/2;
    return query(l, r, seg_l, mid, 2*idx+1)+query(l, r, mid+1, seg_r, 2*idx+2);

  }

  void update(int pos, int val, int idx, int l , int r) {

    if(l==r) {
      seg[idx] = val;
      return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) update(pos,val,2*idx+1,l,mid);
    else update(pos,val,2*idx+2,mid+1,r);

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    return ;
  }

};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  segtree tree(n);
  tree.build(0, 0, n-1, a);
  for(int i=0; i<q; i++) {
    int t, x, y; cin >> t >> x >> y;
    x--;
    if(t==1) tree.update(x, y, 0, 0, n-1);
    else {
      y--;
      cout << tree.query(x, y, 0, n-1, 0) << "\n" ; 
    }
  }

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
