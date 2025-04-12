#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
  int n; cin >> n;
  vector<int> u(n), s(n);
  for(int i=0; i<n; i++) {
    cin >> u[i];
    u[i]--;
  }
  for(auto &i:s) cin >> i;
  vector<vector<int>> unis(n,vector<int>());

  for(int i=0; i<n; i++)  unis[u[i]].push_back(s[i]);
  for(auto &uni:unis) sort(uni.begin(),uni.end(),greater<int>());

  vector<long long> ans(n,0);
  for(auto &uni:unis) {
    if(uni.empty()) continue;
    int nn = uni.size();
    for(int i=1; i<nn; i++) {
      uni[i] = uni[i-1] + uni[i];
    }
    for(int k=0; k<n; k++) {
      int till = nn - (nn%(k+1));
      if(till == 0) continue;
      ans[k] += uni[till-1];
    }
  }

  for(auto &i:ans) cout << i << " ";
  cout << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
