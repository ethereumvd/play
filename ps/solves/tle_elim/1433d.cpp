#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp.size()==1) cout << "NO\n";
    else {
        int nd1 = 0, nd2;
        for(int i=1; i<n; i++) {
            if(a[i]!=a[nd1]) {
                nd2 = i;
                break;
            }
        }
        vector<pair<int,int>> edges;
        edges.push_back({nd1,nd2});
        for(int i=1; i<n; i++) {
            if(a[i]==a[nd1]) {
                edges.push_back({i,nd2});
            } else if(a[i]==a[nd2]) {
                if(i==nd2) continue;
                edges.push_back({i,nd1});
            } else{
                edges.push_back({i,nd1});
            }
        }

        cout << "YES\n" ;
        for(auto e:edges) {
            cout << e.first+1 << " " << e.second+1 << "\n";
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
