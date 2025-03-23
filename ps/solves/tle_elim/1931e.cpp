#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int &i:a) cin >> i;

    vector<int> zs; int dig = 0;
    for(int i=0; i<n; i++) {
        if(a[i]%10==0) {
            int nz = 0;
            while(a[i]%10 == 0) {
                nz++;
                a[i] /= 10;
            }
            zs.push_back(nz);
        }
        dig += (log10(a[i])) + 1;
    }

    if(zs.size()>1) {
        sort(zs.rbegin(),zs.rend());
        for(int i=1; i<zs.size(); i+=2) {
            dig += zs[i];
        }
    }

    if(dig <= m) cout << "Anna\n" ;
    else cout << "Sasha\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
