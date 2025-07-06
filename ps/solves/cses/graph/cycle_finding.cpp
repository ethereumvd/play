#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;

struct Edge {
    int u;
    int v;
    int cost;
};

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        Edge e; cin >> e.u >> e.v >> e.cost;
        --e.u; --e.v;
        if(e.u == e.v && e.cost < 0) {
            cout << "YES\n";
            cout << e.u + 1 << " " << e.u + 1 << "\n";
            return 0;
        }
        edges.emplace_back(e);
    }

    vector<int> dist(n, 0); //keeping 0 very important
    dist[0] = 0;
    vector<int> par(n, -1);

    for(int i = 1; i <= n - 1; i++) {
        for(auto& e : edges) {
            if(dist[e.u] != inf && dist[e.u] + e.cost < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.cost;
                par[e.v] = e.u;
            }
        }
    }

    int str = -1;
    for(auto& e : edges) {
        if(dist[e.u] != inf && dist[e.u] + e.cost < dist[e.v]) {
            dist[e.v] = dist[e.u] + e.cost;
            par[e.v] = e.u;
            str = e.v;
        }
    }

    if(str == -1) cout << "NO\n";
    else {
        //this for is very important
        //as str is reachable by cycle not necessarily in cycle
        for(int i = 0; i < n; i++) str = par[str];

        vector<int> cycle;
        cycle.emplace_back(str);

        int it = par[str];

        while(it != str) {
            cycle.emplace_back(it);
            it = par[it];
        }
        cycle.emplace_back(str);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for(auto& i : cycle) cout << i + 1 << " ";
        cout << "\n";
    }
}