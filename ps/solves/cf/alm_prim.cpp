#include<bits/stdc++.h>
using namespace std;
int main() {
    int n ; cin >> n ;
    vector<int> prime_div(n+1,0) ;

    for(int i =2 ;i<n;i++) {
        if(prime_div[i]==0) {
            for(int k =i;k<=n;k+=i) {
                prime_div[k]++ ;
            }
        }
    }

    int cnt = 0 ;
    for(int i = 2 ;i<=n;i++) {
        if(prime_div[i]==2) cnt++ ;
    }
    cout << cnt << endl ;
}
