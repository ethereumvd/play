#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// naive recursion + memoization way 
// int f(int idx, int sm, vector<int> &c, vector<vector<int>> &dp) {
//     if(sm == 0) return 1;
//     if(idx == 0) {
//         if(sm % c[0] == 0) return 1;
//         return 0;
//     }
//     if(dp[idx][sm] != -1) return dp[idx][sm];
//     int nottake = f(idx-1, sm, c, dp);
//     int take = 0;
//     if(c[idx] <= sm) {
//         take = f(idx, sm-c[idx], c, dp);
//     }
//     return dp[idx][sm] = take + nottake;
// }

void solve() {
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(int &i:c) cin >> i;
    // tabulation form of the given recursive way :- 
    
    vector<vector<int>> dp(n, vector<int>(x+1, 0)); 
    dp[0][0] = 1;
    for(int j=1; j<=x; j++) {
        if(j % c[0] == 0) dp[0][j] = 1;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<=x; j++) {
            int nottake = dp[i-1][j];
            int take = 0;
            if(j >= c[i]) {
                take = dp[i][j-c[i]] ;
            }
            dp[i][j] = (take + nottake) % mod;
        }
    }
    cout << dp[n-1][x];
    
    //space optimisation :-
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
