#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,c=0;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<vector<int>> p(n,vector<int> (11));
        p[0][v[0]]++;
        for(int i=1;i<n;i++)
        {
            p[i]=p[i-1];
            p[i][v[i]]++;
        }
        for(int i=2;i<n;i+=2)
        {
            for(int j=0;j<=n-i;j++)
            {
                int u=0;
                if(j==0) 
                {
                    for(int k=0;k<=10;k++) 
                    {
                        u+=p[i-1][k];
                        if(u==i/2) c++;
                        break;
                    } 
                }
                else 
                {
                    for(int k=0;k<=10;k++)
                    {
                        u=u+p[j+i-1][k]-p[i-2][k];
                        if(u==i/2) c++;
                        break;
                    }
                }
            }
        }
        cout<<(n*(n+1)/2-c)<<"\n";
    } 
}