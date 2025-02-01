#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void solve() {
    int n; cin >> n; 
    vi M(n), N(n);
    for(auto &x : M) cin >> x;
    for(auto &x : N) cin >> x;
    int needChanges = 0;
    int pos = -1;
    for(int i=0; i<n; i++) {
        int change = M[i] - N[i];
        if (change<0) {
            needChanges++;
            pos = i;
        }
    }
    if (needChanges > 1) cout << "NO\n";
    else {
        if (pos == -1) {
            cout << "YES\n";
        } else {
            int count = N[pos] - M[pos];
            for(int i=0; i<n; i++) {
                if (i == pos) continue;
                if ((M[i] - N[i]) < count) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
