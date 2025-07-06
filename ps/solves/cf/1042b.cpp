#include<bits/stdc++.h>
using namespace std;
int N;

unordered_map<int, unordered_map<int, int>> memo;

long long f(int i, int mask, vector<tuple<int, int>>& vitamins) {
    if(i >= N) return mask == 7 ? 0 : 1e9;
    if(mask == 7) return 0;
    if(memo[i].count(mask)) return memo[i][mask];

    auto [cst, mmask] = vitamins[i];
    int nottake = f(i + 1, mask, vitamins);
    int take = cst + f(i + 1, mask | mmask, vitamins);

    return memo[i][mask] = min(take, nottake);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n ;
    cin >> n;
    N = n;
    vector<tuple<int, int>> vitamins(n);

    for(int i = 0; i < n; i++) {
        int cost ; cin >> cost;
        string s; cin >> s;
        int mask = 0;
        for(auto& ch : s) mask |= (1 << ch - 'A');
        vitamins[i] = {cost, mask};
    }

    long long ans = f(0, 0, vitamins);
    if(ans > 1e8) cout << -1 ;
    else cout << ans ;

}