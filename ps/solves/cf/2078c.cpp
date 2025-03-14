#include<bits/stdc++.h>
using namespace std;
#define int long long
//diff might go out of bounds of constraint
void jogo() {

    int n; cin >> n;
    vector<int> b(2*n);
    int sm = 0;
    for(int i=0; i<2*n; i++) {
        cin >> b[i];
        sm += b[i];
    }
    sort(b.rbegin(),b.rend());

    map<int,int> bs;
    int s1 = 0;
    for(int i=0; i<n; i++) {
        bs[b[i]]++;
        s1 += b[i];
    }
    int diff = 2*s1 - sm;

    if(bs.find(diff)==bs.end()) {
        for(int i=0; i<n; i++) {
            cout << b[i+n] << " " << b[i] << " ";
        }
        cout << diff << "\n";
    } else {
        b.push_back(2*b[n]+diff);
        cout << b[0] << " ";
        for(int i=1; i<n+1; i++) {
            cout << b[i+n] << " " << b[i] << " ";
        }
        cout << "\n";
    }

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
