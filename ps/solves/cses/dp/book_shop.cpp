#include<bits/stdc++.h>
using namespace std;
//0-1 knapsack
// int dp[1000][100001];

// recursion + memoization still give tle so try tabulation
// int f(int i, int pr_lim, vector<int>& pages, vector<int>& prices) {
//
//     if(i == 0) {
//         if(prices[0] <= pr_lim) return pages[0];
//         return 0;
//     }
//     if(dp[i][pr_lim] != -1) return dp[i][pr_lim];
//
//     int nottake = f(i-1, pr_lim, pages, prices);
//     int take = INT_MIN;
//     if(prices[i] <= pr_lim) {
//         take = pages[i] + f(i-1, pr_lim - prices[i], pages, prices);
//     }
//
//     return dp[i][pr_lim] = max(take, nottake);
// }

void solve() {
    int n , x; cin >> n >> x;
    vector<int> prices(n), pages(n);
    for(int &i:prices) cin >> i;
    for(int &i:pages) cin >> i;
    //normal tabulation way

    // vector<vector<int>> dp(n, vector<int>(x+1, 0));
    //
    // for(int j=0; j<=x; j++) {
    //     if(j >= prices[0]) dp[0][j] = pages[0];
    // }
    //
    // for(int i=1; i<n; i++) {
    //     for(int j=0; j<=x; j++) {
    //         int nottake = dp[i-1][j];
    //         int take = INT_MIN;
    //         if(prices[i] <= j) {
    //             take = pages[i] + dp[i-1][j-prices[i]];
    //         }
    //         dp[i][j] = max(take, nottake);
    //     }
    // }
    // cout << dp[n-1][x];

    //space optimisation
    // vector<int> dp(x+1, 0);
    // for(int i=0; i<n; i++) {
    //     for(int j=1; j<=x; j++) {
    //         if(j >= prices[i]) {
    //             dp[j] = max(dp[j], pages[i] + dp[j-prices[i]]);
    //         }
    //     }
    // }
    // cout << dp[x] ;
    // below code works but above doesnt pls see why
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], pages[i] + dp[j - prices[i]]);
        }
    }
    cout << dp[x];
}

int main()  {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
}
