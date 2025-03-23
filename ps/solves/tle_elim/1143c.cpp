#include<bits/stdc++.h>
using namespace std;
#define int long long
//just fuck off such a small mistake
void jogo() {
    int n; cin >> n;
    vector<vector<int>> adj(n,vector<int>());
    vector<int> c(n), par(n); 
    int rt ;
    for(int i=0; i<n; i++) {
        int u, ci; cin >> u >> ci;
        if(u==-1){
            rt = i;
            c[i] = ci;
            par[i] = -1;
            continue;
        }
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
        c[i] = ci;
        par[i] = u;
    }
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(i==rt) continue;
        int rem = 1;
        for(auto nd:adj[i]) {
            if(nd==par[i]) continue;
            rem &= c[nd];
        }
        rem &= c[i];
        if(rem==1) ans.push_back(i);
    }

    if(ans.empty()) cout << "-1" ;
    else for(int i:ans) cout << i+1 << " " ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
