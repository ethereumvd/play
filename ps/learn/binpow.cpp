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
int32_t main() {
    int a , n ; 
    cin >> a >> n ;
    int pow = binpow(a,n);

    cout << pow << "\n";
}
