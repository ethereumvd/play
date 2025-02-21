#include<bits/stdc++.h>
using namespace std;
#define int long long 

int paths = 0;

int nc2(int n) {
    return (n*(n-1)) / 2 ;
} 

struct dsu {

    vector<int> parent;
    vector<int> size;

    dsu(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_rt(int v){
        if(parent[v]==v) return v;
        return parent[v] = find_rt(parent[v]);
    }

    void merge(int u , int v){
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);

        if(rt_v!=rt_u) {
            if(size[rt_u]<size[rt_v]){
                swap(rt_v,rt_u);
            }
            paths -= (nc2(size[rt_u]) + nc2(size[rt_v]));
            parent[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
            paths += nc2(size[rt_u]);
        }

    }
};

void jogo() {

    int n,m; cin >> n >> m;
    vector<pair<int,pair<int,int>>> edge(n-1) ;

    for(int i=0; i<n-1; i++) {
        int u,v,w ; cin >> u >> v >> w;
        u--; v--;
        edge[i]={w,{u,v}};
    }

    sort(edge.begin(),edge.end());

    vector<pair<int,int>> q(m);
    for(int i=0; i<m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(q.begin(),q.end());
    dsu d(n); vector<int> ans(m);

    int j=0;

    for(int i=0; i<m; i++) {
        while(j<n-1 && edge[j].first <= q[i].first) {
            int u = edge[j].second.first;
            int v = edge[j].second.second;
            d.merge(u,v);
            j++;
        }
        ans[q[i].second] = paths;
    }

    for(int i=0; i<m; i++) cout << ans[i] << " ";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
