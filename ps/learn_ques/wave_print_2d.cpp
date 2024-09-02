#include<bits/stdc++.h>
using namespace std;
void print_wave_array(int a[][5])
{
    for(int i =0;i<5 ;i++)
    {
        if(i%2==0)
        {
            for(int k=0;k<4 ;k++)
            {
                cout << a[k][i]<< " ";

            }
        }
        else 
        {
            for(int k=3;k>=0;k--)
            {

                cout << a[k][i]<<" ";
            }
        }
    }
}
int main()
{
    int a[4][5];
    for(int i=0;i<4;i++)
    {
        for(int k =0;k<5;k++)
        {
            cin >> a[i][k];
        }
    }

    print_wave_array(a);
}
