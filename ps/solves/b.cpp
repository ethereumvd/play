#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n; 
    if (n % 2 == 1) 
    {
        cout << n / 2 << " " << n / 2 + 1 << endl;
    } 
    else 
    {
        cout << n / 2 - 1 << " " << n / 2 + 1 << endl;
    }

}
int main() {
    int tc; cin >> tc; 
    while (tc--) solve() ;
}

