#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<bool> isprime(n+1,true);
    isprime[0] = isprime[1] = false;
    for(int i=2; i<=n; i++){
        if(!isprime[i]) continue;
        for(int mul=1; mul*i<=n; mul++) {
            isprime[mul*i] = false;
        }
    }
    return 0;
}
