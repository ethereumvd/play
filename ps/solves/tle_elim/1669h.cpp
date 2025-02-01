#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n , k ; cin >> n >> k ;
    vector<int> a(n) ;
    for(int &i:a) cin >> i ;

    vector<int> cnt(31,0) ;

    for(int i = 0 ; i < n ; i++) {
        for(int k = 0 ; k < 31 ; k++) {
            if(a[i] & (1 << k)) {
                cnt[k]++ ;
            } 
        }
    }
    int rem = k ; 
    int ans = 0 ;
    for(int i = 30 ; i>=0 ; i-- ) {
        int req = n - cnt[i] ;

        if(req <= rem) {
            ans += (1 << i) ;
            rem -= req ;
        }
    }
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
