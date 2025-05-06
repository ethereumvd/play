#include<bits/stdc++.h>
using namespace std;

void reverse(int l, int r, vector<int> &arr) {
  if(l>=r) return;
  swap(arr[l],arr[r]);
  reverse(l+1,r-1,arr);
}

void reversee(int id, vector<int> &arr) {
  if(id > arr.size()/2) return;
  swap(arr[id],arr[arr.size()-id-1]);
  reversee(id+1,arr);
}
int main() {
  vector<int> a = {1,2,3,4,5,6,7};
  reverse(0,a.size()-1,a);
  reversee(0,a);
  for(int& i:a) cout << i << " ";
  return 0;
}
