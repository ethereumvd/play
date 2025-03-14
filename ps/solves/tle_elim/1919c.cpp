#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    int x = INT_MAX,y=INT_MAX;
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        if(x>y){
            swap(x,y);
        }
        if(a[i] <= x){
            x = a[i];
        } else if(a[i]<=y){
            y = a[i];
        } else{
            x= a[i];
            ans ++;
        }
    }
    cout<<ans<<endl;
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
