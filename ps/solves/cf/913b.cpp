#include<bits/stdc++.h>
using namespace std;
void jogo() {
  int n; cin >> n;
  vector<int> ch(n,0);
  for(int i=1; i<=n-1; i++) {
    int p; cin >> p;
    p--;
    ch[p]++;
  }

  int ans = 0;
  for(int i=0; i<n; i++) {
    if(ch[i]==0) ans++;
  }

  if(ans >= 3) cout << "Yes";
  else cout << "No";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
