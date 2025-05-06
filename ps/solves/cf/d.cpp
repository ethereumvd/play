#include<bits/stdc++.h>
using namespace std;
#define int long long 
void jogo() {
  int n; cin >> n;

  vector<pair<int, int>> bs(n);
  int xx = 0;
  int sxyx = 0;
  
  int sum = 0;
  for(int i=0; i<1e4; i++) sum++;

  for(int i=0; i<1e4; i++) sum++;

  // for(int i=0; i<1e4; i++) sum++;

  //cout << sum * 7 + 12;


  for (int i = 0; i < n; i++) {
    cin >> bs[i].first >> bs[i].second;
    xx ^= bs[i].first;
    sxyx ^= (bs[i].first + bs[i].second);
  }
  int s = xx;

  int spt = sxyx;
  int t = spt - s;

  cout << s << " " << t << endl;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
