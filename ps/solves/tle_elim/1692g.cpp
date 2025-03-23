#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &i:a) cin >> i;

    if(k==1) {
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            if(a[i] < 2*a[i+1]) {
                ans++;
            }
        }
        cout << ans << "\n";
        return;
    }

    vector<int> mp;
    for(int i=0; i<n-1; i++) {
        if(a[i] >= 2*a[i+1]) {
            mp.push_back(i);
            mp.push_back(i+1);
        }
    }
    /*for(int i:mp) cout << i <<" " ;*/
    /*cout << endl;*/

    int ans = 0;
    int nn = mp.size() ;
    if(nn == 0) ans = n - k;
    else {
        if(mp[0] >= k ) ans += (mp[0] - k + 1);
        if(n-1 - mp[nn-1] >=k ) ans += (n-1 - mp[nn-1] - k + 1);
        for(int i=1; i<nn-2; i++) {
            if(mp[i+1] - mp[i] >= k) {
                ans += (mp[i+1] - mp[i] - k + 1);
            }
        }
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
