#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, st, en; cin >> n >> st >> en;
    st--; en--;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,false);
    vector<int> perm ;

    queue<int> q;
    q.push(en);
    vis[en] = true;
    while(!q.empty()) {
        int nd = q.front();
        q.pop();
        perm.push_back(nd);
        for(int nx:adj[nd]) {
            if(!vis[nx]) {
                vis[nx] = true;
                q.push(nx);
            }
        }
    }
    reverse(perm.begin(),perm.end());
    for(int i=0; i<n; i++) {
        cout << perm[i]+1 << " ";
    }
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
