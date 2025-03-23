#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    cout << 2 << " " << 1 << " ";

    for(int i=3; i<=n; i++) {
        cout << i << " ";
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
