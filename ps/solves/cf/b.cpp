#include<bits/stdc++.h>
#define int long long
using namespace std;

void jogo() {

  int n,k; cin >> n >> k;
  vector<int> l(n),r(n);
  for(int &i:l) cin >> i;
  for(int &i:r) cin >> i;

  for (int i=0; i<n; i++) {
    if (l[i] < r[i]) swap(l[i], r[i]);
  }

  int summ = accumulate(l.begin(), l.end(), 0LL);

  int ans = summ;

  sort(r.rbegin(), r.rend());

  for (int i=0; i<k-1; i++) {
    ans += r[i];
  }

  cout << ans +1 << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
