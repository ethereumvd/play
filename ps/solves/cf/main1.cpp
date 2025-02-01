#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n + 1, vector<char>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        int ans[n + 1];
        iota(ans + 1, ans + n + 1, 1);
        sort(ans + 1, ans + n + 1, [&] (const int &i, const int &j) {
            if ((i < j && a[i][j] == '1') || (i > j && a[i][j] == '0')) return true;
            return false;
        });

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}