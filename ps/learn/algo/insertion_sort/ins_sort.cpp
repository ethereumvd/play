#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> v,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = v[i];
        int k = i-1;
        while(k>=0 && v[k]>temp)
        {
            v[k+1] = v[k];
            k-=1;
        }
        v[k+1] = temp;
    }
    for(int l=0;l<n;l++) cout << v[l] << " " ;
}
int main()
{
    int n ; cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    insertion_sort(v,n);
}
