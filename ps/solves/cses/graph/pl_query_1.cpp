#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
  int n, q; cin >> n >> q;
  vector<pair<int,int>> qr(q);
  vector<int> t(n);
  for(int i=0; i<n; i++) {
    cin >> t[i];
    t[i]--;
  }
  for(int i=0; i<q; i++) {
    int x, k; cin >> x >> k;
    qr[i] = {x,k};
  }
  int log_mx = log2(n) + 1;
  vector<vector<int>> anc(n,vector<int>(log_mx));

  for(int i=0; i<n; i++) {
    anc[i][0] = t[i];
  }

  for(int j=0; j<log_mx-1; j++) {
    for(int i=0; i<n; i++) {
      anc[i][j+1] = anc[anc[i][j]][j];
    }
  }

  for(auto p:qr) {
    int nd = p.first - 1;
    int kk = p.second;
    int ans = nd;
    for(int i=0; i<log_mx; i++) {
      if((kk & (1<<i)) == 0) continue; 
      ans = anc[ans][i];
    }
    cout << ans + 1 << "\n";
  }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
