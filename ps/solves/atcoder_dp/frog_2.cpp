#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<int> heights(N);
    for(auto& i : heights) cin >> i;

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);

    for(int i = 2; i < N; i++) {
        for(int j = 1; j <= K; j++) {
            if(i - j >= 0) {
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i-j] - heights[i]));
            }
        }
    }

    cout << dp[N-1];
}