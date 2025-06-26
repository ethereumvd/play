#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, W; cin >> N >> W;
    vector<int> weights(N), values(N);
    for(int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(W + 1, vector<int>(N + 1, -1));

    auto f = [&](int currweight, int idx, auto&& f) -> int {
        if(idx == N) return 0;
        if(dp[currweight][idx] != -1) return dp[currweight][idx];

        int nottake = f(currweight, idx + 1, f);
        int take = INT_MIN;

        if(weights[idx] <= currweight) {
            take = values[idx] + f(currweight - weights[idx], idx + 1, f);
        }

        return dp[currweight][idx] = max(take, nottake);
    };

    int ans = f(W, 0, f);
    cout << ans ;
}