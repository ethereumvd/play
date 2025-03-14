#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    vector<vector<int>> adj(n,vector<int>());
    vector<int> c(n);
    int rt ;
    for(int i=0; i<n; i++) {
        int u, ci; cin >> u >> ci;
        if(u==-1){
            rt = i;
            adj[0].push_back(i);
            c[i] = ci;
            continue;
        }
        u--;
        adj[u].push_back(i);
        adj[i].push_back(u);
        c[i] = ci;
    }
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(i==rt) continue;
        int rem = 1;
        for(auto nd:adj[i]) {
            if(nd==rt) {
                rem &= c[rt] == 1 ? 1 : 0 ; 
                continue;
            }
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
