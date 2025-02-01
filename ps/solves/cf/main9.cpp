#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
const int inf = 2e9;
int n, a[mxN];

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> b;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (mp[a[i]] >= 2) b.emplace_back(a[i]);
        }

        if (b.empty()) {
            cout << "-1\n";
            continue;
        }

        int max_b = *max_element(b.begin(), b.end());
        mp[max_b] -= 2;
        vector<int> rem;
        for (int i = 0; i < n; i++) {
            if (mp[a[i]]) {
                rem.emplace_back(a[i]);
            }
        }

        sort(rem.begin(), rem.end());
        int min_diff = inf;
        int x = -1, y = -1;
        for (int i = 0; i + 1 < rem.size(); i++) {
            if (rem[i + 1] - rem[i] < min_diff) {
                x = rem[i + 1], y = rem[i];
                min_diff = x - y;
            }
        }


        if (min_diff <= 2*max_b) {
            // cout << "YES" << "\n";
            cout << x << " " << y << " " << max_b << " " << max_b << "\n";
        } else {
            // cout << "NO" << "\n";
            cout << "-1\n";
        }
    }
}