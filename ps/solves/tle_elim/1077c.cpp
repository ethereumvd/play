#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    int sm = 0;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sm += a[i];
        mp[a[i]]++;
    }
    vector<int> idx ;
    for(int i=0; i<n; i++) {
        int nsm = sm - a[i];
        if(nsm % 2 == 0) {
            mp[a[i]]--;
            if(mp[nsm/2]>0) {
                idx.push_back(i);
            }
            mp[a[i]]++;
        }
    }
    cout << idx.size() << "\n";
    for(int i=0; i<idx.size(); i++) cout << idx[i]+1 << " ";
    cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
