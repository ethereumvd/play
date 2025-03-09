#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m = 998244353;
//somewhere this will die either due to mod or long long
void jogo() {
    string s ; cin >> s;
    int n = s.size();

    vector<int> a;
    for(int i=0; i<n; i++) {
        if(s[i]=='1') {
            int ai = 0;
            while(s[i]!='0'&& i<n) {
                ai++;
                i++;
            }
            i--;
            a.emplace_back(ai);
        } else {
            int ai = 0;
            while(s[i]!='1' && i<n) {
                ai++;
                i++;
            }
            i--;
            a.emplace_back(ai);
        }
    }
    int an = a.size();
    int op = n - an;

    int t1 = 1;
    for(int i=0; i<an; i++) t1 = (t1 * a[i]) % m;

    int t2 = 1;
    for(int i=2; i<=op; i++) t2 = (t2 * i) % m;

    cout << op << " " << (t1*t2)%m << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
