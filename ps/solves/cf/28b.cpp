#include<bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> par;
    vector<int> size;

    dsu(int n) {
        size.assign(n,1);
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find_rt(int u) {
        if(par[u]==u) return u;
        return par[u] = find_rt(par[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);
        if(rt_v!=rt_u) {
            if(size[rt_u] < size[rt_v]) swap(rt_u, rt_v);
            par[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
        }
    }
};
void jogo() {
    int n; cin >> n;
    vector<int> perm(n);
    vector<int> fav(n);
    for(int i=0; i<n; i++) {
        cin >> perm[i];
        perm[i]--;
    }
    for(int &i:fav) cin >> i;

    dsu d(n);
    for(int i=0; i<n; i++) {
        int j1 = i - fav[i];
        int j2 = i + fav[i];
        if(j1 >= 0) d.merge(i,j1);
        if(j2 < n) d.merge(i,j2);
    }

    bool ans = true;
    for(int i=0; i<n; i++) {
        if(d.find_rt(perm[i]) != d.find_rt(i)) {
            ans = false;
            break;
        }
    }

    if(ans) cout << "YES\n" ;
    else cout << "NO\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
