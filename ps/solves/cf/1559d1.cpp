#include<bits/stdc++.h>
using namespace std;

struct dsu {

    vector<int> par,size;

    dsu(int n) {
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) par[i]=i;
    }

    int find_rt(int u) {
        if(par[u]==u) return u;
        return par[u] = find_rt(par[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);
        if(rt_u!=rt_v) {
            if(size[rt_u]<size[rt_v]) {
                swap(rt_u,rt_v);
            }
            par[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
        }
     }
};

void jogo() {

    int n, m1, m2; cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    while(m1--) {
        int u, v; cin >> u >> v;
        u--; v--;
        d1.merge(u,v);
    }
    while(m2--) {
        int u, v; cin >> u >> v;
        u--; v--;
        d2.merge(u,v);
    }

    vector<pair<int,int>> edges;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(d1.find_rt(i)!=d1.find_rt(j) && d2.find_rt(i)!=d2.find_rt(j)) {
                edges.push_back({i,j});
                d1.merge(i,j);
                d2.merge(i,j);
            } 
        }
    }

    if(edges.empty()){
        cout << 0 ;
        return;
    }
    cout << edges.size() << "\n";
    for(int i=0; i<edges.size(); i++) {
        cout << edges[i].first+1 << " " << edges[i].second+1 << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
