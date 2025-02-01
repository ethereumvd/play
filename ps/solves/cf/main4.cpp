#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> st;

void init() {
    for (ll k = 2; k < 1'000'000; k++) {
        ll s = k*k*k + k*k + k + 1;
        st.insert(s);
        while (s < (1e18 / k)) {
            s = k*s + 1;
            st.insert(s);
        }
    }
}

void solve() {
    ll n;
    cin >> n;

    ll m = 4*n - 3;
    ll sqrt_m = sqrtl(m);
    if (sqrt_m * sqrt_m == m) {
        if (n == 1 || n == 3) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }

    if (st.find(n) != st.end()) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    init();
    while (t--) {
        solve();
    }
}