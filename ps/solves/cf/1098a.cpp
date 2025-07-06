#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<vector<int>> adj(n, vector<int>());

    for(int i = 1; i <= n - 1; i++) {
        int p; cin >> p;
        --p;
        adj[p].push_back(i);
    }
    for(auto& i : vals) cin >> i;

    long long res = 0;
    bool possible = true;

    auto dfs = [&](int nd, int lst_nz, auto&& dfs) -> void {
        int next_nz = vals[nd] == -1 ? lst_nz : vals[nd];
        res += next_nz - lst_nz;

        if(next_nz < lst_nz && nd != 0) possible = false;

        for(auto& ch : adj[nd]) {
            dfs(ch, next_nz, dfs);
        }
    };
    dfs(0, 0, dfs);

    if(!possible) cout << -1;
    else cout << res;
}