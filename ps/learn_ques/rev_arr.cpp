#include<bits/stdc++.h>
using namespace std;
void reverse_array(vector<int> v, int n)
{
    int start_idx = 0 ;
    int end_idx = n-1;
    while(start_idx<=end_idx)
    {
        swap(v[start_idx],v[end_idx]);
        start_idx++;
        end_idx--;
    }
    for(int i =0;i<n;i++) cout << v[i] << " ";
}
int main()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int i =0;i<n;i++) cin >> v[i] ;

    reverse_array(v,n);
}
