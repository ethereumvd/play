#include<bits/stdc++.h>
using namespace std;

struct dsu {

    vector<int> parent;
    vector<int> size;

    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int find_rt(int u) {
        if(parent[u]==u) return u;
        return parent[u] = find_rt(parent[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);

        if(rt_v!=rt_u) {
            if(size[rt_u]<size[rt_v]) swap(rt_u,rt_v);
            parent[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
        }
    }

    int gsize(int u) {
        int rt_u = find_rt(u);
        return size[rt_u];
    }

};

void jogo() {

    int n,m ; cin >> n >> m;
    dsu d(n);

    for(int i=0; i<m; i++) {
        int k ; cin >> k;
        vector<int> t(k);
        for(int j=0; j<k; j++) {
            cin >> t[j];
            t[j]--;
        }
        for(int j=0; j<k-1; j++) {
            d.merge(t[j],t[j+1]);
        }
    }

    vector<int> ans(n,0);
    for(int i=0; i<n; i++) {
        ans[i] += d.gsize(i) ;
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n"; 
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
