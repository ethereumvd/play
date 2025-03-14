#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pi pair<int,int>
const int inf = LLONG_MAX;
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
    }
    vector<int> d(n,inf);
    int src = 0; d[src] = 0;

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({d[src],src});

    while(!pq.empty()) {
        int nd = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist > d[nd]) continue;

        for(auto x:adj[nd]) {
            int nx = x.first;
            int wnx = x.second;

            if(d[nd] + wnx < d[nx]) {
                d[nx] = d[nd] + wnx;
                pq.push({d[nx],nx});
            }
        }
    }

    for(int &i:d) cout << i << " ";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
