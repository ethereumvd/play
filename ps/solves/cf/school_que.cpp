#include<bits/stdc++.h>
#define loop(i,n) for(int i=0 ;i<n;i++)
using namespace std;
int main()
{
    int n ; cin >> n ;
    int t ; cin >> t ;

    string s ; cin >> s ;
    
    while(t--)
    {
        loop(i,n-1)
        {
            if(s[i]=='B'&& s[i+1]=='G') 
            {
                swap(s[i],s[i+1]) ;
                i++;
            }
        }
    }

    cout << s ;

}
