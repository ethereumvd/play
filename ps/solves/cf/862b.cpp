#include<bits/stdc++.h>
using namespace std;
int w = 0 , b = 0;
vector<vector<int>> adj(1e5 ,vector<int>()) ;
void bfs(int nd , int pr , bool col) {

    queue<int> nxt ;
    nxt.push(nd) ;





}
void jogo() {

    int n ; cin >> n ;
    for(int i = 0 ; i<n-1 ;i++) {
        int u ,v ; cin >> u >> v ;
        adj[u].emplace_back(v) ;
        adj[v].emplace_back(u) ;
    }

    bfs(1,-1,0) ;

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ;
    int tc = 1 ; 
    cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
