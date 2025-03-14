#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int ninf = INT_MIN;
const int inf = 1e18;
#define pi pair<int,int>
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
    }
    vector<bool> vis(n,false);
    vector<int> d(n,inf);
    vector<int> nmin(n,0);
    vector<int> mxfl(n,inf);//wtf
    vector<int> mnfl(n,inf);

    int src = 0, ed = n-1; 
    d[src] = 0, nmin[src] = 1, mxfl[src] = 0, mnfl[src] = 0;

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    pq.push({d[src],src});

    while(!pq.empty())  {
        auto [dist,nd] = pq.top();
        pq.pop();
        if(vis[nd]) continue;
        vis[nd] = true;

        for(auto x:adj[nd]) {
            int nx = x.first;
            int wnx = x.second;
            if(d[nd]+wnx==d[nx]) {
                nmin[nx] = (nmin[nd]+nmin[nx])%mod;
                mnfl[nx] = min(mnfl[nx],mnfl[nd]+1);
                mxfl[nx] = max(mxfl[nx],mxfl[nd]+1);
                continue;
            }else if (d[nd]+wnx < d[nx]) {
                d[nx] = wnx + d[nd];
                nmin[nx] = nmin[nd];
                nmin[nx] %=mod;
                mnfl[nx] = mnfl[nd] + 1;
                mxfl[nx] = mxfl[nd] + 1;
                pq.push({d[nx],nx});
            }
        }
    }

    cout << d[ed] << " " << nmin[ed]%mod << " " << mnfl[ed] << " " << mxfl[ed] << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
