#include<bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
#define pi pair<int,int>
const int inf = 1e18;
//good question dimag thoda sa khula
//try to think once again
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj1(n);
    vector<vector<pi>> adj2(n);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj1[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }

    function<void(int,vector<int>&,vector<vector<pi>>&)> dijkstra = [&](int src,vector<int> &d,vector<vector<pi>> &adj){
        d.assign(n,inf);
        d[src] = 0;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({d[src],src});

        while(!pq.empty()) {
            auto [dnd,nd] = pq.top();
            pq.pop();
            if(dnd > d[nd]) continue;

            for(auto x:adj[nd]) {
                int nx = x.first;
                int wnx = x.second;
                if(d[nd] + wnx < d[nx]) {
                    d[nx] = d[nd] + wnx;
                    pq.push({d[nx],nx});
                }
            }
        }
    };
    int s1 = 0; vector<int> d1;
    dijkstra(s1,d1,adj1);
    int s2 = n-1; vector<int> d2;
    dijkstra(s2,d2,adj2);

    //iterate over all edges to choose which edge will give minimum
    int mn = 1e18;
    for(int nd=0; nd<n; nd++) {
        for(auto x:adj1[nd]) {
            int nx = x.first;
            int wnx = x.second;
            mn = min(mn,d1[nd] + (wnx/2) + d2[nx]);
        }
    }
    cout << mn ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
