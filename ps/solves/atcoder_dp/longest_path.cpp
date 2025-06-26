#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dist;
vector<bool> vis;

void dfs(int nd) {
    vis[nd] = true;

    for(int ng : adj[nd]) {
        if(!vis[ng]) dfs(ng);
        dist[nd] = max(dist[nd], 1 + dist[ng]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    adj.resize(N);
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
    }

    dist.resize(N, 0);
    vis.resize(N, false);

    for(int i = 0; i < N; i++) {
        if(!vis[i]) dfs(i);
    }

    cout << *max_element(dist.begin(), dist.end());

}