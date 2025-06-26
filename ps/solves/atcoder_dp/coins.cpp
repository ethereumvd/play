#include<bits/stdc++.h>
using namespace std;

double f(int i, int heads, int n, vector<double>& p, vector<vector<double>>& dp) {
    if(heads > n/2 && i == n) {
        return 1;
    }
    if(i >= n) return 0;
    if(dp[i][heads] != -1) return dp[i][heads];

    double takeheads = p[i] * f(i + 1, heads + 1, n, p, dp);
    double taketails = (1 - p[i]) * f(i + 1, heads, n, p, dp);

    return dp[i][heads] = takeheads + taketails;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    vector<double> prob(N);
    for(auto& i : prob) cin >> i;

    vector<vector<double>> dp(N, vector<double>(N + 1, -1));

    double ans = f(0, 0, N, prob, dp);
    cout << fixed << setprecision(10) << ans ;
}