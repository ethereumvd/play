#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, maxw; cin >> n >> maxw;
    vector<int> w(n) , v(n); 
    for(int i=0; i<n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(maxw+1, 0));

    //dp state is dp[i][j] i->idx, j ->wt
    //maximum weight can get till i 
    //carying a weight of j at that point

    for(int j = w[0]; j<= maxw; j++) dp[0][j] = v[0];

    for(int i=1; i<n; i++) {
        for(int j=0; j<=maxw; j++) {
            int not_take = dp[i-1][j];
            int take = INT_MIN;
            if(j >= w[i]) {
                take = v[i] + dp[i-1][j-w[i]];
            }
            dp[i][j] = max(take, not_take);
        }
    }

    cout << *max_element(dp[n-1].begin(), dp[n-1].end());
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
