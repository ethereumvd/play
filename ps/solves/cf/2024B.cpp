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
    int n; cin >> n;

    vector<int> c(n); scanv(c, n);
    for (auto &x : c) --x;

    vector<int> cnt(n, 0);
    for (auto &x : c) cnt[x]++;

    int exactly1 = 0, morethan1 = 0;
    for (auto &x : cnt) {
        if (x == 1) exactly1++;
        else if (x > 1) morethan1++;
    }

    cout << morethan1 + (exactly1 + 1) / 2 * 2 << endl;

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
