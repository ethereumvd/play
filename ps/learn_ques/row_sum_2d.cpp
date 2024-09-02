#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5][5];
    for(int i=0;i<5;i++)
    {
        for(int k =0;k<5;k++)
        {
            cin >> arr[i][k];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            cout << arr[i][k] << " ";
        }
        cout << "\n";
    }
    int sum =0;
    int max_sum=INT_MIN;
    int max_row_idx=0;
    for(int i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            sum += arr[i][k];
        }
        if(sum>max_sum)
        {
            max_sum = sum ;
            max_row_idx = i;
        }
    }
    cout << max_sum << " of row " << max_row_idx+1;

}
