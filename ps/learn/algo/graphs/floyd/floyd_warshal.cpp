#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18 ;
void jogo() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> d(n,vector<int>(n,inf));
    for(int i=0; i<n; i++) d[i][i] = 0;
    while(m--) {
        int i, j, w; cin >> i >> j >> w;
        i--; j--;
        d[i][j] = min(d[i][j],w);//piece of shit
        d[j][i] = min(d[j][i],w);
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(d[i][k] < inf && d[k][j] < inf) {
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    while(q--) {
        int i, j; cin >> i >> j;
        i--; j--;
        if(d[i][j] != inf) cout << d[i][j] << "\n";
        else cout << -1 << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}

