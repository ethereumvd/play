#include <bits/stdc++.h>
using namespace std;

int n;
int a[200'005];

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                ok = false;
                cout << "NO\n";
                break;
            }
            if (!ok) break;
            a[i + 1] -= a[i];
        }

        if (!ok) continue;
        cout << "YES\n";
    }
}
