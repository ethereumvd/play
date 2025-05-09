#include<bits/stdc++.h>
#include <numeric>
using namespace std;

int k;

void printv(vector<int> &a) {
  for(int &i:a) cout << i << " ";
  cout << "\n";
}

int summ(vector<int> &a) {
  int sm = 0;
  sm = accumulate(a.begin(),a.end(),sm);
  return sm;
}

vector<int> dummy;
void print_all_subs(vector<int> &a , vector<int> &dummy, int idx, int n) {

  if(idx == n) {
    if(summ(dummy) == k) {
      printv(dummy);
    } 
    return;
  }
  dummy.push_back(a[idx]);
  print_all_subs(a, dummy, idx+1, n);
  dummy.pop_back();
  print_all_subs(a, dummy, idx+1, n);

}

int main() {

  // vector<int> v = {1, 5 , 6 ,7, 12 , 8 , 3  ,7, 36 ,7};
  // vector<int> v = {3, 1, 2};
  vector<int> v ={ 2, 1 ,1};
  k = 2;
  int n = v.size();
  print_all_subs(v, dummy, 0, n);

}
