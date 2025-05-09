#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool is_pali(string &s) {
  int l = 0, r = s.size()-1 ;
  while(l <= r) {
    if(s[l] != s[r]) return false;
    l++; r--;
  }
  return true;
}

void palind_part(string &s, int idx, vector<string> &dummy) {

  if(idx == s.size()) {
    ans.push_back(dummy);
    return;
  }
  for(int i=idx; i<s.size(); i++) {
    string temp = s.substr(idx, i-idx+1);
    if(!is_pali(temp)) continue;
    dummy.push_back(temp);
    palind_part(s, i+1, dummy);
    dummy.pop_back();
  }

}

int main() {
  string s = "aab";
  vector<string> dummy;
  palind_part(s, 0, dummy);
  for(auto &vec:ans) {
    for(auto &st:vec) cout << st << " ";
    cout << "\n";
  }
}
