#include <bits/stdc++.h>
using namespace std;

void jogo() {
    string s; 
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i] && (i + 2 >= n || c != s[i + 2])) {
                    s[i + 1] = c;
                    break;
                }
            }
        }
    }
    cout << s << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while (tc--) jogo();
    return 0;
}
