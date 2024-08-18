#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> v,int size ,int key)
{
    int start_idx =0;
    int end_idx = size - 1;
    while(start_idx <= end_idx)
    {
        int mid_idx = start_idx + (end_idx - start_idx)/2;
        //this ws done to prevent integer overflow as start_idx+end_idx could result in a integer overflow;
        if (v[mid_idx]==key) return mid_idx;
        if (v[mid_idx]<key)
        {
            start_idx = mid_idx + 1;
            continue;
        }
        if (v[mid_idx]>key)
        {
            end_idx = mid_idx - 1;
            continue ;
        }
    }
    return -1;
}
int main()
{
    int n ; cin >> n ;

    vector<int> v(n) ;
    for(int i=0;i<n;i++) cin >> v[i] ;
    sort(v.begin(),v.end());
    
    int key ; cin >> key ;
    cout << binary_search(v,n,key)<< "\n";
}
