#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int H, W; cin >> H >> W;
    vector<vector<char>> mat(H, vector<char>(W, '.'));
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            cin >> mat[i][j];

    vector<vector<int>> dp(H, vector<int>(W, 0));
    dp[0][0] = 1;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i + 1 < H) {
                if (mat[i+1][j] == '.') {
                    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
                }
            }
            if(j + 1 < W) {
                if(mat[i][j+1] == '.') {
                    dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
                }
            }
        }
    }

    cout << dp[H-1][W-1];
}