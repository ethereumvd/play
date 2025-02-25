#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), dp(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];

        dp[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = dp[i + 1] + 1;
            int j = i + a[i] + 1;
            if (j == n + 1) {
                dp[i] = 0;
            } else if (j <= n) {
                dp[i] = min(dp[i], dp[j]);
            }
        }

        cout << dp[1] << "\n";
    }
}