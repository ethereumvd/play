#include<iostream>
using namespace std;
int main()
{
/* 
  int n ; cin >> n;
  for(int i =1 ; i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout << i ;
    }
    cout << "\n";
  }
   
*/ 

/*
  int n ; cin >> n;
  for(int i =0 ;i<n;i++)
  {
    for(int j =1 ; j<=n ;j++)
    {
      cout << j ;
    }
    cout << "\n";
  }
*/ 

/*
 int n ; cin >> n ; // n must be a perfect square 
 for(int i =1 ; i*i<=n;i++)
 {
   for(int j =1 ;j*j<=n;j++)
   {
     cout << j*i << " ";
   }
   cout << "\n";
 }
*/ 
/*
int n ; cin >> n;
for(int i =1 ; i<=n;i++)
{
  int m = i;
  for(int j=0;j<i;j++)
  {
    cout << m ; m--;
  }
  cout << "\n";
}
*/
/*
int n ; cin >> n ;

 for(int i=1;i<=n; i++)
{
  for(int j=1;j<=n;j++)
  {
    cout << char(64+i) << " ";
  }
  cout << "\n";
  }
*/
/*
 int n ; cin >> n ;

 for(int i=1;i<=n; i++)
{
  int m = 64;
  for(int j=1;j<=n;j++)
  {
    cout << char(64+j+(n*(i-1))) << " ";
  }
  cout << "\n";
}
*/
/*
 int n ; cin >> n ;

 for(int i=1;i<=n; i++)
{
  int m = 64;
  for(int j=1;j<=i;j++)
  {
    cout << char(m+i) << " ";
  }
  cout << "\n";
}
*/
/* 
int n ; cin >> n ;

 for(int i=1;i<=n; i++)
{
  int m = 64;
  for(int j=1;j<=i;j++)
  {
    cout << char(m+i+j -1) << " ";
  }
  cout << "\n";
}
*/
/*
int n ; cin >> n ;

 for(int i=1;i<=n; i++)
{
  for(int j=1;j<=n-i;j++)
  {
    cout << " " ;
  }
  for(int k = 1; k<=i;k++)
  {
    cout << "*" ;
  }
  cout << "\n";
}
*/
/*
int n ; cin >> n ;
 int m = 1;
 for(int i=1;i<=n; i++)
{
  for(int j=1;j<=n-i;j++)
  {
    cout << " " ;
  }
  for(int k = 1; k<=i;k++)
  {
    cout << m ; m++;
  }
  cout << "\n";
}
*/

//pascals triangle 

/*
  int n ; cin >> n;
  for(int i=1 ; i<=n;i++)
  {
    for(int j=1 ; j<=n-i;j++)
    {
      cout << " " ;
    }
    int k =1;
    while(k<=i)
    {
      cout << k ; k++;
    }
    for(int l =1 ;l<=i-1;l++)
    {
      cout << k-1-l;
    }
    cout << "\n";
  }
*/ 
/*
  int n ; cin >> n ;
  for(int i =1 ; i<=n ; i++)
  {
    for(int j =1 ; j<=n-i+1 ; j++)
    {
      cout << j ;
    }
    for(int k=1 ;k<=i-1;k++)
    {
      cout << "**" ;
    }
    for(int l =1 ; l<=n+1-i;l++)
    {
      cout << n+2-l-i; 
    }
    cout << "\n" ;
  }
*/
}
