#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<long long> subtrsz(n, 1);
    vector<long long> dp(n, 0);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs1 = [&](int nd, int par, int depth, auto&& dfs1) -> void {
        dp[0] += depth;
        for(auto& ch : adj[nd]) {
            if(ch != par) {
                dfs1(ch, nd, depth+1, dfs1);
                subtrsz[nd] += subtrsz[ch];
            }
        }
    };

    auto dfs2 = [&](int nd, int par, auto&&dfs2) ->void {
        for(auto& ch : adj[nd]) {
            if(ch != par) {
                dp[ch] = dp[nd] + (n - subtrsz[ch]) - subtrsz[ch];
                dfs2(ch, nd, dfs2);
            }
        }
    };

    dfs1(0, -1, 0, dfs1);
    dfs2(0, -1, dfs2);

    for(auto& i : dp) cout << i << " ";
}