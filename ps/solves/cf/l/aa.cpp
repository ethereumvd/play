#include<bits/stdc++.h>
using namespace std;
void jogo() {
        int n;
        cin >> n;
        int k, p;
        cin >> k >> p;
        int ans = n * p;
        if (-ans <= k && k <= ans)
        {
            k = abs(k);
            if (k % p == 0)
            {
                cout << k / p << endl;
            }
            else
            {
                cout << k / p + 1 << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
