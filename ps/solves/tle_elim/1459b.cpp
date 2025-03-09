#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    if(n % 2 == 0) cout << 1ll*(n/2 + 1)*(n/2 +1) << "\n";
    else cout << 1ll*(n + 3)*(n + 1)/2<< "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
