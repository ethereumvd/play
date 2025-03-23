#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> b(n);
    for(int &i:b) cin >> i;

    vector<int> df(n-1);
    for(int i=0; i<n-1; i++) df[i] = b[i+1] - b[i];
    sort(df.rbegin(),df.rend());

    int ans = b[n-1] - b[0];
    for(int i=0; i<k-1; i++) ans -= df[i];
    ans += k;

    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
