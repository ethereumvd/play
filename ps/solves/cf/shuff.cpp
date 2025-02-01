#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define MOD 998244353
ll binPow(ll a, ll b) {
  if (b == 0)
    return 1;
  ll w = binPow(a, b / 2);
  w = (w * w) % MOD;
  if (b % 2)
    return (w * a) % MOD;
  return w;
}
void jogo() {

  int n;
  cin >> n;
  vector<int> a(n);

  int zer = 0;
  for (int &i : a) {
    cin >> i;
    if (!i)
      zer++;
  }
  int x = 0;
  for (int i = 0; i < zer; i++) {
    if (a[i] == 1)
      x++;
  }

  int ans = 0;
  int ncr = (1LL * n * (n - 1)) / 2;
  ncr %= MOD;
  for (int i = 1; i <= x; i++) {
    ans = ((1LL * ncr * binPow((i * i) % MOD, MOD - 2)) % MOD + ans) % MOD;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--)
    jogo();
  return 0;
}
