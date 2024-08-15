#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void black_box()
{
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll mx=0;
    for(ll a=1; a<=x; ++a)
    {
        for(ll b=1; b<=y; ++b)
        {
            if(k%(a*b)) continue;
            ll c=k/(a*b);
            if(c<=z && a*b*c==k)
            {
                ll ct=(x-a+1)*(y-b+1)*(z-c+1);
                mx=max(ct,mx);
            }
        }
    }
    cout<<mx<<endl;
}

int main()
{
  int tc ; 
  cin >> tc;
  while(tc--){
    black_box();
  }
}
