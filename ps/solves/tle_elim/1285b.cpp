#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        s += a[i];
    }

    int sm = 0;
    int mx1 = LONG_MIN;
    for(int i=1; i<n; i++) {
        sm += a[i];
        mx1 = max(mx1,sm);
        if(sm < 0) {
            sm = 0 ;
        }
    }
    sm = 0;
    int mx2 = LONG_MIN;
    for(int i=0; i<n-1; i++) {
        sm += a[i];
        mx2 = max(sm,mx2);
        if(sm < 0) {
            sm = 0;
        }
    }
    int mxs = max(mx1,mx2);

    if(s > mxs) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
