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
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
void pookie_bear()
{
    int n , k ; cin >> n >> k ;
    vector<pair<int,int>> a(n) ;

    int x ;
    fra(i,0,n,1) {
        cin >> x ;
        if(x%k==0) a[i].first = k ;
        else a[i].first = x%k ;
        a[i].second = i+1 ;
    }
    sort(a.begin(),a.end(),comp) ;
    for(auto i : a) {
        cout << i.second << " " ;
    }
    cout << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
