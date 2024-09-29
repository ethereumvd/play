#include<bits/stdc++.h>
#define ll long long
using namespace std;
void xorwise() {
    ll a , b ; cin >> a >> b ;
    ll x = a&b ;
    cout << (a^x) + (b^x) << "\n";
}
int main() {
    int tt ; cin >> tt;
    while(tt--) xorwise();
}
