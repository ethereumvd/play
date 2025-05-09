#include<bits/stdc++.h>
using namespace std;
#define int long long
struct segtree {

  vector<int> seg;

  segtree(int n,vector<int> &a, int idx, int l, int r) {
    seg.resize(4*n);
    build(a,idx,l,r);
  }

  void build(vector<int> &a, int idx, int l, int r) {

    if(l==r) {
      seg[idx] = a[l];
      return;
    }
    int mid = (l+r)/2;
    build(a,2*idx+1,l,mid);
    build(a,2*idx+2,mid+1,r);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    return;

  }

  int query(int l, int r, int seg_l, int seg_h, int idx) {
    
    if(seg_l > r || seg_h < l) return 0;
    if(seg_l >= l && seg_h <= r) return seg[idx];
    int mid = (seg_l+seg_h)/2;
    return (query(l,r,seg_l,mid,2*idx+1)+query(l,r,mid+1,seg_h,2*idx+2));

  }

};
void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  segtree seg(n,a,0,0,n-1);
  for(int i=0; i<q; i++) {
    int l, r; cin >> l >> r;
    l--; r--;
    cout << seg.query(l,r,0,n-1,0) << "\n";
  }

}
int32_t main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
