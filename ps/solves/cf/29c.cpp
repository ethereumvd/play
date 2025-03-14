#include<bits/stdc++.h>
using namespace std;
//maps are the best thing that has happened to humanity
void jogo() {
    int n; cin >> n;
    map<int,bool> vis;
    map<int,vector<int>> adj;
    map<int,int> deg;
    vector<int> path;
    set<int> st;
    
    while(n--) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        st.insert(u); st.insert(v);
        deg[u]++;
        deg[v]++;
        if(deg[u]>1) st.erase(u);
        if(deg[v]>1) st.erase(v);
    }

    function<void(int)> dfs = [&] (int nd) -> void {
        vis[nd] = true;
        path.push_back(nd);
        for(auto nx:adj[nd]) {
            if(!vis[nx]) {
                dfs(nx);
            }
        }
        return;
    };

    int str = *st.begin();
    dfs(str);

    for(int i=0; i<path.size(); i++) cout << path[i]+1 << " " ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
