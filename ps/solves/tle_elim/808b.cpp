#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    int sm = 0;
    for(int i=1; i<=k; i++) sm += a[i];

    int wsm = sm;
    for(int i=k; i<n; i++) {
        wsm += a[i+1] - a[i-k+1];
        sm += wsm;
    }

    double ans = static_cast<double>(sm) / (n-k+1);
    cout << fixed << setprecision(6) << ans ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
