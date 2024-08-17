//https://leetcode.com/problems/merge-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> v1,vector<int> v2, int n, int m)
{
    vector<int> v3;
    int i =0;
    int j =0;
    while(i<m && j<n)
    {
        if(v1[i]<v2[j]) 
        {
            v3.push_back(v1[i]);
            i++;
        }
        if(v1[i]>v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
        if(v2[j]==v1[i])
        {
            v3.push_back(v2[j]);
            v3.push_back(v1[i]);
            j++;
            i++;
        }
    }
    while(i<m)
    {
        v3.push_back(v1[i]);
        i++;
    }
    while(j<m)
    {
        v3.push_back(v2[j]);
        j++;
    }
    for(int k=0;k<m+n;k++) cout << v3[k] << " ";

}
int main()
{
    int n ; cin >> n;
    int m ; cin >> m;
    vector<int> v1(m+n);
    vector<int> v2(m);
    for(int i=0;i<m+n;i++) cin >> v1[i];
    for(int k=0;k<m;k++) cin >> v2[k];

    solve(v1,v2,n,m);
}
