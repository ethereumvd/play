#include<bits/stdc++.h>
using namespace std;
#define int long long
const int ninf = -1e18;
//oh no have to check if the positive cycle can reach destination or not
struct edge {
    int u, v, w;
};
void jogo() {
    int n, m; cin >> n >> m;
    vector<edge> edges;
    while(m--) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--; e.v--;
        edges.push_back(e);
    }
    vector<int> d(n,ninf);
    int src = 0; d[src] = 0;

    bool flag = false;
    for(int i=0; i<n; i++) {
        for(auto e:edges) {
            if(d[e.u] != ninf && d[e.u] + e.w > d[e.v]) {
                    d[e.v] = d[e.u] + e.w;
                    if(i==n-1) flag = true;
            }
        }
    }
    if(flag) cout << -1 << "\n";
    else cout << d[n-1] << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
