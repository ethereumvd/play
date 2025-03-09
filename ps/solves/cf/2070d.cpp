//wtf is happening 
//dry run giving absolutely correct answer
//but actual answer coming wrong
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;

void jogo() {

    int n; cin >> n;
    vector<vector<int>> adj(n,vector<int>());

    for(int i=1; i<=n-1; i++) {
        int v ; cin >> v;
        v--;
        adj[v].push_back(i);
        /*adj[i].push_back(v);*/
    }

    vector<int> lvnd ;
    for(int i=0; i<adj[0].size(); i++) {
        lvnd.push_back(adj[0][i]);
    }
    int ans = lvnd.size() ;
    vector<bool> vis(n,false);
    vis[0]=true;

    while(!lvnd.empty()) {
        vector<int> temp;

        for(int i:lvnd) {
            vis[i]= true;
            for(int u:adj[i]) {
                if(!vis[u]){
                    temp.push_back(u);
                }
            }
        }
        if(temp.empty()) break;
        int nlv = temp.size();

        for(int i:lvnd) {
            ans = (ans + (nlv - (adj[i].size())))%m;
        }
        lvnd = temp;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
