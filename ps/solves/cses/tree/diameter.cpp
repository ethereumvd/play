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

    int mx_lev = 0;
    int mx_lev_nd = -1;
    auto dfs = [&] (int nd, int par, int lev, auto&& dfs) -> void {
        mx_lev = max(lev, mx_lev);
        if(lev >= mx_lev) mx_lev_nd = nd;

        for(auto &ch:adj[nd]) {
            if(ch == par) continue;
            dfs(ch, nd, lev+1, dfs);
        }
        return;
    };

    dfs(0, -1, 0, dfs);
    mx_lev = 0;

    dfs(mx_lev_nd, -1, 0, dfs);
    int ans = mx_lev;

    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
