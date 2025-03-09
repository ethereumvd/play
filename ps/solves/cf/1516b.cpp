#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n ; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> pref(n);
    pref[0]=a[0];
    for(int i=1; i<n; i++) {
        pref[i] = a[i]^pref[i-1] ;
    }

    if(pref[n-1]==0) {
        cout << "YES" << "\n";
        return;
    }

    bool flag = false;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(pref[i]==(pref[i]^pref[j]) && (pref[i])==(pref[n-1]^pref[j])){
                flag = true;
                break;
            } 
            if(flag) break;
        }
    }

    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
