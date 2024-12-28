#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    int n ; cin >> n ;
    vector<int> a(n) ; scanv(a,n) ;

    fra(i,0,n,1) {

        if(!a.empty() && (a.front()==0)) {
            a.erase(a.begin()) ;
        }
        if(!a.empty() && (a.back()==0)) {
            a.pop_back() ;
        }
    }

    if(a.empty()) cout << 1 << endl ;
    bool zero_present = false ;
    fra(i,0,a.size(),1) {
        if(a[i] == 0)  {
            zero_present = true ;
            break ;
        }
    }
    zero_present ? cout << 2 << endl  : cout << 1 << endl ;

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
