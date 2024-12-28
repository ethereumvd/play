#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define printv(v,n) fra(i,0,n,1) cout << v[i] 
#define sortv(a) sort(a.begin(), a.end())
#define revv(a) reverse(a.begin(), a.end())
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{

    int n , k ; cin >> n >> k ;
    vector<int> a(n) ; vector<int> b(n) ;
    scanv(a,n) ; scanv(b,n) ;

    sortv(a) ; sortv(b) ;
    set<int> t(a.begin(),a.end()) ;
    t.insert(b.begin(),b.end()) ;

    ll ans = 0 ;
    for(int it : t) {
        int not_and_neg = lower_bound(a.begin(),a.end(),it) - a.begin() ;
        int not_ = lower_bound(b.begin() ,b.end(),it) - b.begin() ;
        if(not_and_neg - not_<=k) {
            ans = max(ans , 1LL * it * (n-not_)) ;
        }
    }
    cout << ans << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
