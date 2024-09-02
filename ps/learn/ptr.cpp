#include<bits/stdc++.h>
using namespace std;
int main()
{
    //int *p ; very bad practice and unsafe
    int n = 5;
    int *ptr = &n;
    cout << ptr << "\n";
    cout << *ptr << "\n";
    cout << sizeof(ptr) << "\n" ;
    ptr += 1;
    cout << ptr << "\n";
    cout << *ptr << "\n"; 
/*  char ch = 'f'; 
    char *p = &ch;
    cout << *p << " " << p <<"\n";
    p=p+1;
    cout << *p << " " << p <<"\n";
*/
    

    

}

