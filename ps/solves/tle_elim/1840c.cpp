#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define frb(i,a,n,b) for(int i=n;i>=0;i-=b) 
#define is_odd(x) ((x)%2!=0)
#define is_even(x) ((x)%2==0)
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define printv(v,n) fra(i,0,n,1) cout << v[i] 
#define sortv(a) sort(a.begin(), a.end())
#define revv(a) reverse(a.begin(), a.end())
#define endl "\n" 
#define debug(x) cout << x << endl 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    ll n , k, q ; cin >> n >> k >> q;
    vector<ll> a(n) ; scanv(a,n) ;

    ll x = 0 ; ll ans = 0 ;
    fra(i,0,n,1) {
        if(a[i]<=q) x++ ;
        else {
            if(x>=k) {
                ans += (x-k+1)*(x-k+2) / 2 ;
            }
            x = 0 ;
            continue ;
        }
    }
    if(x>=k) ans += (x-k+1)*(x-k+2) / 2 ;
    cout << ans << endl  ;
}
int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
