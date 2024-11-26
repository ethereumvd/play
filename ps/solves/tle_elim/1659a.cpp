#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
void pookie_bear()
{
    int n , r , b ; cin >> n >> r >> b ;
    fra(i,0,b,1)
    {
        fra(k,0,r/(b+1),1) cout << "R" ;
        cout << "B";
    }
    fra(i,0,r%(b+1),1) cout << "R" ;
    cout << endl ;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
