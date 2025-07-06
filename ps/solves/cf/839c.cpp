#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n, 0);
    vector<double> probs(n, 0);
    vector<bool> vis(n, false);
    int rt = 0;

    auto dfs = [&](int nd, double prob, auto&& dfs) -> void {
        vis[nd] = true;
        double p = adj[nd].size() == 1 ? 1.0 : (1.0/(adj[nd].size() - 1));
        if(nd == rt) p = (1.0/adj[nd].size());
        if(adj[nd].size() == 1) probs[nd] = prob;

        for(auto& ch : adj[nd]) {
            if(!vis[ch]) {
                depth[ch] = depth[nd] + 1;
                dfs(ch, p*prob, dfs);
            }
        }
    };

    dfs(0, 1.0, dfs);
    double res = 0;
    for(int i = 0; i < n; i++) {
        res += probs[i] * (double)depth[i];
    }

    cout << fixed << setprecision(6) << res;

}