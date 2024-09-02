#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i=a;i<n;i+=b)
using namespace std;
int main()
{
    int n ; cin >> n ;
    vector<int> a(n) ;
    loop(i,0,n,1) cin >> a[i] ;

    sort(a.begin(),a.end());

    loop(i,0,n,1) cout << a[i] << " " ;
}
