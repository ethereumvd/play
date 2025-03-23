#include <bits/stdc++.h>
using namespace std;
#define int long long
const int ninf = -1e18;
struct edge {
    int u, v, w;
};

void jogo() {
    int n, m;
    cin >> n >> m;
    
    vector<edge> edges;
    vector<vector<int>> adj(n), rev_adj(n); // Graph and reverse graph for reachability check
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Convert to 0-based index
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> dist(n, ninf);
    dist[0] = 0; // Start from room 1 (index 0)

    // Bellman-Ford relaxation for (n-1) times
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != ninf && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Detect Positive Cycles
    vector<bool> in_cycle(n, false);
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            if (dist[e.u] != ninf && dist[e.u] + e.w > dist[e.v]) {
                in_cycle[e.v] = true;
                dist[e.v] = 1e18; // Mark as potentially infinite
            }
        }
    }

    // **Check if Cycle is Reachable from 1 and Can Reach n**
    vector<bool> reachable_from_1(n, false), reachable_to_n(n, false);
    
    function<void(int, vector<vector<int>>&, vector<bool>&)> dfs = [&](int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) dfs(neighbor, graph, visited);
        }
    };
    
    dfs(0, adj, reachable_from_1);  // Mark nodes reachable from 1
    dfs(n - 1, rev_adj, reachable_to_n); // Mark nodes that can reach n
    
    // If any positive cycle is reachable from 1 and can reach n, print -1
    for (int i = 0; i < n; i++) {
        if (in_cycle[i] && reachable_from_1[i] && reachable_to_n[i]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << dist[n - 1] << "\n"; // Print max score
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    jogo();
    return 0;
}

