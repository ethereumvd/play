#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> rev_adj(n, vector<int>());
    for(int i=0; i<m; i++) {
        int u, v ; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    vector<int> kingdom(n);

    auto dfs = [&](int nd, vector<int>& out, auto&& dfs) -> void {
        vis[nd] = true;
        for(auto ng:adj[nd]) {
            if(!vis[ng]) {
                dfs(ng, out, dfs);
            }
        }
        out.push_back(nd);
    };

    auto dfs1 = [&] (int nd, int label, auto&& dfs1) -> void {
        vis[nd] = true;

        for(auto ng:rev_adj[nd]) {
            if(!vis[ng]) {
                dfs1(ng, label, dfs1);
            }
        }
        kingdom[nd] = label;
    };

    vector<int> ord;
    for(int i=0; i<n; i++) {
        if(!vis[i]) dfs(i, ord, dfs);
    }
    reverse(ord.begin(), ord.end());
    
    vis.assign(n, false);

    int cnt = 0;

    for(auto i:ord) {
        if(!vis[i]) {
            cnt++;
            dfs1(i, cnt, dfs1);
        }
    }

    cout << cnt << endl;
    for(auto i:kingdom) cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
