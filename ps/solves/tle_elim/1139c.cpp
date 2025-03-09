#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int binpow(int a, int n) {
    int ans = 1 ;
    while(n>0) {
        if(n&1) ans = (ans * a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}

struct dsu {

    vector<int> par;
    vector<int> size;

    dsu(int n) {
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int find_rt(int u) {
        if(par[u]==u) return u;
        return par[u] = find_rt(par[u]);
    }

    void merge(int u, int v) {
        int rt_u = find_rt(u);
        int rt_v = find_rt(v);
        if(rt_u!=rt_v) {
            if(size[rt_u]<size[rt_v]) swap(rt_u,rt_v);
            par[rt_v] = rt_u;
            size[rt_u] += size[rt_v];
        }
    }

};

void jogo() {
    int n, k; cin >> n >> k;
    dsu d(n);

    for(int i=0; i<n-1; i++) {
        int u, v, x; cin >> u >> v >> x;
        u--; v--;
        if(x==1) continue;
        d.merge(u,v);
    }

    int ans = binpow(n,k);
    map <int,bool> sz;
    for(int i=0; i<n; i++) {
        if(sz[d.find_rt(i)]) continue;
        sz[d.find_rt(i)]= true;
        ans = (ans - binpow(d.size[d.find_rt(i)],k) + mod)%mod; 
    }
    /**/
    /*if(sz.size()==1 && sz.begin()->first==n) {*/
    /*    cout << "0";*/
    /*    return;*/
    /*}*/

    /*for(auto [s,cnt] : sz) {*/
        /*ans = (ans - (cnt*binpow(s,k)) + mod)%mod; */
    /*}*/
    cout << ans ;
}

int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
