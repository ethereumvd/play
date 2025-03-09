#include<bits/stdc++.h>
using namespace std;

//simple comparator
bool should_swap(int a, int b) { 
    if(a>b) return true;
    return false;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    //n^2 sort 
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(should_swap(a[i],a[j])) swap(a[i],a[j]); //increasing
        }
    }

    for(int i:a) cout << i << " ";
}
