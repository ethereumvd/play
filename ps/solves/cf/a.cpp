#include<bits/stdc++.h>
using namespace std;
void jogo() {
  int n; cin >> n;
  string s; cin >> s;
  int low = 1, high = n;
  vector<int> ans(n);
  for(int i=s.size()-1; i>=0; i--) {
    if(s[i]=='<') {
      ans[i+1] = low;
      low++;
    } else {
      ans[i+1] = high;
      high--;
    }
  }

  ans[0] = low;

  for(int &i:ans) cout << i << " ";
  cout << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
