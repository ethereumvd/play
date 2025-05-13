#include<bits/stdc++.h>
using namespace std;

void solve() {

    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>());

    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   

    int mxlev = 0, mxnd = -1 ;
    auto dfs = [&] (int nd, int par, int lev, auto&& dfs) -> void {
        if(lev > mxlev) {
            mxlev = lev;
            mxnd = nd;
        }

        for(auto ch:adj[nd]) {
            if(ch == par) continue;
            dfs(ch, nd, lev+1 ,dfs);
        }
        return;
    };
    dfs(0, -1, 0, dfs);
    mxlev = 0;
    int u = mxnd;
    dfs(mxnd, -1, 0, dfs);
    int dia = mxlev;
    int v = mxnd;

    vector<int> dist1(n,0), dist2(n,0);

    auto dfs2 = [&](int rt, int nd, int par, int lev, auto&& dfs2) -> void {
        if(rt == u) dist1[nd] = lev;
        if(rt == v) dist2[nd] = lev;

        for(auto ch:adj[nd]) {
            if(ch == par) continue;
            dfs2(rt, ch, nd, lev+1, dfs2);
        }
    };
    dfs2(u, u, -1, 0, dfs2);
    dfs2(v, v, -1, 0, dfs2);

    for(int i=0; i<n; i++) {
        cout << max(dist1[i], dist2[i]) << " ";
    }
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
