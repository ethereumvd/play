#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
int n, m;
int b[mxN];
multiset<int> a;

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        a.clear();
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(b, b + m);

        bool ok = true;
        for (int i = 0 ; i < m; i++) {
            if (a.find(b[i]) != a.end()) {
                continue;
            }

            if (b[i] & 1) {
                int x = (b[i] - 1) / 2;
                int y = x + 1;
                // cout << x << " " << y << "\n";
                if (a.find(x) != a.end() && a.find(y) != a.end()) {
                    // cout << x << " " << y << "\n";
                    a.erase(a.find(x));
                    a.erase(a.find(y));
                    a.insert(b[i]);
                    continue;
                }
            }

            if (b[i] % 2 == 0) {
                int x = (b[i] / 2);
                if (a.count(x) >= 2) {
                    a.erase(a.find(x));
                    a.erase(a.find(x));
                    a.insert(b[i]);
                    continue;
                }
            }

            ok = false;
            break;
        }

        vector<int> c(a.begin(), a.end());
        sort(c.begin(), c.end());

        // for (int i = 0; i < c.size(); i++) {
        //     cout << c[i] << " ";
        // }

        if (c.size() != m) {
            ok = false;
        } else {
            for (int i = 0; i < m; i++) {
                if (c[i] != b[i]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "Yes" : "No") << "\n";
    }
}