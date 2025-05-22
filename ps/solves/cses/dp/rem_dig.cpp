#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=10; i<=n; i++) {
        string s = to_string(i);
        for(auto &ch:s) {
            int dig = (int)(ch - '0');
            if(i < dig) continue;
            dp[i] = min(dp[i], dp[i - dig] + 1);
        }
    }

    cout << dp[n] ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
