#include<bits/stdc++.h>
using namespace std;

bool palindrome(int idx, string& s) {
  if(idx > s.size()/2) return true;
  if(s[idx] != s[s.size()-idx-1]) return false;
  return palindrome(idx+1,s);
}

int main() {
  string s = "madam";
  string s2 = "helloolleh";
  if(palindrome(0,s)) cout << "s is pali" << "\n"; 
  if(palindrome(0,s2)) cout << "s2 is pali" << "\n";
  return 0;
}
