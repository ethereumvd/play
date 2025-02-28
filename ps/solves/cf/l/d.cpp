#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 0;
    int res = 0;   
    for (int i= 0; i< n; i++) {
        int large = 0, small = 0;
        for (int j= i + 1; j< n;j++) {
            if (arr[j] > arr[i]) {
                large++;
            }
            else if (arr[j] < arr[i]) {
                small++;
            }
            int df = large - small;
            if (df < res) {
                res = df;
                l = i;
                r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 <<endl;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
