#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int ans = 0;

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            deg[u]++;
            deg[v]++;
        }

        int u = max_element(deg.begin(), deg.end()) - deg.begin();

        ans += deg[u];

        for (auto v : adj[u]) {
            deg[v]--;
            // adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
        }

        deg[u] = 0;

        u = max_element(deg.begin(), deg.end()) - deg.begin();
        ans += deg[u];

        cout << ans - 1 << "\n";
    }
}