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
    int n ,d ; cin >> n >> d ;
    set<int> ans ;
    ans.insert(1) ;
    if(d%3==0) ans.insert(3) ;
    if(d%5==0) ans.insert(5) ;
    if(d%7==0) ans.insert(7) ;
    if(d%9==0) ans.insert(9) ;

    if(n>=3) {
        ans.insert(3) ;
        if(n>=6) {
            ans.insert(9) ;
        }
    }
    
    if(n>=3 || (n==2)&&(d==7)) {
        ans.insert(7) ;
    } 
    else{
        int sum = 1;
        for (int i = 2; i <= n; i++)
        {
            sum = sum * i;
            if (((sum * d) % 9) == 0)
            {
                ans.insert(9);
                break;
            }
        }
    }

    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
