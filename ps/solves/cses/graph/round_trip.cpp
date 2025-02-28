// please reveiw dfs and cycle detection once again
// this was hell to debug
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<bool> vis;
int lpe ,lps = -1;

bool dfs(vector<vector<int>> &adj, int nd, int par) {

    vis[nd] = true;

    for(int i=0; i<adj[nd].size(); i++){
        if(adj[nd][i]==par) continue;
        if(!vis[adj[nd][i]]) {
            parent[adj[nd][i]] = nd;
            if(dfs(adj,adj[nd][i],nd)) return true;
        } else if(vis[adj[nd][i]]) {
            lpe = nd;
            lps = adj[nd][i];
            return true;
        }
    }

    return false;
}

void jogo() {

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>());
    parent.resize(n,-1);
    vis.resize(n,false);

    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        if(dfs(adj,i,parent[i])) break;
    }

    if(lps==-1) cout << "IMPOSSIBLE";
    else {
        vector<int> path;
        path.push_back(lps);
        for(int i=lpe; i!=lps; i=parent[i]) {
            path.push_back(i);
        }
        path.push_back(lps);
        cout << path.size() << "\n";
        for(int i=0; i<path.size(); i++) cout << path[i]+1 << " " ;

    }
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
