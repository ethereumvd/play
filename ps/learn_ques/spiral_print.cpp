#include<bits/stdc++.h>
using namespace std;
void print_spiral(int a[][4])
{
    int count =0 ;
    int total = 3*4;
    int start_row = 0;
    int end_col = 3;
    int end_row = 2;
    int start_col=0;
    while(count<total)
    {
        //print first row
        for(int i=start_col;i<=end_col && count<total;i++)
        {
            cout << a[start_row][i] << " " ;
            count++;
        }
        start_row++;
        //print end column
        for(int k=start_row;k<=end_row && count<total;k++)
        {
            cout << a[k][end_col]<< " ";
            count++;
        }
        end_col--;
        //print end row
        for(int l=end_col;l>=start_col && count<total;l--)
        {
            cout << a[end_row][l]<< " ";
            count++;
        }
        end_row--;
        //print start column
        for(int h=end_row;h>=start_row && count<total;h--)
        {
            cout << a[h][start_col] << " ";
            count++;
        }
        start_col++;
    }

}
int main()
{
    int a[3][4];
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<4;k++)
        {
            cin >> a[i][k];
        }
    }
    print_spiral(a);
}
