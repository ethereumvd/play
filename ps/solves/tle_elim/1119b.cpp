#include<bits/stdc++.h>
using namespace std;
void jogo() {

    int n, h; cin >> n >> h;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    /*int k = 0 , ch = h;*/
    /*multiset<int> st;*/
    /*bool can = true;*/
    /*for(int i=0; i<n; i++) {*/
    /*    st.insert(a[i]);*/
    /*    for(auto iter=st.rend(); iter!=st.rbegin(); iter++){*/
    /*        int mxh = *iter;*/
    /*        ch -= mxh;*/
    /*        if(ch <= 0){*/
    /*            can = false;*/
    /*            ch = h;*/
    /*            break;*/
    /*        }*/
    /*        iter++;*/
    /*    }*/
    /*    if(!can) break;*/
    /*    else k++;*/
    /*}*/
    /**/
    /*cout << k << "\n";*/

    //this will give tle but who gives a shit, try anyways
    vector<int> c; 
    int k = 0;
    for(int i=0; i<n; i++) {
        c.emplace_back(a[i]);
        sort(c.begin(),c.end(),greater<int>());
        int req = 0;
        for(int j=0; j < c.size(); j+=2) req += c[j];
        if(req > h) break;
        k++;
    }
    cout << k << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false) ,cin.tie(nullptr);
    int tc = 1;
    while(tc--) jogo();
    return 0;
}
