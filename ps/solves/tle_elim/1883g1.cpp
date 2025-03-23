#include<bits/stdc++.h>
using namespace std;
int up_bound(vector<int> &arr, int val, int n) {
    int idx = n;
    int l = 0; int r = n-1;

    while(l <= r) {
        int mid = l + ((r-l)/2);
        if(arr[mid] > val) {
            idx = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return idx;
}
void jogo() {
    int n, m; cin >> n >> m;
    vector<int> a(n) , b(n);
    for(int i=0; i<n-1; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    a[n-1] = 1;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int idx = -1, res = n; 
    for(int i=0; i<n; i++) {
        int idup = up_bound(b,a[i],n);
        /*cout << idup << " ";*/
        if(idup == n) {
            res = i;
            break;
        }
        if(idup > idx) {
            idx = idup ;
        }else if(idup == idx) {
            if(idup == n-1) {
                res = i;
                break;
            }
            idx = idup + 1;
        } else if(idup < idx) {
            if(idx == n-1) {
                res = i;
                break;
            }
            idx++;
        }
        /*cout << idx << "\n";*/
    }
    /*cout << "\n";*/
    cout << n - res << "\n"; 
    /*cout << "\n";*/
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
