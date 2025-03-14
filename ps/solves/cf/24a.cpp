#include<bits/stdc++.h>
using namespace std;
vector<int> path;
vector<bool> vis;

void dfs(int nd, vector<vector<int>> &adj) {
    vis[nd] = true;
    path.push_back(nd);

    for(auto nx:adj[nd]) {
        if(!vis[nx]) {
            dfs(nx,adj);
        }
    }
    return;
}
void jogo() {
    int n; cin >> n;
    vis.resize(n,false);
    vector<vector<int>> adj(n,vector<int>());
    map<pair<int,int>,int> mp;

    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        mp[{a,b}] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,adj);
    path.push_back(0);

    int sm1 = 0, sm2 = 0;
    for(int i=0; i<path.size()-1; i++) {
        int nd1 = path[i], nd2 = path[i+1]; 
        if(mp.find({nd1,nd2})!=mp.end()) {
            sm1 += mp[{nd1,nd2}] ;
        } else {
            sm2 += mp[{nd2,nd1}];
        }
    }

    cout << min(sm1,sm2) << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
