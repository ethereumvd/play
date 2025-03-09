#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    if(n % 2 == 0) cout << n/2 << " " << n/2 << "\n";
    else {
        int a = 1;
        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0) {
                a = n/i;
                break;
            }
        }
        cout << a << " " << n-a << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
