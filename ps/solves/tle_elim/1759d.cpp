#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n, m; 
    cin >> n >> m;
    int tn = n;
    int cf = 0, ct = 0;

    while (tn % 5 == 0) {
        cf++;
        tn /= 5;
    }
    while (tn % 2 == 0) {
        ct++;
        tn /= 2;
    }

    int k = 1;
    
    while (ct < cf && k * 2 <= m) {
        k *= 2;
        ct++;
    }
    while (cf < ct && k * 5 <= m) {
        k *= 5;
        cf++;
    }

    while (k * 10 <= m) {
        k *= 10;
    }
    k *= (m / k);

    cout << n * k << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) jogo();
    return 0;
}

