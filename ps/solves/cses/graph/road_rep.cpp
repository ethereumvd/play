#include<bits/stdc++.h>
using namespace std;
#define int long long
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
            if(size[rt_u]<size[rt_v]) swap(rt_u,rt_v);
            size[rt_u] += size[rt_v];
            par[rt_v] = rt_u;
        }
    }
};
struct edge {
    int u, v, w;
};
bool cmp(edge e1, edge e2) {
    return e1.w < e2.w;
}
void jogo() { int n, m; cin >> n >> m;
    vector<edge> edges;
    while(m--) {
        edge e; 
        cin >> e.u >> e.v >> e.w; 
        e.u--; e.v--;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end(),cmp);
    dsu d(n);
    int mstw = 0, cnt = 0;
    for(auto edge:edges) {
        int rt_u = d.find_rt(edge.u);
        int rt_v = d.find_rt(edge.v);
        if(rt_u!=rt_v) {
            d.merge(edge.u,edge.v);
            mstw += edge.w;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt!=n-1) cout << "IMPOSSIBLE\n";
    else cout << mstw << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
