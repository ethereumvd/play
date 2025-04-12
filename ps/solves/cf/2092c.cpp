#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
  int n; cin >> n; 
  vector<int> a(n);
  for(int &i:a) cin >> i;
  sort(a.begin(),a.end());

  int sm = 0, cnt = 0;
  for(int i=0; i<n; i++) {
    sm += a[i];
    if(a[i] % 2 == 1) cnt++;
  }

  if(cnt == 0 || cnt == n) cout << a[n-1] << "\n";
  else cout << sm - cnt + 1 << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
