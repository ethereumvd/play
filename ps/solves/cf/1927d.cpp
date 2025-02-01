#include<bits/stdc++.h>
#define int long long 
using namespace std;
void jogo() {

    int n ; cin >> n ;
    vector<int> a(n) ;
    for(int &i:a) cin >> i ;
    int q ; cin >> q ;

    vector<int> cr(n,0);
    cr[n-1] = -1 ;
    for(int i = n-1; i > 0 ; i--) {
        if(a[i]==a[i-1]) { 
            cr[i-1] = cr[i];
            continue;
        } else {
            cr[i-1] = i ;
        }
    }

    while(q--) {
        int l , r ; cin >> l >> r ; 
        l-- ; r-- ;

        if(cr[l]>r || cr[l] == -1)  {
            cout << -1 << " " << -1 ;
        } else {
            cout << l + 1  << " " << cr[l] + 1 ;
        }
        cout << "\n" ;
    }
    cout << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
