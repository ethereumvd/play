#include<bits/stdc++.h>
using namespace std;

//simple binary lifting
// n <= 2 * 10e5 so logn can go upto 18

void solve() {
    int n, q; cin >> n >> q;
    vector<int> par(n);
    par[0] = -1;
    for(int i=1; i<n; i++) {
        cin >> par[i];
        par[i]--;
    }
    int LOG = 0;
    while((1<<(LOG)) <= n) LOG++;

    vector<vector<int>> anc(n,vector<int>(LOG,-1)); 
    for(int nd = 0; nd < n; nd++) {
        anc[nd][0] = par[nd];
    }
    for(int lev = 1; lev < LOG; lev++) {
        for(int nd = 0; nd < n; nd++) {
            if(anc[nd][lev-1] != -1)
            anc[nd][lev] = anc[anc[nd][lev-1]][lev-1];
        }
    }

    for(int qr=0; qr<q; qr++) {
        int nd, k; cin >> nd >> k; 
        nd--;
        int ptr = 0;
        int par = nd;
        for(int i = 0; i<LOG; i++) {
            if((1 << i) & k) {
                par = anc[par][i];
                if(par == -1) break;
            }
        }

        cout << (par == -1 ? par : par + 1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
