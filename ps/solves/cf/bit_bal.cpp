#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long b, c, d; cin >> b >> c >> d;
    long long a = 0;  
    bool valid = true; 

    for (int i = 61; i >= 0; i--) {
        long long bit_mask = 1LL << i; 
        bool b_i = (b & bit_mask) != 0; 
        bool c_i = (c & bit_mask) != 0; 
        bool d_i = (d & bit_mask) != 0;

        if (d_i == 0) {
            if (b_i == 1 && c_i == 0) {
                valid = false;
                break;
            } else if (b_i == 0 && c_i == 1) {
                continue;
            } else if (b_i == 0 && c_i == 0) {
                continue;
            } else if (b_i == 1 && c_i == 1) {
                a |= bit_mask;  
            }
        } else {
            if (b_i == 1 && c_i == 1) {
                continue;
            } else if (b_i == 0 && c_i == 0) {
                a |= bit_mask;  
            } else if (b_i == 0 && c_i == 1) {
                valid = false;
                break;
            } else if (b_i == 1 && c_i == 0) {
                a |= bit_mask;  
            }
        }
    }
    if (valid) {
        cout << a << endl;
    } else {
        cout << -1 << endl;
    }
}
int main() {
    int tc; cin >> tc;  
    while (tc--) solve();  
}

