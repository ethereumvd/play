#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n; cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x ;

    if(a[0]==1) {
        cout << n+1 << " ";
        for(int i=1; i<=n ;i++) cout << i << " ";
        cout << "\n";
    } else {
        int hop = -1;
        for(int i=0; i<n-1; i++) {
            if(a[i]==0 && a[i+1]==1) {
                hop = i+1; break;
            }
        }
        if(a[n-1]==0) hop = n;
        if(hop==-1) cout << -1 ; 
        else {
            for(int i=1; i<=n; i++) {
                cout << i << " ";
                if(i==hop) cout << n+1 << " " ;
            }
        }
        cout << "\n";
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
