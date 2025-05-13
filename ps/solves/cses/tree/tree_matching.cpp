#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n; 
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int rt = 0;
    vector<int> dp1(n,0), dp2(n,0);
    
    auto dfs = [&](int nd, int par, auto&& dfs) -> void {

        for(auto &ch:adj[nd]) {
            if(ch == par) continue;
            dfs(ch, nd, dfs);
            dp1[nd] += max(dp1[ch] , dp2[ch]);
        }
        for(auto &ch:adj[nd]) {
            if(ch == par) continue;
            dp2[nd] = max(dp2[nd], dp1[ch] + 1 + dp1[nd] - max(dp1[ch],dp2[ch]));
        }

        return;
    };
    dfs(0, -1, dfs);
    int ans = max(dp1[rt], dp2[rt]);

    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
