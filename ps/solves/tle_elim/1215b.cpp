#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> dpp(n,0);
    vector<int> dpn(n,0);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    dpp[0] = a[0] > 0 ? 1 : 0; 
    dpn[0] = a[0] < 0 ? 1 : 0;

    for(int i=1; i<n; i++) {
        if(a[i] > 0) {
            dpp[i] = dpp[i-1] + 1;
            dpn[i] = dpn[i-1];
        } else {
            dpp[i] = dpn[i-1];
            dpn[i] = dpp[i-1] + 1;
        } 
    }
    int np = 0;
    int nn = 0;
    for(int i=0; i<n; i++) {
        np += dpp[i];
        nn += dpn[i];
    }

    cout << nn << " " << np << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
