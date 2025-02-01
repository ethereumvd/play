#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n, k;
  cin >> n >> k;

  vector<array<int, 3>> v(n);
  vector<int> x, y, z;
  for (int i = 0; i < n; i++) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
    if (v[i][1] == 0 && v[i][2] == 1) {
      x.emplace_back(v[i][0]);
    } else if (v[i][1] == 1 && v[i][2] == 0) {
      y.emplace_back(v[i][0]);
    } else if (v[i][1] == 1 && v[i][2] == 1) {
      z.emplace_back(v[i][0]);
    }
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());

  int l = 0, r = 0, ans = 0;
  int cnt = 0;
  for (int i = 0;
       i < min(k, (int)min(z.size(), min(x.size(), y.size()))) && cnt < k;
       i++) {
    if (x[l] + y[l] < z[r]) {
      ans += x[l] + y[l];
      l++;
    } else {
      ans += z[r];
      r++;
    }
    cnt++;
  }

  if (cnt < k) {
    for (int i = r; i < z.size() && cnt < k; i++) {
      ans += z[i];
      cnt++;
    }
  }

  if (cnt < k) {
    for (int i = l; i < (int)min(x.size(), y.size()) && cnt < k; i++) {
      ans += x[i] + y[i];
      cnt++;
    }
  }

  if (cnt < k) {
    cout << -1 << "\n";
  } else
    cout << ans << "\n";
}
