#include<bits/stdc++.h>
using namespace std;
class dsu {
private:
  vector<int> size;
  vector<int> par;
public:

  dsu(int n) {
    size.assign(n,1);
    par.resize(n);
    for(int i=0; i<n; i++) par[i] = i;
  }

  int get_rt(int u) {
    if(par[u] == u) return u;
    return par[u] = get_rt(par[u]);
  }

  void merge(int u, int v) {
    int rt_u = get_rt(u);
    int rt_v = get_rt(v);

    if(rt_u != rt_v) {
      if(size[rt_u] < size[rt_v]) swap(rt_u,rt_v);
      par[rt_v] = rt_u;
      size[rt_u] += size[rt_v];
    }
  }
};
void jogo() {

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
