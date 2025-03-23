#include<bits/stdc++.h>
using namespace std;
vector<int> num = {4, 8, 15, 16, 23, 42};
int comm (vector<int> &v1, vector<int> &v2) {
    if(v1[0] != v2[0] && v1[0] != v2[1]) return v1[1];
    else return v1[0];
}
void jogo() {
    map<int,vector<int>> mul;
    for(int i=0; i<6; i++) {
        for(int j=i+1; j<6; j++) {
            mul[num[i]*num[j]] = {num[i],num[j]};
        }
    }

    vector<int> muls(4);
    cout << "? " << 1 << " " << 2 << endl;
    cin >> muls[0];
    cout << "? " << 2 << " " << 3 << endl;
    cin >> muls[1];
    cout << "? " << 4 << " " << 5 << endl;
    cin >> muls[2];
    cout << "? " << 5 << " " << 6 << endl;
    cin >> muls[3];
    vector<int> ans(6);
    auto it1 = mul.find(muls[0]);
    auto it2 = mul.find(muls[1]);

    ans[1] = comm(it1->second,it2->second);
    ans[0] = muls[0] / ans[1];
    ans[2] = muls[1] / ans[1];

    it1 = mul.find(muls[2]);
    it2 = mul.find(muls[3]);

    ans[4] = comm(it1->second,it2->second);
    ans[3] = muls[2] / ans[4];
    ans[5] = muls[3] / ans[4];

    cout << "!" << " " <<  ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5];
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
