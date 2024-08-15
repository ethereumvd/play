#include<bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
  for(int k=0;k<n;k++)
  {
    cout << arr[k];
  }
}
void array_intersection(int arr1[],int n ,int arr2[],int m)
{
  for(int i=0;i<n;i++)
  {
    for(int k=0;k<m;k++)
    {
      if (arr1[i]==arr2[k])
      {
        cout << arr2[k] << " ";
        arr2[k]=INT_MAX;
      }
    }
  }
  int cnt =0;
  for(int l=0;l<m;l++)
  {
    if(arr2[l]==INT_MAX) return;
    else cnt++;
  }
  if(cnt==m) cout << -1;
}
int duplicate(int arr[],int n)
{
  int xorsum =0;
  for(int i=0;i<n;i++)
  {
    xorsum =xorsum^arr[i]^i;
  }
  return xorsum;
}
int unique_elmnt(int arr[],int n)
{
  int ans =0;
  for(int i=0;i<n;i++)
  {
    ans=ans^arr[i];
  }
  return ans ;
}

void swapalternate(int arr[],int n)
{
  for(int i=0;i<n-1;i+=2)
  {
    swap(arr[i],arr[i+1]);
  }
}
void rev(int arr[],int n)
{
  int start =0 ;
  int end =n-1;
  for(int i=0;i<n;i++)
  {
    if(start>=end) return ;//if equal to not applied with > , then gaand
   
    /*
    arr[start]=arr[start]+arr[end];
    arr[end]=arr[start]-arr[end];
    arr[start]=arr[start]-arr[end];
    */
    swap(arr[start],arr[end]);
    
    start++;
    end--;
  }
}

int main()
{
/*
  int n ;cin >> n;
  int arr[100];
  int sum =0 ;
  for(int j=0; j<n;j++)
  {
    cin >> arr[j];
  }
  for(int i =0;i<n;i++)
  {
    sum += arr[i];
  }
  cout << sum ;
  */
/*  int n ; cin >> n;
  int arr[20] ;
  for(int i=0;i<n;i++)
  {
    cin >> arr[i];
  }

  rev(arr,n);
  printarray(arr,n);
*/

//ARRAY PROBLEMS START HERE (lec -10)

/*
  int n ;cin >> n ;
  int arr[n]; 
  for(int j=0;j<n;j++)
  {
    cin >> arr[j];
  }
  swapalternate(arr,n);
  printarray(arr,n);
*/
/*  int n ;cin >> n;//n is in the form 2m+1 and m numbers are present twice
  int arr[n]; 
  for(int j=0;j<n;j++)
  {
    cin >> arr[j];
  }
 cout << unique_elmnt(arr,n);
*/
 /* int n ;cin >> n;
  int arr[n]; 
  for(int j=0;j<n;j++)
  {
    cin >> arr[j];
  }
  cout << duplicate(arr,n);
 */
  int n ;cin >> n;
  int arr1[n]; 
  for(int j=0;j<n;j++)
  {
    cin >> arr1[j];
  }
  int m ;cin>>m;
  int arr2[m];
    for(int k=0;k<m;k++)
  {
    cin >> arr2[k];
  }
  array_intersection(arr1,n,arr2,m);
  


}
    
