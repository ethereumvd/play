#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<char>> forest(n + 1, vector<char>(n + 1));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> forest[i][j];
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = (forest[i][j] == '*') + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }

    for (int i = 0; i < q; i++) {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;  // input is (row1, col1, row2, col2)
      int ans = dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1];
      cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
