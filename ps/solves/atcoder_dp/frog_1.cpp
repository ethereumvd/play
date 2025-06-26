#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> heights(N);
    for(auto& i : heights) cin >> i;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(heights[1] -heights[0]);

    for(int i = 2; i < N; i++) {
        dp[i] = min(dp[i], dp[i-1] + abs(heights[i-1] - heights[i]));
        dp[i] = min(dp[i], dp[i-2] + abs(heights[i-2] - heights[i]));
    }

    cout << dp[N-1];
}