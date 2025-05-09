#include<bits/stdc++.h>
using namespace std;

void solve() {

  int n, q; cin >> n >> q;
  vector<vector<int>> adj(n,vector<int>());
  for(int i=1; i<=n-1; i++) {
    int p; cin >> p;
    p--;
    adj[p].push_back(i);
  }
  vector<vector<int>> subtr(n,vector<int>());

  auto dfs = [&](int nd, auto&& dfs) -> void {

    subtr[nd].push_back(nd);
    for(auto ch:adj[nd]) {
      dfs(ch,dfs);
      subtr[nd].insert(subtr[nd].end(), subtr[ch].begin(), subtr[ch].end());
    }
    return;

  };
  dfs(0,dfs);

  for(int i=0; i<q; i++) {
    int u, k; cin >> u >> k;
    u--; 
    if(subtr[u].size() < k) cout << -1 << "\n";
    else cout << subtr[u][--k] + 1 << "\n";
  }
 
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  solve();
}
