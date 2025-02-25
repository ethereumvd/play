#include<bits/stdc++.h>
using namespace std;

void jogo() {

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>());
    vector<bool> vis(n,0);
    vector<bool> team(n);

    while(m--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(vis[i]) continue;

        queue<int> q ;
        q.push(i);
        vis[i] = true;
        team[i] = 0;

        while(!q.empty()) {
            int nd = q.front();
            q.pop();

            for(int j=0; j<adj[nd].size(); j++) {
                if(vis[adj[nd][j]]) {
                    if(team[adj[nd][j]]==team[nd]) {
                        cout << "IMPOSSIBLE" ;
                        return;
                    }
                    continue ;
                }
                q.push(adj[nd][j]);
                vis[adj[nd][j]] = true ;
                team[adj[nd][j]] = !team[nd] ;
            } 
        }
    }

    for(int i=0; i<n; i++) {
        if(team[i]) cout << 1 << " " ;
        else cout << 2 << " " ;
    }

}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
