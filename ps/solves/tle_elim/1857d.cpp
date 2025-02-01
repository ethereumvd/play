#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n ; cin >> n ;
    vector<int> a(n) , b(n);
    for(int &i:a) cin >> i ;
    for(int &j:b) cin >> j ;
    
    vector<int> diff(n) ;
    for(int i = 0 ; i < n ; i++) diff[i] = a[i] - b[i] ;

    vector<int> pts ;
    int max_p = *max_element(diff.begin(),diff.end());
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if(diff[i] == max_p) {
            pts.push_back(i + 1) ;
            cnt++ ;
        }
    }

    cout << cnt << "\n" ;
    for(int i = 0 ; i<pts.size() ;i++)  cout << pts[i] << " " ;
    cout << "\n" ;

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
