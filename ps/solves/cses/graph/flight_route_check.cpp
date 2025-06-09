#include<bits/stdc++.h>
using namespace std;

void solve() {

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> rev_adj(n, vector<int>());
    for(int i=0; i<m; i++) {
        int u , v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<bool> vis(n, false);

    auto dfs = [&] (int nd, vector<int>& out, auto&& dfs) -> void {
        vis[nd] = true;
        for(auto ng:adj[nd]) {
            if(!vis[ng]) {
                dfs(ng, out, dfs);
            }
        }
        out.push_back(nd);
        return ;
    };

    auto dfs1 = [&] (int nd, vector<int>& out, auto&& dfs1) -> void {
        vis[nd] = true;
        out.push_back(nd);
        for(auto ng:rev_adj[nd]) {
            if(!vis[ng]) {
                dfs1(ng, out, dfs1);
            }
        }
        return ;
    };

    vector<int> ord;
    for(int i=0; i<n; i++) {
        if(!vis[i]) dfs(i, ord, dfs);
    }
    reverse(ord.begin(), ord.end());

    vector<vector<int>> scc;
    vis.assign(n, false);
    for(int i=0; i<n; i++) {
        if(!vis[ord[i]]) {
            vector<int> cc;
            dfs1(ord[i], cc, dfs1);
            scc.push_back(cc);
        }
    }

    // for(int i=0; i<n; i++) {
    //     cout << "adj list for nd " << i << endl;
    //     for(int j=0 ; j<adj[i].size(); j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //
    //
    // for(auto i:ord) cout << i << " " ;
    // cout << endl;
    //
    // cout << scc.size() << endl;
    // for(auto vec:scc) {
    //     for(auto i :vec )cout << i << " ";
    //     cout << endl;
    // }

    if(scc.size() <= 1) cout << "YES";
    else {
        cout << "NO\n" ;
        cout << scc[1][0] + 1 << " " << scc[0][0] + 1;
        //son of a bitch scc[0][0] << scc[1][0] wouldnt work
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
