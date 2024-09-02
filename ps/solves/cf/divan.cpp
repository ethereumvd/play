#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i=a;i<n;i+=b)
using ll = long long ;
using namespace std;
void divan_project()
{
    int n ; cin >> n ;
    vector<pair<int,int>> visits ;
    loop(i,1,n+1,1)
    {
        int a ; cin >> a ;
        visits.push_back({a,i}) ;
    }
    sort(visits.rbegin(),visits.rend()) ;
    
    vector<int> cords(n+1) ;
    cords[0] = 0 ;
    int cord_shift = 1 ;
    loop(i,0,n,1)
    {
        if((i&1)==0)
        {
            cords[visits[i].second] = cord_shift ;
        }
        else 
        {
            cords[visits[i].second] = -cord_shift ;
            cord_shift++;
        }
    }

    ll mint = 0 ;
    loop(i,0,n,1)
    {
        mint += 2LL * abs(cords[visits[i].second]) * visits[i].first  ;
    }
    cout << mint << "\n" ;
    loop(i,0,n+1,1) cout << cords[i] << " " ;
    cout << "\n" ;

}
int main()
{
    int tt ;  cin >> tt ;
    while(tt--) divan_project() ;
}
