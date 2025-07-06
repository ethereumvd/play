#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(auto& i : A) cin >> i;
    int mn = *min_element(A.begin(), A.end());

    vector<int> dp(K + 1, 0);
    //dp[i] is can taro win if he starts when height is i
    //0 means taro loses 1 means taro wins

    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < N; j++) {
            if(i >= A[j]) {
                if(dp[i - A[j]] == 0) dp[i] = 1;
            }
        }
        if(i < mn) dp[i] = 0;
    }

    if(dp[K] == 1) cout << "First";
    else cout << "Second";
}