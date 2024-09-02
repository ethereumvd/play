#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i =a;i<n;i+=b)
using ll = long long ;
using namespace std ;
void three_friends()
{
    ll a,b,c ;
    cin >> a >> b >> c ;
    
    ll min_dist = abs(a - b) + abs(b - c) + abs(c - a) ;

    loop(i,-1,2,1)
    {
        loop(j,-1,2,1)
        {
            loop(k,-1,2,1)
            {
                ll a_new = a + i ;
                ll b_new = b + j ;
                ll c_new = c + k ;
                min_dist =  min(min_dist,abs(a_new -  b_new)+abs(b_new - c_new)+abs(c_new - a_new));
            }
        }
    }
    
    cout << min_dist << "\n" ;
}
int main()
{
    int tt ; cin >> tt ;
    while(tt--) three_friends() ;
}
