#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> par(n, -1);
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 1; i <= n - 1; i++) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i);
        par[i] = p;
    }
    vector<tuple<int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        queries[i] = {u, v};
    }

    int rt = 0;
    int LOG = 0;
    while((1 << LOG) <= n) LOG++;

    vector<vector<int>> up(n, vector<int>(LOG + 1, -1));
    //up[v][k] is v's 2^k th parent

    for(int nd = 0; nd < n; nd++) up[nd][0] = par[nd];
    for(int i = 0; i <= LOG; i++) up[rt][i] = rt;

    for(int i = 1; i <= LOG; i++) {
        for(int nd = 0; nd < n; nd++) {
            up[nd][i] = up[up[nd][i-1]][i-1];
        }
    }

    vector<int> depth(n, 0);
    auto dfs = [&](int nd, auto&& dfs) -> void {
        for(auto& ch : adj[nd]) {
            depth[ch] = depth[nd] + 1;
            dfs(ch, dfs);
        }
    };
    dfs(0, dfs);

    auto get_kth_anc = [&](int nd, int k) -> int {
        for(int i = 0; i <= LOG; i++) {
            if((1 << i) & k) {
                nd = up[nd][i];
            }
        }
        return nd;
    };

    auto get_lca = [&](int u, int v) -> int {
        if(depth[v] < depth[u]) swap(u, v);

        int diff = depth[v] - depth[u];
        v = get_kth_anc(v, diff);

        if(u == v) return u;

        int K = LOG;
        while(par[u] != par[v]) {
            if(up[u][K] == up[v][K]) {
                K >>= 1;
            } else {
                u = up[u][K];
                v = up[v][K];
            }
        }

        return par[u];// = par[v];
    };

    for(auto& [u, v] : queries) {
        int lca = get_lca(u, v);
        cout << lca + 1 << "\n";
    }

}