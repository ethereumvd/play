#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<pair<int,int>> ans;
    ans.reserve(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                ans.emplace_back(make_pair(a[j], a[i]));
                ans.emplace_back(make_pair(a[i], a[j]));
            } else {
                ans.emplace_back(make_pair(a[i], a[j]));
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}