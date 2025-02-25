#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        vector<int> u(k), v(k);
        for (int i = 0; i < k; i++) {
            cin >> u[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }

        vector<int> adj1(a + 1, 0);
        vector<int> adj2(b + 1, 0);
        for (int i = 0; i < k; i++) {
            adj1[u[i]]++;
            adj2[v[i]]++;
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans += k - adj1[u[i]] - adj2[v[i]] + 1;
        }

        cout << ans / 2 << "\n";
    }
}