#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> idxs;
    vector<int> ps;
    for(int i=1; i<=n; i++) {
        int a ; cin >> a;
        if(i > a) {
            idxs.push_back(i);
            ps.push_back(a);
        }
    }

    int ans = 0;
    int nn = idxs.size()-1;
    for(int i=nn; i>0; i--) {
        int a = ps[i];

        auto it = lower_bound(idxs.begin(),idxs.end(),a);
        if(it==idxs.begin()) continue;
        it--;

        int k = it - idxs.begin() + 1;
        ans += k ;
    }
    cout << ans << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
