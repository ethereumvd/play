#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string id ; cin >> id ;
    int sum1 = (id[0] - '0') + (id[1] - '0') + (id[2] - '0');
    int sum2 = (id[3] - '0') + (id[4] - '0') + (id[5] - '0');
    if (sum1 == sum2) {
         cout << "YES" << endl;
    } else {
         cout << "NO" << endl;
    }
}
int main()
{
    int tc ; cin >> tc ;
    while(tc--) solve() ;
}
