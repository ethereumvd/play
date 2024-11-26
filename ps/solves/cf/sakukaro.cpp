#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
void solve()
{
    int n ; cin >> n;
    int pos = 0;
    int move = 1;
    bool saku = true;
    while(true)
    {
        if(saku) pos -= move ;
        else pos += move ;

        if(abs(pos)>n)
        {
            if(saku) cout << "Sakukaro" << "\n" ;
            else cout << "Kosuke" << "\n" ;
            break;
        }
        saku = !saku;
        move += 2;
    }
}
int main()
{
    int tc ; cin >> tc ;
    while(tc--) solve();
}

