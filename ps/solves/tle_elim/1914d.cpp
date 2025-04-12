#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
  int n; cin >> n; 
  vector<pair<int,int>> a(n), b(n), c(n);
  for(int i=0; i<n; i++) {
    int x; cin >> x; 
    a[i] = {x,i};
  }
  for(int i=0; i<n; i++) {
    int x; cin >> x; 
    b[i] = {x,i};
  }
  for(int i=0; i<n; i++) {
    int x; cin >> x; 
    c[i] = {x,i};
  }

  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());

  int ans = -1;
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      for(int k=0; k<3; k++) {
        if(a[i].second!=b[j].second && b[j].second!=c[k].second && a[i].second!=c[k].second) {
        ans = max(ans,a[i].first + b[j].first + c[k].first);
        }
      }
    }
  }

  cout << ans << "\n" ;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
