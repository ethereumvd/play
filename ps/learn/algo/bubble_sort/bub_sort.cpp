#include<bits/stdc++.h>
using namespace std ;
void bubble_sort(vector<int> v,int n)
{
    bool swapped = false;
    for(int i=n-1;i>0;i--)
    {
        for(int k=0;k<i;k++)
        {
            if(v[k]>v[k+1])
            {
                swap(v[k],v[k+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
        //if no swappings happen then its already sorted so just break
    }
    
    for(int l=0;l<n;l++) cout << v[l] << " ";
}
int main()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++) cin >> v[i] ;

    bubble_sort(v,n);
}
