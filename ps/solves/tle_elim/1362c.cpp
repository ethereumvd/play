#include<bits/stdc++.h>
using namespace std;
#define int long long 
//wow observation
void jogo() {
    int n; cin >> n;
    int ans = 0;
    while(n>0) {
        ans += n;
        n >>= 1;
    }
    cout << ans << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
