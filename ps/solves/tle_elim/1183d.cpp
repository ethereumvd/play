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
    vector<int> freq;
    for(auto i:mp) {
        freq.push_back(i.second);
    }
    sort(freq.rbegin(),freq.rend());

    int ans = freq[0] ;
    int prev = freq[0];
    for(int i=1; i<freq.size(); i++) {
        if(freq[i] >= prev) {
            if(prev == 0) break;
            ans += prev - 1;
            prev--;
        }else {
            ans += freq[i];
            prev = freq[i];
        }
    }

    cout << ans << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
