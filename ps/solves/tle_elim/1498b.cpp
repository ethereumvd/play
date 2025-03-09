#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n, wid; cin >> n >> wid;
    multiset<int> w;
    while(n--) {
        int i; cin >> i;
        w.insert(i);
    }

    int sz = wid ;
    int h = 1;
    while(!w.empty()) {
        //if this works idk anymore what is wrong what is right
        auto mxi = w.upper_bound(sz);
        if(mxi == w.begin()) {
            sz = wid;
            h++;
        } else {
            mxi--;
            int mx = *mxi;
            sz -= mx;
            w.erase(mxi);
        }
    }
    cout << h << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
