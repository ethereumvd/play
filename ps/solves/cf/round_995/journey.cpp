#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    ll n , a, b, c ;
    cin >> n >> a >> b >> c ;
    ll tot = a+b+c ;
    ll cycles = n / tot ;
    ll remain = n % tot ;

    ll days = cycles *3 ;
    ll sum = n - remain ;

    if(remain>0) {
        vector<ll> dist = {a ,b , c} ;
        fra(i,0,3,1) {
            sum+=dist[i] ;
            days++ ;
            if(sum>=n) break ;
        }
    }
    cout << days << endl ;

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
