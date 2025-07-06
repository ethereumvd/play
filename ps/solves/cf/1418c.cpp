#include<bits/stdc++.h>
using namespace std;
int N;
const int inf = 1e8;
unordered_map<int, unordered_map<bool, int>> memo;

int dp(int i, bool myturn, vector<int>& a) {
    if(i >= N) return 0;
    if(memo[i].count(myturn)) return memo[i][myturn];

    int move1 = inf, move2 = inf;
    if(myturn) {
        move1 = dp(i + 1, false, a);
        move2 = dp(i + 2, false, a);
    } else {
        move1 = a[i] + dp(i + 1, true, a);
        if(i < N - 1) move2 = a[i] + a[i + 1] + dp(i + 2, true, a);
    }

    return memo[i][myturn] = min(move1, move2);
}

void solve() {
    memo.clear();
    cin >> N;
    vector<int> a(N);
    for(auto& i : a) cin >> i;

    cout << dp(0, false, a) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) solve();
}