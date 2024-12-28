#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{

    int n , m , k ; 
    cin >> n >> m >> k ;
    vector<ll> a(m) ; scanv(a,m) ;
    vector<ll> q(k) ; scanv(q,k) ;

    vector<bool> ans(m,0)  ;
    unordered_set<ll> known(q.begin(), q.end()) ;

    if(k==n-1){
        fra(i,0,m,1) {
            auto flag = known.find(a[i]);
            if(flag==known.end()) {
                ans[i] = 1;
            }
        }
        fra(i,0,m,1) cout << ans[i] ;
        cout << endl ;
    }
    else{
        if(k<n-1){
            fra(i,0,m,1) cout << 0 ;
            cout << endl ;
        }
        else {
            fra(i,0,m,1) cout << 1 ;
            cout << endl ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
