#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    int n ; cin >> n ;
    vector<int> a(n) ; vector<int> b(n) ;
    scanv(a,n) ; scanv(b,n) ;
    int ans = 0 ;
    int diff = 0 ;
    fra(i,0,n-1,1) {
        diff = a[i] - b[i+1] ;
        if(diff>0) {
            ans += diff ;
        }
    }
    ans+=a[n-1] ;
    cout << ans << endl ;

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
