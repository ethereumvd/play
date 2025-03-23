#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i] - (i + 1);
        mp[b[i]] += a[i];
    }

    int ans = -1;
    for(auto i:mp) ans = max(ans,i.second);

    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
