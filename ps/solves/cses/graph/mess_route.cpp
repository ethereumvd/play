#include<bits/stdc++.h>
using namespace std;

vector<int> path;

void pathtrace(int nd, vector<int> &parent) {
    if(nd==0) return;

    path.push_back(parent[nd]);
    pathtrace(parent[nd],parent);
}

void jogo() {

    int n, m; cin >> n >> m ;
    vector<vector<int>> adj(n,vector<int>());
    vector<bool> vis(n,0);
    vector<int> parent(n);

    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v ;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(0);
    vis[0] = true ;

    while(!q.empty()) {
        int nd = q.front();
        q.pop();
        for(int i=0; i<adj[nd].size(); i++) {
            if(vis[adj[nd][i]]) continue;
            q.push(adj[nd][i]);
            vis[adj[nd][i]] = true ;
            parent[adj[nd][i]] = nd ;
        }
    }

    if(!vis[n-1]) cout << "IMPOSSIBLE"; 
    else {
        pathtrace(n-1, parent);
        reverse(path.begin(),path.end());

        cout << path.size()+1 << "\n";
        for(int i=0; i<path.size(); i++) {
            cout << path[i]+1 << " " ;
        }
        cout << n ;
    }

}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
