#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, k; cin >> n >> k;
    vector<int> ans;

    if(k % 2 == 0) {
        for(int i=1; i<=n-2; i++) {
            ans.push_back(n-1);
        }
        ans.push_back(n);
        ans.push_back(n-1);
    } else {
        for(int i=1; i<=n-2; i++) {
            ans.push_back(n);
        }
        ans.push_back(n);
        ans.push_back(n-1);
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
