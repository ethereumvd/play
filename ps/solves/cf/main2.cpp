#include <bits/stdc++.h>
using namespace std;

int n;
const int mxN = 1e5 + 5;
vector<int> c[mxN];

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        c[i].clear();
        int x;
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            c[i].emplace_back(y);
            mp[y]++;
        }
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < c[i].size(); j++) {
            if (mp[c[i][j]] < 2) {
                flag = false;
                break;
            }
        }
        if (flag) {
            found = true;
            break;
        }
    }

    cout << (found ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}