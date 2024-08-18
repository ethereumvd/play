#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> v,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min_idx = i;
        for(int k =i;k<size;k++)
        {
            if(v[k]<v[min_idx]) 
            {
                min_idx = k;
                continue;
            }
            else continue;
        }
        swap(v[min_idx],v[i]);
    }
    for(int l =0 ; l<size;l++) cout << v[l] << " ";
}
int main()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int i =0 ; i< n ;i++) cin >> v[i];

    selection_sort(v,n);
}
