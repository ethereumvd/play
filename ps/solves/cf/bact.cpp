#include<bits/stdc++.h>
using namespace std;
int main() {
    int x ; cin >> x ;
    int cnt =0 ;
    while(x!=0) {
        if((x & 1) == 1) {
            cnt++ ;
            x = x>>1;
            continue ;
        }
        x = x>>1 ;
    }
    cout << cnt << "\n" ;
}
