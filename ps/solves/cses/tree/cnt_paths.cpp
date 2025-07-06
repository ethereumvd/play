#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<tuple<int, int>> paths(m);

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        paths[i] = {u, v};
    }

    vector<int> depth(n, 0);
    vector<int> par(n, 0);

    auto dfs1 = [&] (int nd, int pr, auto&& dfs1) -> void {
        par[nd] = pr;

        for(auto& ch : adj[nd]) {
            if(ch != pr) {
                depth[ch] = depth[nd] + 1;
                dfs1(ch, nd, dfs1);
            }
        }
    };
    dfs1(0, 0, dfs1);

    int LOG = 0;
    while((1 << LOG) <= n) LOG++;

    vector<vector<int>> up(n, vector<int>(LOG + 1, 0));
    for(int nd = 0; nd < n; nd++) up[nd][0] = par[nd];

    for(int i = 1; i <= LOG; i++)
        for(int nd = 0; nd < n; nd++)
            up[nd][i] = up[up[nd][i-1]][i-1];


    auto get_kth_pr = [&] (int nd, int k) -> int {
        for(int i = LOG; i >= 0; i--)
            if((1 << i) & k) nd = up[nd][i];

        return nd;
    };

    auto get_lca = [&] (int u, int v) -> int {
        if(depth[u] > depth[v]) swap(u, v);
        v = get_kth_pr(v, depth[v] - depth[u]);

        if(u == v) return u;

        for(int i = LOG; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    };

    vector<int> pref(n, 0);

    auto dfs2 = [&](int nd, int pr, auto&& dfs2) -> void {
        for(auto& ch : adj[nd]) {
            if(ch != pr) {
                dfs2(ch, nd, dfs2);
                pref[nd] += pref[ch];
            }
        }
    };

    for(auto& [u, v] : paths) {
        int lca = get_lca(u, v);
        pref[u]++;
        pref[v]++;
        pref[lca]--;
        if(lca != 0) pref[par[lca]]--;
    }

    dfs2(0, 0, dfs2);

    for(auto& i : pref) cout << i << " ";
}