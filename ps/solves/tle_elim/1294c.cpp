#include<bits/stdc++.h>
using namespace std;
void jogo() {
    //monkeybrain bruteforce
    //will give tle but who gives a shit, try anyways

    int n; cin >> n;
    int a,b,c; bool found = false;
    for(int i=2; i<=sqrt(n); i++) {
        if(n % i == 0) {
            int f1 = i;
            int f2 = n/i;
            for(int j=2; j<sqrt(f2); j++) {
                if(f2 % j == 0) {
                    int f21 = j;
                    int f22 = f2/j;
                    if(f21!=f1 && f22!=f1) {
                        a = f1;
                        b = f21;
                        c = f22;
                        found = true;
                        break;
                    }
                }
            }
        }
        if(found) break;
    }
    if(!found) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n" ;
        cout << a << " " << b << " " << c << "\n" ;
    }

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
