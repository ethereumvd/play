#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n ; cin >> n;
    vector<int> uni(n),sk(n);
    vector<vector<int>> tu(n,vector<int>());
    for(int i=0; i<n; i++) {
        cin >> uni[i];
        uni[i]--;
    }
    for(int i=0; i<n; i++){
        cin >> sk[i];
        tu[uni[i]].push_back(sk[i]);
    }

    for(int i=0; i<tu.size();i++) {
        sort(tu[i].begin(),tu[i].end(),greater<int>());
        vector<int> prefix(tu[i].size());

    }

}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
