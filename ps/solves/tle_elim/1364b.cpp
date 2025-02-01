#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n ; cin >> n ;
    vector<int> p(n) ;
    for(int &i:p) cin >> i ;

    vector<int> ans ;

    for(int i = 0; i< n ;i++) {
        if(i==0 || i==n-1 || (p[i-1] < p[i]) != (p[i] < p[i+1])) ans.push_back(i) ;
    }



}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
