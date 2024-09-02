#include <bits/stdc++.h>
#define loop(i, a, n, b) for (int i = a; i < n; i += b)
using namespace std;
void double_string() {
    int n ; cin >> n ;
    vector<string> strings(n) ;
    unordered_set<string> string_set ;

    loop(i, 0, n, 1) 
    {
        cin >> strings[i];
        string_set.insert(strings[i]);
    }

    vector<char> ans(n, '0');

    loop(i, 0, n, 1) 
    {
        string str = strings[i];
        int strlen = str.length();

        loop(j, 1, strlen, 1) 
        {
            string part1 = str.substr(0, j) ;
            string part2 = str.substr(j) ;

            if (string_set.count(part1) && string_set.count(part2)) 
            {
                ans[i] = '1' ;
                break ;
            }
        }
    }

    loop(i,0,n,1) cout << ans[i] ;
    cout << "\n" ;
}
int main() 
{
    int tt ; cin >> tt ;
    while (tt--) double_string() ;
}

