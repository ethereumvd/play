#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n ; cin >> n;
    vector<vector<int>> adj(n, vector<int>());

    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> subtrsz(n, 1);

    auto dfs1 = [&](int nd, int pr, auto&& dfs1) -> void {
        for(auto& ch : adj[nd]) {
            if(ch != pr) {
                dfs1(ch, nd, dfs1);
                subtrsz[nd] += subtrsz[ch];
            }
        }
    };
    dfs1(0, 0, dfs1);

    auto dfs2 = [&](int nd, int pr, auto&& dfs2) -> int {
        for(auto& ch : adj[nd]) {
            if(ch != pr) {
                if(subtrsz[ch] > n/2) return dfs2(ch, nd, dfs2);
            }
        }
        return nd;
    };

    cout << dfs2(0, 0, dfs2) + 1;
}