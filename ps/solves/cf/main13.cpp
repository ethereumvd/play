#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        if (l == 1 && r == 1) {
            cout << "1\n";
            continue;
        }
        cout << r - l << "\n";
    }
}