#include<bits/stdc++.h>
using namespace std;
void decp(int x, map<int,int> &mp) {
    if(x <= 1) return;

    //really ?
    //f sqrt()
    for(int i=2; i*i<=x; i++) {
        while(x % i == 0) {
            mp[i]++;
            x /= i;
        }
    }
    if(x > 1) mp[x]++;
}
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    map<int,int> mp;
    for(int i=0; i<n; i++) {
        decp(a[i],mp);
    }

    bool flag = true;
    for(auto &[p,c]:mp) {
        if(c%n!=0) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
