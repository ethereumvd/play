#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void collatz() {
    ll x, y, k;
    cin >> x >> y >> k;

    while (k > 0) {
        ll qt = (x / y) + 1;

        if (x < y) {
            if (k < y - x) {
                x += k;
                break;
            }
            k -= y - x;
            x = (k % (y - 1)) + 1;
            break;
        } 
        else if (y * qt - x > k) {
            x += k;
            break;
        } 
        else {
            k -= (y * qt - x);
            x = qt;
            while (x % y == 0) x /= y;
        }
    }

    cout << x << "\n";
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        collatz();
    }
}

