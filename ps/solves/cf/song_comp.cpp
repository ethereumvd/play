#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i=0;i<n;i+=b)
using namespace std ;
int main()
{
    int n , m ;
    cin >> n >> m ;

    vector<int> a(n) ;
    vector<int> b(n) ;
    loop(i,0,n,1) cin >> a[i] >> b[i] ;

    int sum = 0 ;
    loop(i,0,n,1) sum+=b[i] ;

    if(sum>m) cout << -1 ;



}
