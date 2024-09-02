#include<bits/stdc++.h>
using namespace std;
void rotate_ninety_cw(int a[][5])
{
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<5;k++)
        {
            cout << a[i][k]<< " ";
        }
        cout << "\n";
    }
}
int main()
{
    int a[4][5];
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<5;k++)
        {
            cin >> a[i][k];
        }
    }
    rotate_ninety_cw(a);
}
