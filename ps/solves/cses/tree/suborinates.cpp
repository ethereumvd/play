#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
  int n; cin >> n;
  vector<vector<int>> adj(n,vector<int>());
  for(int i=1; i<n; i++) {
    int par; cin >> par;
    par--;
    adj[par].push_back(i);
  }

  vector<int> sub(n,0);
  auto dfs = [&](int nd, auto&& dfs) -> void {

    for(auto &ch:adj[nd]) {
      dfs(ch,dfs);
      sub[nd] += sub[ch];
    }

    sub[nd] += 1;
    return;

  };

  dfs(0,dfs);
  for(int i=0; i<n; i++) cout << sub[i]-1 << " ";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
