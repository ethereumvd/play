#include<bits/stdc++.h>
using namespace std;
void solve(){
    int k; string m; cin >> k >> m;
    
    string x(k, '0');
    string y(k, '0');

    x[0] = '1';
    y[0] = '1';

    for (int j = 1; j < k; ++j) {
        if (m[j] == '0') {
            x[j] = '0';
            y[j] = '0';
        } else if (m[j] == '1') {
            x[j] = '1';
            y[j] = '0'; 
        } else if (m[j] == '2') {
            if (x[j - 1] == '1' && y[j - 1] == '1') {
                x[j] = '1';
                y[j] = '1';
            } else {
                x[j] = '0';
                y[j] = '2';
            }
        }
    }
    cout << x << endl;
    cout << y << endl;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}

