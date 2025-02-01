#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
int n, m;
int a[mxN], b[mxN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    multiset<int> st(b, b + n);
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (st.find(a[i]) != st.end()) {
            st.erase(st.find(a[i]));
        }
    }

    for (auto it : st) {
        c.emplace_back(it);
    }

    multiset<int> d(c.begin(), c.end());

    
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}