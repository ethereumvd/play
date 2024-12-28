#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
void pookie_bear()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> a(n) ;
    int cnt = 0 ;
    fra(i,0,n,1)
    {
        cin >> a[i] ;

        if(!(a[i]&1)) cnt ++ ;

        if(a[i]%k) ans = 0;

        ans = min(ans ,k - a[i]%k) ;
    }
    if(k==4)
    {
        if(cnt>=2) ans = 0 ;
        else if(cnt==1) ans = min(ans,1) ;
        else ans = min(ans ,2) ;
    }
    cout << ans << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
}
