#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>());
    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n,-1);
    vector<int> topo;

    function<bool(int)> dfs = [&] (int nd) -> bool {
        vis[nd] = 0;

        for(auto nx:adj[nd]) {
            if(vis[nx]==0) return true;
            else if(vis[nx]==-1) {
                if(dfs(nx)) return true;
            }
        }
        vis[nd] = 1 ;
        /*cout << nd+1 << "\n";*/
        topo.push_back(nd);
        return false;
    };  

    bool poss = true;
    for(int nd=0; nd<n; nd++) {
        if(vis[nd]==-1) {
            if(dfs(nd)) {
                poss = false;
                break;
            }
        }
    }

    if(!poss) cout << "IMPOSSIBLE";
    else {
        reverse(topo.begin(),topo.end());
        for(int &i:topo) cout << i+1 << " ";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
