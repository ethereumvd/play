#include<bits/stdc++.h>
using namespace std;
int n, k;
// unordered_map<int, unordered_map<bool, int>> memo;

//O(n * k) which is bad

// int f(int i, bool used, vector<int>& a, vector<int>& t) {
//     if(i >= n) return 0;
//     if(memo[i].count(used)) return memo[i][used];

//     int notuse = t[i] * a[i] + f(i + 1, used, a, t);
//     int use = INT_MIN;
//     if(!used) {
//         int sm = 0;
//         int id = i;
//         for(; id < min(n, i + k); id++) sm += a[id];
//         use = sm + f(id, true, a, t);
//     }

//     return memo[i][used] = max(use, notuse);
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int n, k;
    cin >> n >> k;
    vector<int> a(n), t(n);
    for(auto& i : a) cin >> i;
    for(auto& i : t) cin >> i;

    int sure = 0;
    for(int i = 0; i < n; i++) if(t[i] == 1) sure += a[i];

    int mxg = 0;
    for(int i = 0; i < k; i++) if(t[i] == 0) mxg += a[i];

    int gain = mxg;
    for(int i = k; i < n; i++) {
        if(t[i] == 0) gain += a[i];
        if(t[i-k] == 0) gain -= a[i-k];
        mxg = max(mxg, gain);
    }

    cout << sure + mxg;
}