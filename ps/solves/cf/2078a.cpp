#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, x; cin >> n >> x;
    int sm = 0;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        sm += a;
    }
    if((sm%n==0) && (sm/n==x)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
