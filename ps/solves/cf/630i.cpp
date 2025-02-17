#include<bits/stdc++.h>
#define int long long 
using namespace std;
int binpow(int a , int n ) {
    int res = 1 ;
    while(n>0) {
        if(n&1) res *= a ;
        a = a*a ;
        n = n >> 1 ;
    }
    return res ;
}
void jogo() {
    int n ; cin >> n ;
    int ans = (2*3*4*binpow(4,n-3)) + (4*9*binpow(4,n-4)*(n-3)) ;
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ;
    int tc = 1 ; 
    while(tc--) jogo() ;
    return 0;
}
