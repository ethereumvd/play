#include<bits/stdc++.h>
#define loop(i,n) for(int i =0 ;i<n;i++)
using namespace std;
void even_array()
{
    int n ; cin >> n ;
    vector<int> a(n) ;
    loop(i,n) cin >> a[i] ;

    int even_pos_mismatch = 0 ;
    int odd_pos_mismatch = 0 ;
    loop(i,n)
    {
        if(i%2==0 && (a[i]-i)%2!=0)
        {
            even_pos_mismatch++;
        }
        else if (i%2!=0 && (a[i]-i)%2!=0)
        {
            odd_pos_mismatch++;
        }
    }
    if(odd_pos_mismatch!=even_pos_mismatch) cout << -1 << "\n" ;
    else cout << even_pos_mismatch << "\n" ;
}
int main()
{
    int tt ; cin >> tt ;
    while(tt--) even_array() ;
}
