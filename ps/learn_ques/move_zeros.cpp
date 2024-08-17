#include<bits/stdc++.h>
using namespace std;
void movee(vector<int> v,int n)
{
    int i =0;
    int k =0;
    while(i<n)
    {
        if(v[i]!=0)
        {
            swap(v[i],v[k]);
            i++;
            k++;
            continue;
        }
        i++;
    }
    for(int l=0;l<n;l++) cout << v[l] << " ";
}
int main()
{
    int n ; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    movee(v,n);
}
