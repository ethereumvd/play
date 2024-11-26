#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
void solve()
{
    int n , k , a , b ;
    cin >> n >> k >> a >> b ;
    vector<ll> x(n) , y(n) ;
    fra(i,0,n,1) cin >> x[i] >> y[i] ;

    ll min_a = LLONG_MAX / 2 ; 
    ll min_b = LLONG_MAX / 2 ;

    fra(i,0,k,1)
    {
        min_a = min( min_a , abs(x[i] - x[a-1]) + abs(y[i] - y[a-1]) );
        min_b = min( min_b , abs(x[i] - x[b-1]) + abs(y[i] - y[b-1]) );
    }
    
    ll ans = abs(x[a-1] - x[b-1]) + abs(y[a-1] - y[b-1]) ;
 
    ans = min(ans , min_a + min_b) ;
    cout << ans << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) solve() ;
} 
