//how the fuck is this doing something different than 1895b.cpp ???
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
        for(int &i:a) {
            cin >> i ;
            mi = min(mi,i) ;
        }
        minn = min(mi,minn) ;
        for(int i = 0 ;i<m ; i++) {
            if(a[i]!=mi && a[i]<sec_mi) {
                sec_mi = a[i] ;
            }
        }
        sec_min.push_back(sec_mi) ;
    }
    cout << minn + accumulate(sec_min.begin(),sec_min.end(),0) - *min_element(sec_min.begin(),sec_min.end()) << "\n" ; 
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc ; cin >> tc ;
    while(tc--) jogo() ;
}
