#include<bits/stdc++.h>
using namespace std;
#define int long long //f off
int gcdd(int a,int b) {
    if(b<a) swap(a,b);
    while(a!=0) {
        b %= a;
        swap(a,b);
    }
    return b;
}
void jogo() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    map<pair<int,int>,int> mp;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(a[i]==0) {
            if(b[i]==0) ans++;
            continue;
        }else {
            int g = gcdd(abs(a[i]),abs(b[i]));
            if(a[i]*b[i] > 0) mp[{abs(a[i]/g),abs(b[i]/g)}]++;
            else mp[{-abs(a[i]/g),abs(b[i]/g)}]++;
        }
    }

    if(mp.empty()) cout << ans << "\n";
    else {
        int mx = INT_MIN;
        for(auto i:mp) {
            mx = max(i.second,mx);
        }
        cout << mx+ans << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
