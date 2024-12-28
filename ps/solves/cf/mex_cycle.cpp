#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define is_odd(x) ((x)%2!=0)
#define is_even(x) ((x)%2==0)
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define printv(v,n) fra(i,0,n,1) cout << v[i] 
#define sortv(a) sort(a.begin(), a.end())
#define revv(a) reverse(a.begin(), a.end())
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    int n, x, y ; cin >> n >> x >> y ;

    vector<int> ans(n,0) ;

    if(is_even(n)) {
        fra(i,0,n,1) {
            if(is_odd(i)) ans[i] = 1 ;
        }
        if(is_even(y-x)) {
            ans[x-1] = 2 ;
        }
    }
    else {
        fra(i,0,n-1,1) {
            if(is_odd(i)) {
                ans[i] = 1 ;
            }
        }
        ans.insert(ans.begin()+(x-1) , 2) ;
    }
    fra(i,0,n,1) cout << ans[i] << " " ;
    cout << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
