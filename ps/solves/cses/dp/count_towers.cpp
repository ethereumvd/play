#include<bits/stdc++.h>
using namespace std;
#define int long long

const int md = 1e9 + 7;
const int N = 1e6;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<vector<int>> dp(N+1, vector<int>(2, 0));
    dp[1][0] = dp[1][1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % md ;
        dp[i][1] = (2 * dp[i-1][1] + dp[i-1][0]) % md;
    }

    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        cout << (dp[n][1] + dp[n][0])%md << "\n";
    }
}
