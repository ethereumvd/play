#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 2e15;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> b, c, d;
        for (int i = 1; i < l; i++) {
            b.emplace_back(a[i]);
        }

        for (int i = l; i <= r; i++) {
            c.emplace_back(a[i]);
        }

        for (int i = r + 1; i <= n; i++) {
            d.emplace_back(a[i]);
        }

        if (!b.empty()) sort(b.begin(), b.end());
        sort(c.begin(), c.end(), greater<int>());
        if (!d.empty()) sort(d.begin(), d.end()); 

        // sort(a.begin() + 1, a.begin() + l);
        // sort(a.begin() + l, a.begin() + r + 1, greater<int>());
        // sort(a.begin() + r + 1, a.end());

        // for (int i = 1; i <= n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";

        int ans = inf;
        int res = 0;

        for (int k = 0; k < c.size(); k++) {
            res += c[k];
        }

        ans = min(ans, res);
        
        res = 0;
        int i = 0, j = 0;

        while (i < b.size() && j < c.size()) {
            if (b[i] < c[j]) {
                res += b[i];
                j++;
                i++;
            } else {
                break;
            }
        }

        for (int k = j; k < c.size(); k++) {
            res += c[k];
        }

        ans = min(ans, res);

        res = 0;
        i = 0, j = 0;
        while (i < d.size() && j < c.size()) {
            if (d[i] < c[j]) {
                res += d[i];
                j++;
                i++;
            } else {
                break;
            }
        }

        for (int k = j; k < c.size(); k++) {
            res += c[k];
        }

        ans = min(ans, res);
        cout << ans << "\n";
    }
}