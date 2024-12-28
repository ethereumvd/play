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
    ll sum = 0;
    fra(i,0,n,1) {
        int a ; cin >> a ;
        sum += a ;
    }
    sum % n == 0 ? cout << "YES" << endl : cout << "NO" << endl ;


}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
