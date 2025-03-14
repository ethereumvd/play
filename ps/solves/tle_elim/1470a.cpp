#include<bits/stdc++.h>
using namespace std;
#define int long long
//might have out of bounds shenanigans
void jogo() {
    int n, m; cin >> n >> m;
    vector<int> k(n), c(m);
    for(int i=0; i<n; i++){
        cin >> k[i];
        k[i]--;
    } 
    for(int i=0; i<m; i++) cin >> c[i];
    sort(k.begin(),k.end(),greater<int>());

    int ans = 0, p = 0;
    for(int i=0; i<n; i++) {
        if(p <= k[i]) {
            ans += c[p];
            p++;
        } else {
            ans += c[k[i]] ;
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
