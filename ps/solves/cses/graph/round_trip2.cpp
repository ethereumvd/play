#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>());
    vector<int> par(n,-2);

    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n,-1);
    int lp = -1,st =-1;

    function<bool(int)> dfs = [&] (int nd) -> bool {
        vis[nd] = 0;
        for(auto nx:adj[nd]) {
            if(vis[nx]==0) {
                par[nx] = nd;
                lp = nx;
                st = nd;
                return true;
            } else if(vis[nx]==-1){
                par[nx] = nd;
                if(dfs(nx)) return true;
            }
        }
        vis[nd] = 1;
        return false;
    };

    for(int i=0; i<n; i++) {
        if(vis[i]== -1 && dfs(i)) break;
    }

    if(lp == -1) cout << "IMPOSSIBLE" ;
    else {
        vector<int> path;
        path.push_back(lp);
        for(int i=st; i!=lp; i=par[i]) {
            path.push_back(i);
        }
        path.push_back(lp);
        reverse(path.begin(),path.end());
        cout << path.size() << "\n";
        for(int i:path) cout << i+1 << " " ;
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
