#include<bits/stdc++.h>
using namespace std;

int fibo(int n, vector<int> &dp) {

    if(dp[n] != -1) return dp[n];

    return fibo(n-1, dp) + fibo(n-2, dp);

}

int main() {
    int n; cin >> n;
    vector<int> dp(n + 1,-1);
    dp[0] = 0;
    dp[1] = 1;
    cout << fibo(n, dp);
}
