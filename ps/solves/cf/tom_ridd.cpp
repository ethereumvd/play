#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ; cin >> n ;
    vector<string> names ;

    while(n--)
    {
        string name ; cin >> name ;

        bool found = false ;

        for(int i =0 ; i<names.size();i++)
        {
            if(names[i]==name) 
            {
                found = true ;
                break ;
            }
            else continue ;
        }
        if (found) cout << "YES" << "\n" ;
        else 
        {
            names.push_back(name) ;
            cout << "NO" << "\n";
        }
    }
}
