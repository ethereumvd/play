#include<bits/stdc++.h>
using namespace std;
int main(){

    int i = 2;
    int& k = i ; //this is reference variable 
    
    cout << i << " " << k << "\n";
    i++ ;
    cout << i << " " << k << "\n";
    k++;
    cout << i << " " << k << "\n";
}
