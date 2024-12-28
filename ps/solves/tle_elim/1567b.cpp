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
    int a , b ; cin >> a >> b ;

    int modf = a % 4 ;
    int req ;
    const int a_temp = a ;

    if(modf == 0) req = 0 ;
    else if(modf==1) req = a - 1 ;
    else if(modf ==2) req = 1 ;
    else req = a  ; 

    int target = req ^ b ; 

    if(target==0) cout << a << endl ;
    else {
        if(target==a) cout << a +2 << endl ;
        else cout << a + 1 << endl ;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
