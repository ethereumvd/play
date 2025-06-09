//https://www.spoj.com/problems/EC_P/
#include <bits/stdc++.h>
using namespace std;

void solve(int t) {

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<tuple<int, int>> bridges;

    vector<bool> vis(n, false);
    vector<int> tin(n), low(n);
    int timer = 0;
    auto dfs = [&] (int nd, int pr, auto&& dfs) -> void {
        vis[nd] = true;
        tin[nd] = low[nd] = timer++;

        for(auto ng:adj[nd]) {
            if(ng == pr) continue;
            if(!vis[ng]) dfs(ng, nd, dfs);
            low[nd] = min(low[ng], low[nd]);

            if(low[ng] > tin[nd]) bridges.push_back({nd, ng});
        }
    };

    for(int i=0; i<n; i++) if(!vis[i]) dfs(i, -1, dfs);
    auto cmp = [&] (tuple<int,int> a, tuple<int, int> b) -> bool {
        auto [au, av] = a;
        auto [bu, bv] = b;
        if(au == bu) return av < bv;
        return au < av;
    };

    
    cout << "Caso #" << t << endl;
    if(bridges.empty()) {
        cout << "Sin bloqueos" << endl;
    }
    else {
        cout << bridges.size() << endl;
        for(auto edge:bridges) {
            auto [u, v] = edge;
            if(u > v) swap(u, v); 
        }
        sort(bridges.begin(), bridges.end(), cmp);
        for(auto edge:bridges) {
            auto [u, v] = edge ;
            cout << u+1 << " " << v+1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t ; cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
