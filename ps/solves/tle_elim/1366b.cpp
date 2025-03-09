#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, x, m; cin >> n >> x >> m;
    int lmx = x, rmx = x;
    while(m--) {
        int l, r; cin >> l >> r;
        if(max(lmx,l)<=min(r,rmx)) {
            lmx = min(l,lmx);
            rmx = max(r,rmx);
        } 
    }
    cout << (rmx-lmx+1) << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
