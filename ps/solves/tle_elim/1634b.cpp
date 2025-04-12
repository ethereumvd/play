#include<bits/stdc++.h>
using namespace std;
#define int long long 
void jogo() {
  int n, x, y; cin >> n >> x >> y;
  int od = 0;
  for(int i=0; i<n; i++) {
    int a; cin >> a;
    if(a % 2 == 1) od++;
  }

  if(x % 2 == 1) {
    if(od % 2 == 1) {
      if(y % 2 == 1) cout << "Bob" << "\n";
      else cout << "Alice" << "\n";
    } else {
      if(y % 2 == 1) cout << "Alice" << "\n";
      else cout << "Bob" << "\n";
    }
  } else {
    if(od % 2 == 1) {
      if(y % 2 == 1) cout << "Alice" << "\n";
      else cout << "Bob" << "\n";
    } else {
      if(y % 2 == 1) cout << "Bob" << "\n";
      else cout << "Alice" << "\n";
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
