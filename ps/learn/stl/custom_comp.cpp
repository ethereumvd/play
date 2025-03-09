#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int,int> a, pair<int,int> b)  {
    if(a.first!=b.first) return a.first < b.first ;
    return a.second > b.second;
}
//this comparator should return false when we want to swap

int main() {

    vector<pair<int,int>> v = {{1,2},{3,4},{3,5},{4,5},{4,5},{7,1},{8,2},{8,10},{8,-1}};

    sort(v.begin(),v.end(),cmp);

    for(auto i:v) cout << i.first << " " << i.second << "\n";
}
