#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i=0; i<n-1; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    a.push_back(1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
