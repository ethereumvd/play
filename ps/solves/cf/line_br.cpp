#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fra(i,a,n,b) for(int i=a;i<n;i+=b) 
#define scanv(v,n) fra(i,0,n,1) cin >> v[i] 
#define endl "\n" 
const int mod = 1e9 + 7 ; 
void pookie_bear()
{
    int n , m ; cin >> n >> m ;
    /*int cnt = 0 , length = 0;*/
    /*while(n--) {*/
    /*    string s ; cin >> s ;*/
    /**/
    /*    if(length+s.length() <= m) {*/
    /*        length+=s.length() ;*/
    /*        cnt++ ;*/
    /*    }*/
    /*    else break ;*/
    /*}*/
    /**/
    /*cout << cnt << endl ;*/
        cerr << "n: " << n << ", m: " << m << '\n';  // Debugging input
    int cnt = 0, length = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        cerr << "Processing word: " << s << ", current length: " << length << '\n';  // Debugging each word
        if (length + s.length() <= m) {
            length += s.length();
            cnt++;
        }
    }

    cout << cnt << '\n';
    cerr << "Result for this test case: " << cnt << '\n';  // Debugging result

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tc ; cin >> tc ;
    while(tc--) pookie_bear() ;
} 
