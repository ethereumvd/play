#include<bits/stdc++.h>
using namespace std;
#define int long long
int stidx(int idx, int k) {
    if(idx<=k) {
        return idx*(idx + 1)/2;
    } else {
        int sm = k*(k+1)/2;
        int ex = idx - k;
        return (sm + ex*k - (ex*(ex+1)/2));
    }
}
void jogo() {
    int k, x ; cin >> k >> x;

    if(x > k*k) cout << 2*k - 1 << "\n";
    else { 
        int l = 1, r = 2*k - 1;
        int ans = 1;
        while(l <= r) {
            int mid = r - (r - l)/2 ;
            int sm = stidx(mid,k);
            if(sm < x) l = mid + 1;
            else if (sm >= x) {
                ans = mid ;
                r = mid - 1;
            } 
        }
        cout << ans << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
