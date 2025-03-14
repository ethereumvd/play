#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
const int inf = LLONG_MAX; //fking piece of shit 
void jogo() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> d(n,inf);
    vector<int> par(n,-1);
    int src = 0, ed = n-1;
    d[src] = 0;

    set<pi> st;
    st.insert({d[src],src});

    while(!st.empty()) {
        auto it = *(st.begin());
        int nd = it.second;
        st.erase(st.begin());

        for(auto x:adj[nd]){
            int ndx = x.second;
            int nx = x.first;
            if(d[nd] + ndx < d[nx]) {
                if(d[nx]!=inf) {
                    st.erase({d[nx],nx});
                }
                d[nx] = d[nd] + ndx;
                par[nx] = nd;
                st.insert({d[nx],nx});
            }
        }
    }

    if(d[ed]==inf) cout << "-1" ;
    else {
        vector<int> path;
        for(int i=ed; i!=src; i=par[i]) {
            path.push_back(i);
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        for(int i:path) cout << i+1 << " ";
    }


}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
