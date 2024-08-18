#include<bits/stdc++.h>
using namespace std;
void rotate_array(vector<int> v,int n,int r_val)
{
    vector<int> vrot(n);
    int i =0;
    while(i<n)
    {
        vrot[(i+r_val)%n] = v[i];
        i++;
    }
    for(int k=0;k<n;k++) cout << vrot[k] << " ";
}
int main()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++) cin >> v[i];
    int r_val ; cin >> r_val;

    rotate_array(v,n,r_val);
}
