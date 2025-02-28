#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, x, idx = 0, q = 0;
    cin >> n >> x;

    for (int i = 0; i < 31; i++) {
        if ((x & (1 << i)) == 0) {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < min(n - 1, (1 << idx)); i++) {
        cout << i << " ";
        q |= i;
    }
    if ((q | (n - 1)) == x) cout << n - 1 << " ";
    else cout << x << " ";

    for (int i = min(n - 1, (1 << idx)) + 1; i < n; i++) {
        cout << x << " ";
    }

    cout << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
