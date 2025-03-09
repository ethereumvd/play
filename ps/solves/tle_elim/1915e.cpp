#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    bool flag = false;

    vector<int> pref(n);
    pref[0] = a[0];
    int mul = 1;
    for(int i=1; i<n; i++) {
        mul = i % 2 == 0 ? 1 : -1 ; 
        pref[i] = pref[i-1] + mul*a[i];
        if(pref[i]==0) {
            flag = true;
            break;
        }
    }

    map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[pref[i]]++;
        if(mp[pref[i]]>=2) {
            flag = true;
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
