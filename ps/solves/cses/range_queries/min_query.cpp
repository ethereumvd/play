#include<bits/stdc++.h>
using namespace std;
struct segtree {

  vector<int> seg;
  
  segtree(int n) {
    seg.resize(4*n);
  }

  void build(vector<int> &a, int idx, int l, int r) {

    if(l==r) {
      seg[idx] = a[l];
      return;
    }
    int mid = (l+r)/2;
    build(a,2*idx+1,l,mid);
    build(a,2*idx+2,mid+1,r);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    return;
  }

  int query(int l,int r, int idx, int lidx, int hidx) {

    if(hidx < l || lidx > r) return INT_MAX;
    if(lidx >=l  && hidx <= r) return seg[idx]; 
    int mid = (lidx+hidx)/2;
    return min(query(l,r,2*idx+1,lidx,mid),query(l,r,2*idx+2,mid+1,hidx));

  }


};

void solve() {

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  segtree seg(n);
  seg.build(a,0,0,n-1);

  for(int i=0; i<q; i++)  {
    int l, r; cin >> l >> r;
    l--;r--;
    cout << seg.query(l, r, 0, 0, n-1) << "\n"; 
  }

}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
