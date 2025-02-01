#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n ; cin >> n ;
    vector<int> a(n) ;
    for(int &i:a) cin >> i ;

    set<int> freq ;

    int cnt = 0 ;
    for(int i = 0; i < 31 ; i++) {
        for(int k = 0 ; k < n ; k++) {
            if(a[k] & (1 << i)) {
                cnt++;
            }
        }
        freq.insert(cnt) ;
        cnt = 0 ;
    }

    int ans = 0 ;
    for(auto x:freq) {
        ans = gcd(x,ans); 
    }

    //max freq can be n 
    for(int i = 1 ; i <= n ; i++) {
        if(ans%i == 0) cout << i << " " ;
    }
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
