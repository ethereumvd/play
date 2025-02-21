#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> adj[100005];
int white, black ;

void dfs(int nd,int par, bool col) {

    if(col) black++ ;
    else white++;

    for(int i=0; i<adj[nd].size();i++){
        if(adj[nd][i]!=par) {
            dfs(adj[nd][i],nd,!col);
        }
    }
}

void jogo() {
    cin >> n;
    white = 0; black = 0;
    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,0);
    int ans = (white*black) - (n-1);
    cout << ans << " " << endl;
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
