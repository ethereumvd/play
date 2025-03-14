#include<bits/stdc++.h>
using namespace std;
const int ninf = INT_MIN;
//if this works then my life is a lie
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    while(m--) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    vector<int> topo;
    vector<int> d(n,ninf);
    vector<int> par(n,-1);
    vector<bool> vis(n,false);
    int src = 0, ed = n-1;
    d[src] = 0;

    function<void(int)> dfs = [&] (int nd) {
        vis[nd] = true;
        for(auto nx:adj[nd]) {
            if(vis[nx]) continue;// one fucking line more and no tle 
            // this question can go fuck itself
            dfs(nx);
        }
        topo.push_back(nd);
    };

    dfs(src);
    if(!vis[ed]) cout << "IMPOSSIBLE\n";
    else {
        reverse(topo.begin(),topo.end());
        for(int nd:topo) {
            for(auto nx:adj[nd]) {
                if(d[nd] + 1 > d[nx]) {
                    d[nx] = d[nd] + 1;
                    par[nx] = nd;
                }
            }
        }
        vector<int> path;
        for(int i=ed; i!=src; i=par[i]) {
            path.push_back(i);
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        cout << d[ed] + 1 << "\n";
        for(int i:path) cout << i+1 << " ";
    }

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
