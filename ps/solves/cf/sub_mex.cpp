#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i=a;i<n;i+=b)
using namespace std;
void subset_mex()
{
    int n ; cin >> n ;
    vector<int> a(n) ;
    loop(i,0,n,1) cin >> a[i] ;

    vector<int> cnt(101,0) ;
    int mex_a = 0 , mex_b = 0 ;

    loop(i,0,n,1) 
    {
        if(a[i]<101) 
        {
            cnt[a[i]]++ ;
        }
    }

    loop(i,0,101,1)
    {
        if(cnt[i]==0)
        {
            mex_a =  i ;
            break ;
        }
        else 
        {
            cnt[i]-- ;
            continue ;
        }
    }
    loop(i,0,101,1)
    {
        if(cnt[i]==0)
        {
            mex_b = i ;
            break ;
        }
    }
    int ans = mex_a + mex_b ;
    cout << ans << "\n" ;
}
int main()
{
    int tt ; cin >> tt ;
    while(tt--) subset_mex() ;
}
