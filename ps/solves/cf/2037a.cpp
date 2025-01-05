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
    int n;
    cin >> n;
    vector<int> a(n);
    fra(i, 0, n, 1) cin >> a[i];

    vector<int> freq(n + 1, 0);
    fra(i, 0, n, 1) freq[a[i]]++;

    int result = 0;
    fra(x, 0, n + 1, 1) result += freq[x] / 2;

    cout << result << endl;

}
int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
