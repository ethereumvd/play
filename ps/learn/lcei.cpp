#include<bits/stdc++.h>
using namespace std;

int ap(int n)
{
  return (3*n)+7;
}
int setbits(int a)
{
  int n = 1 ;
  int bit;
  int cnt = 0 ;
  while(a>0)
  {
    bit = a&1;
    a = a >> 1;

    if(bit==1) cnt++;
    else continue;
  }
  return cnt ;
}
int nfibonacci(int n )
{
  if(n==0) return 0;
  int a =0;
  int b=1;
  int sum ;
  for(int i =1;i<=n;i++)
  {
    sum = a+b;
    a=b;
    b=sum;
  }
  return sum;
}
int main()
{
  //todo -
  //given an ap 3*n+7 , print the nth term provided by user
  //print total number of sets bits in a and b , sepatately
  //print nth fibonnaci series number 

/*
  int n ; cin >> n;
  cout << ap(n);
*/
/*
  int a , b ;
  cin >> a >> b ;
  cout << setbits(a)+setbits(b) ;
*/

  int n; cin >> n;
  cout << nfibonacci(n-2) ;
  
}



