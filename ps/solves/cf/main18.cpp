#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cnt = 0;
    vector<int> b;
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i] & 1) cnt++;
        else cnt--;
        if (cnt == 0) {
            b.emplace_back(abs(a[i + 1] - a[i]));
        }
    }

    if (b.empty()) {
        cout << "0\n";
        return 0;
    }

    cout << ans << "\n";
}