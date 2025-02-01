#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> a(k);
    for (int &i : a) cin >> i;

    vector<pair<int, int>> ans;
    for (int i = k - 1; i >= 0; i--) {
        int mod = a[i] % k;
        int z = (k + i - mod) % k;
        if (z != 0) {
            ans.emplace_back(make_pair(i + 1, z));
        }
        for (int j = 0; j < i; j++) {
            a[j] += z;
        }
    }

    cout << ans.size() + 1 << "\n";
    for (auto p : ans) {
        cout << "1 " << p.first << " " << p.second << "\n";
    }

    cout << "2 " << k << " " << k << "\n";
}