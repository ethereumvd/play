#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[151][151];
int ans[2001];

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                ans[a[i][j]] = i;
            }
        }

        bool ok = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[j] != ans[i*n + j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) {
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << " ";
            }
        } else cout << "-1";
        cout << "\n";
    }
}