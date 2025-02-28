#include<bits/stdc++.h>
using namespace std;
void jogo() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v(n),p;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            int c=0;
            while(i<n && s[i]=='B')
            {
                c=max(c,v[i]);
                i++;
            }
            p.push_back(c);
        }
    }

    if(p.empty() || k>=p.size())
    {
        cout<<0<<"\n";
        return;
    }

    sort(p.rbegin(), p.rend());
    for (int i : p) cout << i << " ";
    cout << "\n";
    cout<<p[k]<<"\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while(tc--) jogo();
    return 0;
}
