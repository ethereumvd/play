#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 5;
int n, m1, m2;
vector<int> adj1[mxN], adj2[mxN];

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m1 >> m2;

        for (int i = 1; i <= n; i++) {
            adj1[i].clear();
            adj2[i].clear();
        }

        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            adj1[u].emplace_back(v);
            adj1[v].emplace_back(u);
        }

        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            adj2[u].emplace_back(v);
            adj2[v].emplace_back(u);
        }

        // for (int i = 1; i <= n; i++) {
        //     sort(adj1[i].begin(), adj1[i].end());
        //     sort(adj2[i].begin(), adj2[i].end());
        // }

        int ans = 0;

        // for (int i = 1; i <= n; i++) {
        //     vector<int>& adju = adj1[i];
        //     vector<int>& adjv = adj2[i];

        //     int p1 = 0, p2 = 0;
        //     while (p1 < adju.size() && p2 < adjv.size()) {
        //         if (adju[p1] == adjv[p1]) {
        //             p1++;
        //             p2++;
        //         } else if (adju[p1] > adjv[p2]) {
        //             p2++;
        //             ans++;
        //         } else {
        //             p1++;
        //             ans++;
        //         }
        //     }

        //     while (p1 < adju.size()) p1++, ans++;
        //     while (p2 < adjv.size()) p2++, ans++;
        // }

        // cout << ans / 2 << "\n";
    }
}