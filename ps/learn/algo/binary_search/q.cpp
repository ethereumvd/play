#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s ; cin >> s ;
    int l , r ; 
    l=0;
    r=s.size()-1;
    int ans = -1 ;
    while(l<=r){

        long long mid = l + (r-l)/2 ;
        if(s[mid]=1)
        {
            ans = mid ;
            r = mid -1 ;
        }
        else l = mid +1 ;
    }
    cout << ans ;
}
