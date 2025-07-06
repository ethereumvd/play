#include<bits/stdc++.h>
using namespace std;
int N, K;
const int mod = 1e9 + 7;
unordered_map<int, unordered_map<int, int>> dp;

//recursive + memoization => gives TLE
int f(int i, int leftCandies, vector<int>& A) {
    if(leftCandies < 0) return 0;
    if(i == A.size()) return leftCandies == 0 ? 1 : 0;
    if(dp[i].count(leftCandies)) return dp[i][leftCandies];

    int res = 0;
    for(int j = 0; j <= A[i]; j++) {
        res = (res + f(i + 1, leftCandies - j, A)) % mod;
    }
    return dp[i][leftCandies] = res % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    vector<int> A(N);
    for(auto& i : A) cin >> i;

    vector<vector<int>> dp(N, vector<int>(K + 1, 0));
    //dp[i][j] is num of ways we can give j candies till ith child
    for(int i = 0; i < N; i++) dp[i][0] = 1;
    for(int j = 0; j <= A[0]; j++) dp[0][j] = 1;

    for(int i = 1; i < N; i++) {
        for(int k = 1; k <= K; k++) {
            for(int j = 0 ; j <= min(k, A[i]); j++) {
                dp[i][k] += dp[i-1][k - j];
            }
        }
    }

    cout << dp[N-1][K];
}