#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct dsu {
    vector<int> par;
    vector<int> size;

    dsu(int n) {
        size.assign(n,1);
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find_rt(int u) {
        if(par[u] == u) return u;
        else return par[u] = find_rt(par[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);
        if(rt_u!=rt_v) {
            if(size[rt_u] < size[rt_v]) swap(rt_u,rt_v);
            par[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
        }
    }
};
struct edge {
    int u, v, w;
};
bool cmp(edge e1 , edge e2) {
    return e1.w < e2.w;
}
void jogo() {
    int n, m, k; cin >> n >> m >> k;
    vector<edge> edges;
    while(m--) {
        edge e;
        cin >> e.u >> e.v >> e.w;
        e.u--; e.v--;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end(),cmp);

    int op = 0;
    dsu d(n); vector<int> mst;
    for(auto e:edges) {
        if(d.find_rt(e.u)!=d.find_rt(e.v)) {
            if(e.w > k) op += (e.w - k);
            d.merge(e.u,e.v);
            mst.push_back(e.w);
        }
    }
    int mx = *max_element(mst.begin(),mst.end());
    if( mx < k) {
        op = INT_MAX;
        for(auto e:edges) {
            op = min(op, abs(e.w-k));
        }
    }

    cout << op << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
