#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=1; i<=n-1; i++) {
        int a; cin >> a;
        a--;
        adj[a].push_back(i);
    }
    string s; cin >> s;
    vector<bool> col(n);
    for(int i=0; i<n; i++) {
        col[i] = s[i] == 'B' ? false : true ;
    }

    int ans = 0;
    vector<int> bal(n,0);

    function<void(int)> dfs = [&] (int nd) {
        for(auto nx:adj[nd]) {
            dfs(nx);
            bal[nd] += bal[nx];
        }
        bal[nd] += col[nd] ? 1 : -1;
        if(bal[nd] == 0) ans++;
        return;
    };

    dfs(0);
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
