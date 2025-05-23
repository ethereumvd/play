#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {

    int n, m; cin >> n >> m;
    vector<int> x(n);
    for(int &i:x) cin >> i;

    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    if(x[0] == 0) 
        for(int j=1; j<=m; j++) dp[0][j] = 1;
    else 
        dp[0][x[0]] = 1;

    auto valid = [&] (int i) -> bool {
        if(i >= 1 && i <= m) return true;
        return false;
    };

    for(int i=1; i<n; i++) {
        if(x[i] != 0) {
            for(int di=-1; di<=1; di++) 
                if(valid(x[i]+di)) 
                    dp[i][x[i]] =  (dp[i][x[i]] + dp[i-1][x[i] + di])%mod;
        } else {
            for(int k=1; k<=m; k++) {
                for(int dk=-1; dk<=1; dk++) 
                    if(valid(k+dk)) 
                        dp[i][k] = (dp[i][k] + dp[i-1][k+dk])%mod;
            }
        }
    }
    int sm = 0;
    for(int j=1; j<=m; j++)
        sm = (sm + dp[n-1][j]) % mod;
    cout << sm ;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
