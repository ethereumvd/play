#include<bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_map<int, int>> dp;

int f(int i, int j, vector<int>& A) {
    if(i > j) return 0;
    if(dp[i].count(j)) return dp[i][j];

    int last = A[j] - f(i, j - 1, A);
    int first = A[i] - f(i + 1, j, A);

    return dp[i][j] = max(last, first);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for(auto& i : A) cin >> i;

    cout << f(0, N-1, A);
}