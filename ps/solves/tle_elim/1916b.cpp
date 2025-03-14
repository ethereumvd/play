#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcdd(int a, int b) {
    if(b < a) swap(a,b);
    while(a!=0) {
        b %= a;
        swap(a,b);
    }
    return b;
}
void jogo() {
    int a, b; cin >> a >> b;
    if(b < a) swap(a,b);
    if(b % a == 0) cout << (b*b) / a << "\n";
    else cout << (a*b)/(gcdd(a,b)) << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
