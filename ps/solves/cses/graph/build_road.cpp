#include<bits/stdc++.h>
using namespace std;

struct dsu {

    vector<int> parent, size;
    dsu(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i ;
    }

    int find_rt(int u) {
        if(parent[u]==u) return u;
        return parent[u] = find_rt(parent[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);

        if(rt_u!=rt_v) {
            if(size[rt_v]>size[rt_u]) {
                swap(rt_u,rt_v);
            }
            parent[rt_v] = rt_u ;
            size[rt_u] += size[rt_v] ;
        }
    }
};

void jogo() {

    int n , m; cin >> n >> m;
    dsu d(n);

    while(m--) {
        int u, v; cin >> u >> v ;
        u--; v--;
        d.merge(u,v);
    }

    set<int> roots;

    for(int i=0; i<n; i++) d.find_rt(i);
    for(int i=0; i<n; i++) {
        roots.insert(d.find_rt(i));
    }

    int sz = roots.size() ;
    cout << sz - 1 << "\n" ;
    if(sz!=1) {
        auto it = roots.begin();
        int first = *it;
        for(auto i=roots.begin(); i!=roots.end(); i++) {
            if(*i==*it) continue ;
            cout << first+1 << " " << *i+1 << "\n" ;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
