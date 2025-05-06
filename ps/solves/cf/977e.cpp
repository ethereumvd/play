#include<bits/stdc++.h>
using namespace std;
void jogo() {
  int n, m ; cin >> n >> m;
  vector<vector<int>> adj(n,vector<int>());
  for(int i=0; i<m; i++) {
    int u,v; cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> vis(n,false);

  auto dfs = [&](int nd, int par, bool flag, auto&& dfs) -> void {
   
    vis[nd] = true;

    for(auto ch:adj[nd]) {
      if(ch==par) continue;
      if(vis[ch]) {
        flag = true;
        continue;
      } 
      dfs(ch,nd,flag,dfs);
    }

    return ;
  };

  int cnt = 0;

  for(int i=0; i<n; i++) {
    if(vis[i]) continue;
    bool flag = false;
    dfs(i,-1,flag,dfs);
    if(flag) cnt++;
  }

  cout << cnt ;

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
