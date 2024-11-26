#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve()
{
    ll p1 ; cin >> p1;
    ll p2 ; cin >> p2;
    vector<ll> a(p1) ;
    for(int k=0;k<p1;k++){
        cin >> a[k]  ;
    }
    vector<ll> d(p2) ; vector<ll> g(p2);
    vector<ll> ans(p1)={0};
    for(int i =0;i<p2;i++)
    {
        cin >> d[i] >> g[i];

    }
    for(int l=0;l<p1;l++)
    {
        for(int m =0;m<p2;l++)
        {
            if(a[l]>=d[m])
            {
                ans[l]+=g[m];
            }
        }
    }
    for(int n=0;n<p1;n++)
    {
        cout << ans[n];
    }
}
int main()
{
        solve();
}
