#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> memo;

void dfs(vector<vector<int>>& adj, vector<int>& out, int nd, vector<bool>& vis) {

    vis[nd] = true;

    for(auto& ch : adj[nd]) {
        if(!vis[ch]) {
            dfs(adj, out, ch, vis);
        }
    }

    out.emplace_back(nd);
}

int dp(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& coins, int nd) {

    if(memo.count(nd)) return memo[nd];

    int res = 0;
    vis[nd] = true;

    for(auto& ch : adj[nd]) {
        res = max(res, dp(adj, vis, coins, ch));
    }

    return memo[nd] = coins[nd] + res;
}


int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> coins(n);
    vector<vector<int>> adj(n), rev_adj(n);
    for(auto& i : coins) cin >> i;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        rev_adj[v].emplace_back(u);
    }

    vector<bool> vis(n, false);

    vector<int> topo;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(adj, topo, i, vis);
    }
    reverse(topo.begin(), topo.end());

    vis.assign(n, false);

    vector<int> root(n);
    vector<int> totcoincomp(n);

    for(auto& i : topo) {
        if(vis[i]) continue;

        vector<int> comp;
        dfs(rev_adj, comp, i, vis);

        int rt = i;
        root[rt] = rt;
        int totcoins = 0;

        for(auto& c : comp) {
            root[c] = i;
            totcoins += coins[c];
        }
        totcoincomp[rt] = totcoins;
    }

    vector<vector<int>> condensed(n, vector<int>());

    for(int i = 0; i < n; i++) {
        for(auto& ch : adj[i]) {
            int rt_i = root[i];
            int rt_ch = root[ch];
            if(rt_i != rt_ch) {
                condensed[rt_i].push_back(rt_ch);
            }
        }
    }

    vis.assign(n, false);

    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            ans = max(ans, dp(condensed, vis, totcoincomp, i));
        }
    }

    cout << ans ;
}