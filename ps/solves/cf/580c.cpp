#include<bits/stdc++.h>
using namespace std;
void jogo() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  vector<int> cats(n,0);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i]==1) cats[i]++;
  }
  vector<vector<int>> adj(n,vector<int>());
  for(int i=0; i<n-1; i++) {
    int x, y; cin >> x >> y;
    --x; --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  int rt = 0;
  map<int,bool> leaves;
  auto dfs = [&](int nd, int par, auto&& dfs) -> void {

    for(auto &ch:adj[nd]) {
      if(ch==par) continue;
      if(cats[ch] != 0) cats[ch] += cats[nd];
      dfs(ch,nd,dfs);
    }

    if(adj[nd].size()==1 && nd!=rt) leaves[nd] = false;
    return;
  };
  
  auto dfs2 = [&](int nd, int par, auto&& dfs2) -> void {
   
    if(cats[nd] > m) return;
    for(auto &ch:adj[nd]) {
      if(ch==par) continue;
      dfs2(ch,nd,dfs2);
    }

    if(adj[nd].size()==1 && nd!=rt) leaves[nd] = true;
    return ;
  };
  dfs(0,0,dfs);
  dfs2(0,0,dfs2);

  int cnt = 0;
  for(auto it:leaves) if(it.second == true) cnt++;
  cout << cnt << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
