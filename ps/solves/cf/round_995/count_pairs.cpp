#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define sortv(v) sort(v.begin(),v.end())
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{

    ll n , x , y ; cin >> n >> x >> y  ;
    vector<ll> a(n) ; ll sum = 0;
    fra(i,0,n,1) {
        cin >> a[i] ; sum+=a[i] ;
    }
    sortv(a) ;
    ll ans = 0 ;
    fra(i,0,n-1,1) { 

        ll min_j = sum - a[i] - y ;
        ll max_j = sum - a[i] - x ;
        auto up = upper_bound(a.begin()+i+1,a.end(),max_j) ;
        auto low = lower_bound(a.begin()+i+1,a.end(),min_j) ;

        ans += (up - low);
    }
    cout << ans << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
