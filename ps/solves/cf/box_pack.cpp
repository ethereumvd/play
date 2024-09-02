#include<bits/stdc++.h>
#define loop(i,a,n,b) for(int i =a;i<n;i+=b)
using namespace std;

int main() {
    int n ; cin >> n ;
    
    vector<int> a(n);
    unordered_map<int, int> freq ;
    loop(i,0,n,1)
    {
        cin >> a[i] ;
        freq[a[i]]++ ;
    }
    
    int max_freq = 0 ;
    
    for (auto& p : freq)
    {
        if (p.second > max_freq) max_freq = p.second;
    }
    
    cout << max_freq ;
}

