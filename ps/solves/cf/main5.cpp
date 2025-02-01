#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3, a4, a5;

int get_fib() {
    int cnt = 0;
    if (a3 == a2 + a1) cnt++;
    if (a4 == a3 + a2) cnt++;
    if (a5 == a4 + a3) cnt++;
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> a4 >> a5;

        int ans = 0;
        a3 = a1 + a2;
        ans = max(ans, get_fib());
        a3 = a5 - a4;
        ans = max(ans, get_fib());
        a3 = a4 - a2;
        ans = max(ans, get_fib());
        
        cout << ans << "\n";
    }
}