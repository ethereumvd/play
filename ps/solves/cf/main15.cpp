#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> l >> r;
        vector<int> a(n);
        for (int &i : a) cin >> i;

        vector<int> b, c, d, f;

        for (int i = 0; i < l - 1; i++) {
            b.emplace_back(a[i]);
        }
        for (int i = l - 1; i < r; i++) {
            c.emplace_back(a[i]);
        }
        for (int i = r; i < n; i++) {
            d.emplace_back(a[i]);
        }

        sort(b.begin(), b.end());
        sort(c.begin(), c.end(), greater<int>());
        sort(d.begin(), d.end());

        f = c;

        int ans = 2e9;

        int i = 0, j = 0;
        while (i < b.size() && j < f.size()) {
            if (b[i] < f[j]) {
                swap(b[i], f[j]);
                i++;
                j++;
            } else break;
        }

        ans = min(ans, accumulate(f.begin(), f.end(), 0LL));

        f = c;
        i = 0, j = 0;
        while (i < d.size() && j < f.size()) {
            if (d[i] < f[j]) {
                swap(d[i], f[j]);
                i++;
                j++;
            } else break;
        }

        ans = min(ans, accumulate(f.begin(), f.end(), 0LL));

        cout << ans << "\n";
    }
}