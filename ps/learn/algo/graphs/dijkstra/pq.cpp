#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e9;
#define pi pair<int,int>
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> par(n,-1);
    vector<int> d(n,inf);
    int src = 0,ed = n-1;
    d[src] = 0;

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({d[src],src});

    while(!pq.empty()) {
        int nd = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist > d[nd]) continue;

        for(auto x:adj[nd]) {
            int nx = x.first;
            int dnx = x.second;
            if(d[nd] + dnx < d[nx]) {
                d[nx] = d[nd] + dnx;
                pq.push({d[nx],nx});
                par[nx] = nd;
            }
        }
    }

    if(d[ed]==inf) cout << -1;
    else {
        vector<int> path;
        for(int i=ed; i!=src; i=par[i]) {
            path.push_back(i);
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        for(int i:path) cout << i+1 << " ";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
