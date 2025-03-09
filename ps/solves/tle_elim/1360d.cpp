#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, k; cin >> n >> k;
    if(k>=n) cout << "1" << "\n";
    else {
        int mx = 1;

        for(int i=2; i<=sqrt(n); i++) {
            if(n % i == 0){
                int p1 = i;
                int p2 = n/i;
                if(max(p1,p2)<=k) {
                    mx = max(max(p1,p2),mx);
                }else if(min(p1,p2)>k) {
                    continue;
                }else {
                    mx = max(min(p1,p1),mx);
                }
            }
        }
        cout << n / mx << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
