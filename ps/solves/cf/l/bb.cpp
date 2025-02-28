#include<bits/stdc++.h>
using namespace std;
#define int long long
void jogo() {
        int n;
        cin>>n;

        string s;
        cin>>s;
        int up = 0,down = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '-'){
                up++;
            }
            else{
                down++;
            }
        }
        if(n < 3){
            cout<<0<<endl;
        return;
        }
        int a = up/2;
        int b = up -a;
        int ans = down*a*b;
        cout<<ans<<endl;


}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
