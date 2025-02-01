#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n ; cin >> n;
    vector<int> a(n);
    int n_o = 0 , n_e = 0 ;
    for(int &x:a) {
        cin >> x ; 
        if(x%2!=0) {
            n_o++;
            continue;
        }
        n_e++;
    }

    cout << ((n_e > 0) ? n_o+1 : n_o-1) << "\n"  ;

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
