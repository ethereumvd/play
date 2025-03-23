#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    vector<vector<int>> dp(n,vector<int>(3,INT_MIN));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = 0;

    for(int i=0; i<n-1; i++) {
        dp[i+1][0] = max(dp[i][2] + a[i+1], dp[i][1] + a[i+1]);
        dp[i+1][1] = max(dp[i][2] + b[i+1], dp[i][0] + b[i+1]);
        dp[i+1][2] = max(dp[i][0],dp[i][1]);
    }

    /*cout << dp[n-1][0] << " " << dp[n-1][1] << " " <<  dp[n-1][2] << "\n";*/
    int ans = max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
