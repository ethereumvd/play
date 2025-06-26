#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string S, T; cin >> S >> T;
    int n1 = S.length();
    int n2 = T.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    //dp[i][j] is max lcs length till prefix i of S and j of T

    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(S[i - 1] == T[j - 1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else  {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string lcs = "";
    int i = n1, j = n2;
    while(i > 0 && j > 0) {
        if(S[i-1] == T[j-1]) {
            lcs += S[i - 1];
            i--; j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << lcs;
}