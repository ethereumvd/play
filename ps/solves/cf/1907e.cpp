#include<bits/stdc++.h>
#define int long long
using namespace std;
void jogo() {

    int n ; cin >> n ;
    int ans = 1;
    while(n > 0) {
        int dig = n % 10 ;
        n = n / 10;
        int tmp = 0 ;
        for(int i = 0 ; i<=dig ;i++) {
            for(int j = 0 ; j<=dig ;j++) {
                if(dig - j - i >= 0) tmp++;
            }
        }
        ans = ans*tmp ;
    }

    cout << ans << "\n" ;

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ;
    int tc = 1 ; cin >> tc ;
    while(tc--) jogo() ;
    return 0;
}
