#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n;
    k = -1;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            k = i - 1;
            break;
        }
    }
    if (k == -1) {
        cout << 1 << " " << n - 1 << "\n";
    } else {
        int a = n / (k + 1);
        int b = k * a;
        cout << a << " " << b << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
