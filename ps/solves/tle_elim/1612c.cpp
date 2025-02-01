#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int k , x ; cin >> k >> x ;

    vector<int> pref(2*k -1) ;

    int help = 0 ;
    int l = 1 ;
    for(int i = 1 ; i<= 2*k - 1 ;i++) {
        if(i <= k ) {
            pref[i] = i + help ;
            help = pref[i] ;
        } else { 
            pref[i] = (k-l) + help ;
            l++ ;
            help  = pref[i] ;
        }
    }

    auto ans = *lower_bound(pref.begin() , pref.end() , x) ;

    cout << ans << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
