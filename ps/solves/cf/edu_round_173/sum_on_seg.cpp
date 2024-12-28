#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define frb(i,n,a,b) for(int i=n;i>=a;i-=b) 
#define is_odd(x) ((x)%2!=0)
#define is_even(x) ((x)%2==0)
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define printv(v,n) fra(i,0,n,1) cout << v[i] 
#define sortv(a) sort(a.begin(), a.end())
#define revv(a) reverse(a.begin(), a.end())
#define endl "\n" 
#define debug(x) cout << x << endl ;
const int mod = 1e9 + 7 ; 
int mx_sub_sum(vector<int> v, int s , int e) {
    int mx = 0 ; int sum = 0 ;
    fra(i,s,e,1) {
        if(sum<0) sum = 0 ;
        sum += v[i] ;
        mx = max(mx,sum) ;
    }
    return mx ;
}
int mn_sub_sum(vector<int> v , int s , int e) {
    int mn = 0 ; int sum = 0 ;
    fra(i,s,e,1) {
        if(sum>0) sum = 0 ;
        sum+=v[i] ;
        mn = min(mn,sum) ;
    }
    return mn ;
}
void pookie_bear()
{
    int n ; cin >> n ;
    vector<int> a(n) ; scanv(a,n) ;

    set<int> ans ; int idx = -1 ;
    fra(i,0,n,1) {
        if(a[i]!=1 && a[i]!=-1) {
            idx = i ;
            break ;
        }
    }

    if(idx==-1){
        int mx = mx_sub_sum(a,0,n) ;
        int mn = mn_sub_sum(a,0,n) ;
        fra(i,mn,mx+1,1) ans.insert(i) ;
    } else {
        int mx_l = mx_sub_sum(a,0,idx) ;
        int mn_l = mn_sub_sum(a,0,idx) ;
        int mx_r = mx_sub_sum(a,idx+1,n) ;
        int mn_r = mn_sub_sum(a,idx+1,n) ;
        fra(i,mn_l,mx_l+1,1) ans.insert(i) ;
        fra(i,mn_r,mx_r+1,1) ans.insert(i) ;

        int mx_suff = 0 ; int mn_suff = 0;
        int curr = 0 ;
        frb(i,idx-1,0,1) {
            curr += a[i] ;
            mx_suff = max(curr,mx_suff) ;
            mn_suff = min(curr,mn_suff) ;
        }

        curr = 0 ;
        int mx_pref = 0 ; int mn_pref = 0;
        fra(i,idx+1,n,1) {
            curr+=a[i] ;
            mx_pref = max(mx_pref , curr) ;
            mn_pref = min(mn_pref , curr) ;
        }

        int mx = mx_pref + mx_suff + a[idx] ;
        int mn = mn_pref + mn_suff + a[idx] ;
        fra(i,mn,mx+1,1) ans.insert(i) ;
    }

    cout << ans.size() << endl ;
    for(auto i : ans) cout << i << " " ;
    cout << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
