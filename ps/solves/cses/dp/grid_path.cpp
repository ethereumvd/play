#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

void solve() {
    int n ; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n,'.'));
    for(auto &v:grid) 
        for(auto &ch:v ) 
            cin >> ch;

    vector<vector<int>> dp(n, vector<int>(n,0));
    dp[0][0] = grid[0][0] == '.' ? 1 : 0 ;

    int di[] = {1, 0};
    int dj[] = {0, 1};

    auto valid = [&](int i, int j) -> bool {
        if(i >= 0 && i < n && j >= 0 && j < n) return true;
        return false;
    };

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<2; k++) {
                int nxi = i+di[k];
                int nxj = j+dj[k];
                if(valid(nxi, nxj)) {
                    if(grid[nxi][nxj] == '*') {
                        dp[nxi][nxj] = 0;
                        continue;
                    }
                    dp[nxi][nxj] = (dp[nxi][nxj] + dp[i][j]);
                    dp[nxi][nxj] %= mod;
                }
            }
        }
    }

    cout << dp[n-1][n-1] ;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
