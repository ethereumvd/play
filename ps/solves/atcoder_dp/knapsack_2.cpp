#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, W; cin >> N >> W;
    vector<int> weights(N), values(N);
    for(int i = 0; i < N; i++) cin >> weights[i] >> values[i];
    int mxval = accumulate(values.begin(), values.end(), 0LL);

    vector<int> dp(mxval + 1, INT_MAX);
    //dp[i] will be min weight I must have to acheive value i
    dp[0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = mxval; j >= 0; j--) {
            if(dp[j] != INT_MAX && j + values[i] <= mxval) {
                dp[j + values[i]] = min(dp[j + values[i]], dp[j] + weights[i]);
            }
        }
    }

    for(int i = mxval; i >= 0; i--) {
        if(dp[i] <= W) {
            cout << i;
            break;
        }
    }
}