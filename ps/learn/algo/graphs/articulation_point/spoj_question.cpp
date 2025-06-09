//https://www.spoj.com/problems/SUBMERGE/
#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m) {
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<n; i++) {
        int u , v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false), isap(n, false);
    vector<int> tin(n), low(n);
    int timer = 0;

    auto dfs = [&](int nd, int p, auto&& dfs) -> void {
        vis[nd] = true;
        tin[nd] = low[nd] = timer++;
        int c = 0;

        for(auto ng:adj[nd]) {
            if(ng == p) continue;
            if(!vis[ng]) {
                ++c;
                dfs(ng, nd, dfs);
                low[nd] = min(low[nd], low[ng]);
                if(low[ng] >= tin[nd] && p != -1) {
                    isap[nd] = true;
                }
            } else low[nd] = min(low[nd], tin[ng]);
        }
        if(p == -1 && c > 1) isap[nd] = true;
    };

    dfs(0, -1, dfs);

    int cnt = 0;
    for(int i=0; i<n; i++) if(isap[i]) cnt++;
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while(true) {
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve(n, m);
    }
}
