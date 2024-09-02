#include<bits/stdc++.h>
#define loopf(i,a,n,b) for(int i=a;i<n;i+=b)
#define loopb(i,a,n,b) for(int i=a;i>n;i-=b)
using ll = long long ;
using namespace std ;
void cancel_array()
{
    ll n ; cin >> n ;
    vector<ll> a(n) ;
    loopf(i,0,n,1) cin >> a[i] ;

    ll maxsum = INT_MIN ;
    ll suff_sum = 0 ;
    loopb(i,n-1,-1,1)
    {
        suff_sum += a[i] ;
        maxsum = max(suff_sum,maxsum) ;
    }
    cout << maxsum << "\n" ;
}
int main()
{
    ll tt ; cin >> tt ;
    while(tt--) cancel_array() ;
}
