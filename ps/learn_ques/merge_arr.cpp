#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> v,int n ,vector<int> v2,int m)
{
    vector<int> v3(m+n);
    int i =0 ;
    int j =0 ;
    int k =0 ;
    while(i<n && j<m)
    {
        if(v[i]<v2[j])
        {
            v3[k] = v[i];
            i++;
            k++;
        }
        else 
        {
            v3[k] = v2[j];
            j++;
            k++;
        }

    }
    //these following loops to copy the extra elements
    while(i<n)
    {
        v3[k] = v[i];
        i++;
        k++;
    }
    while(j<m)
    {
        v3[k] = v2[j];
        j++;
        k++;
    }
    for(int l=0 ;l<m+n;l++) cout << v3[l] << " ";

}
int main()
{
    int n ; cin >> n;
    vector<int> v(n) ;
    for(int i =0;i<n;i++) cin >> v[i] ;

    int m ; cin >> m ;
    vector<int> v2(m) ;
    for(int k=0;k<m;k++) cin >> v2[k] ;

    merge(v,n,v2,m);
}
