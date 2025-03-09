#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    for(int &i:a) cin >> i ;

    map<pair<int,int>,int> mp;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int mx = a[i] % x;
        int my = a[i] % y;
        ans += mp[{(x - mx)%x,my}];
        mp[{mx,my}]++;
    }
    cout << ans << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
