#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n , k ; cin >> n >> k ;
    string s ; cin >> s ;

    int z = 0 , o = 0 ,sum = 0;
    vector<int> sums ;

    for(int i = n-1 ;i>0 ;i--) {
        if(s[i]=='0') z++;
        else o++ ;
        sum =  o - z ;
        if(sum>0) sums.emplace_back(sum);
    }
    /*for(int &i:sums) cout << i << " " ;*/
    /*cout << "\n";*/

    sort(sums.begin(), sums.end());  
    int ans = 1;

    while (k > 0 && !sums.empty()) {
        k -= sums.back(); 
        sums.pop_back();
        ++ans;
    }
    if(k>0) cout << -1 << "\n" ;
    else cout << ans << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
