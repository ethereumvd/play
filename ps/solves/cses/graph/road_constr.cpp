#include<bits/stdc++.h>
using namespace std;
struct dsu {

    vector<int> par;
    vector<int> size;

    dsu(int n) {
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find_rt(int u) {
        if(u==par[u]) return u;
        return par[u] = find_rt(par[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);
        if(rt_v!=rt_u) {
            if(size[rt_u] < size[rt_v]) swap(rt_u,rt_v);
            size[rt_u] += size[rt_v];
            par[rt_v] = rt_u;
        }
    }

};
void jogo() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edges.push_back({a,b});
    } 

    dsu d(n); 
    int mxsz = 1, cc = n;
    for(auto e:edges) {
        int u = e.first;
        int v = e.second;

        int rt_u = d.find_rt(u);
        int rt_v = d.find_rt(v);
        if(rt_v==rt_u) {
            cout << cc << " "  << mxsz << "\n";
        } else {
            int sz_u = d.size[rt_u];
            int sz_v = d.size[rt_v];
            mxsz = max(mxsz,sz_u+sz_v);
            d.merge(rt_u,rt_v);
            cc--;
            cout << cc << " " << mxsz << "\n";
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
