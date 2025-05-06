#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin.tie(0);

    int n , x ; cin >> n >> x ;
    vector<int> c(n) ; scanv(c,n) ;
    
    vector<vector<int>> dp(n,vector<int>(x+1,0)) ;
    dp[0][0] = 1 ;


} 

