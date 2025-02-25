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

        vector<int> a(n + 1), dp(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        auto f = [&] (int m) -> vector<int> {
            vector<int> ans;
            ans.emplace_back(1);
            for (int i = 2; i*i <= n; i++) {
                if (m % i == 0) {
                    ans.emplace_back(i);
                    ans.emplace_back(m / i);
                }
            }
            return ans;
        };

        for (int i = 2; i <= n; i++) {
            vector<int> factors = f(i);
            for (auto j : factors) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
}