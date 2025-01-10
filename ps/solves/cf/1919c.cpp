#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n ; cin >> n ;
    vector<int> a(n);
    for(int &i:a) cin >> i ;

    vector<int> s , t ;
    int pen = 0 ;
    for(int &i:a) {
        if(s.empty() || s.back()>=i){
            s.push_back(i);
            continue;
        }
        if(t.empty() || t.back()>=i) {
            t.push_back(i);
            continue;
        }
        pen++;
        t.push_back(i) ;
    }
    cout << pen << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr) ,cout.tie(nullptr) ;
    int tc ; cin >> tc ;
    while(tc--) jogo() ;
}
