#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int k, n; cin >> n >> k;
    string s; cin >> s;
    vector<int> avail(26, false);
    for(int i = 0; i < k ; i++) {
        char c; cin >> c;
        avail[c - 'a'] = true;
    }

    int currlen = 0;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        if(avail[s[i] - 'a']) {
            currlen++;
        } else {
            res += 1LL * (currlen) * (currlen + 1) / 2;
            currlen = 0;
        }
    }
    res += 1LL * (currlen) * (currlen + 1) / 2;

    cout << res;
}