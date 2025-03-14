#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void jogo() {
    int n, m; cin >> n >> m ;
    vector<vector<int>> adj(n);
    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector<int> topo;
    vector<bool> vis(n,false);
    function<void(int)> dfst =  [&] (int nd) {
        vis[nd] = true;
        for(auto nx:adj[nd]) {
            if(!vis[nx]) { //fking piece of shit this is
                //try to think why this check is important
                dfst(nx);
            }
        }
        topo.push_back(nd);
        return;
    };
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfst(i);
        }
    }

    
    vector<int> dp(n,0);
    vis.assign(n,false);
    dp[0] = 1; //src 

    reverse(topo.begin(),topo.end());

    for(auto nd:topo) {
        for(auto nx:adj[nd]) {
            dp[nx] = (dp[nd] + dp[nx])%mod;
        }
    }

    cout << dp[n-1] << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
