#include<bits/stdc++.h>
#define int long long
using namespace std;
void jogo() {
    int n ; cin >> n ;
    int minn = INT_MAX ;
    vector<int> sec_min ;
    while(n--) {
        int m ; cin >> m ;
        int mi = INT_MAX ; int sec_mi = INT_MAX ;
        vector<int> a(m) ;
        for(int &i:a) cin >> i ;
        mi = *min_element(a.begin(),a.end());
        minn = min(mi,minn) ;
        a.erase(find(a.begin(),a.end(),mi));
        sec_mi = *min_element(a.begin(),a.end());
        sec_min.push_back(sec_mi) ;
        //how tf is this different
    }
    cout << minn + (int)accumulate(sec_min.begin(),sec_min.end(),0ll) - *min_element(sec_min.begin(),sec_min.end()) << "\n" ; 
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc ; cin >> tc ;
    while(tc--) jogo() ;
}
