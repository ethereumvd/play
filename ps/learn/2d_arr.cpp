#include<bits/stdc++.h>
using namespace std;
void column_wise_sum(int arr[][3])
{
    int sum[3] = {0};
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            sum[i]+=arr[k][i];
        }
    }
    for(int k=0;k<3;k++) cout << sum[k] << " ";
}
void row_wise_sum(int arr[][3])
{
    int sum[3] = {0} ;
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            sum[i] += arr[i][k]; 
        }
    }
    for(int k=0;k<3;k++) cout << sum[k] << " ";
}
bool linear_search(int arr[][3] , int key)
{
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            if(arr[i][k]==key) return true;
        }
    }
    return false;
}
void two_dimensional_arrays()
{
    int arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            cin >> arr[i][k];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++)
        {
            cout << arr[i][k] << " ";
        }
        cout <<  "\n";
    }
    int target; cin >> target ;
    cout <<  linear_search(arr,target) << "\n";
    row_wise_sum(arr);
    cout << "\n";
    column_wise_sum(arr);
}
int main()
{
    two_dimensional_arrays();
}
