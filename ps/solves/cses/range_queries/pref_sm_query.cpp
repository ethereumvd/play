#include<bits/stdc++.h>
using namespace std;
#define int long long 
//each nd of segtree stores the max pref summ 
//and the total sm of range its responsible for

struct segtree {

  vector<vector<int>> seg;

  segtree(int n, vector<int> &a) {
    seg.resize(4*n,vector<int>(2));
    build(0, 0, n-1, a);
  }

  void build(int idx, int l, int r, vector<int> &a) {
    if(l == r) {
      seg[idx][0] = a[l];
      seg[idx][1] = a[l];
      return;

    }
    int mid = (l+r)/2;
    build(2*idx+1, l, mid, a);
    build(2*idx+2, mid+1, r, a);
    seg[idx][0] = seg[2*idx+1][0] + seg[2*idx+2][0];
    seg[idx][1] = max(seg[2*idx+1][1], seg[2*idx+1][0] + seg[2*idx+2][1]);
  }

  void update(int pos, int val, int l, int r, int idx) {

    if(l==r) {
      seg[idx][0] = val;
      seg[idx][1] = val;
      return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) update(pos, val, l, mid, 2*idx+1);
    else update(pos, val, mid+1, r, 2*idx+2);
    seg[idx][0] = seg[2*idx+1][0] + seg[2*idx+2][0];
    seg[idx][1] = max(seg[2*idx+1][1], seg[2*idx+1][0] + seg[2*idx+2][1]);
    
  }

  void update(int pos, int val, int n) {
    update(pos, val, 0, n-1, 0);
  }

  vector<int> query(int rl, int rr, int l, int r, int idx) {

    if(r < rl || l > rr) return {0, 0};
    // if(r < rl || l > rr) return {0, INT_MIN};
    // W O W !!
    if(l >= rl && r <= rr) {
      return seg[idx];
    }
    int mid = (l+r)/2;
    vector<int> left = query(rl, rr, l, mid, 2*idx+1);
    vector<int> right = query(rl, rr, mid+1, r, 2*idx+2);

    int sm = left[0] + right[0];
    int pref = max(left[1], left[0] + right[1]);
    return {sm, pref};
  }

  int query(int rl, int rr, int n) {
    vector<int> ans = query(rl, rr, 0, n-1, 0);
    return max(ans[0], ans[1]);
  }
};

void solve() {

  int n, q; cin >> n >> q;
  vector<int> x(n);
  for(int &i:x) cin >> i;
  
  segtree tree(n,x);

  for(int i=0; i<q; i++) {
    int ty; cin >> ty;
    if(ty == 1) {
      int pos, val ; cin >> pos >> val ;
      pos--;
      tree.update(pos, val, n);
    }
    else {
      int rl, rr; cin >> rl >> rr;
      rl--; rr--;
      //god knows how it will work
      int ans = tree.query(rl, rr, n);
      if(ans == -1) ans++;
      cout << ans << "\n";
    }

  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
