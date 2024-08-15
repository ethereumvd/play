#include<bits/stdc++.h>
using namespace std;
int main()
{
// todo - 
// interchange b/w binary and decimal
// also convert negative integer into binary
// reverse and integer 
// print complement of a integer like for input 5 i.e 101 print 2 i.e 010 that id the complement of 101  
// check if a number is a power of 2 i.e of the form 2^n 
/*  
  int n ; cin >> n;
  int i =0 ;
  int ans =0;
  while(n>0)
  {
    int digit = n%10;
    ans += (digit * pow(2,i));
    i++;
    n = n/10;
  }
  cout << "decimal of the given binary is: " << ans << "\n";
*/
 /* 
  int m ; cin >> m;
  int i =0;
  int ans = 0;
  while(m>0)
  {
    int bit = m&1;
    ans += (bit *(pow(10,i)));
    m = m >> 1;
    i++;
  }
  cout << "binary representation of n is: " << ans << "\n";
*/
/* 
  int n ; cin >> n;
  long long int ans =0 ;
  while(n>0)
  {
    int digit = n%10 ;
    ans = (ans *10 ) + digit ;
    n = n/10;
  }
  if(ans >=INT_MAX || ans <= INT_MIN) cout << "muh me le le" ;
  cout << ans ;
*/

/*   // This code is faulty some cases it will print gand answers
  int n ; cin >> n;
  int i =0 ;
  int ans =0 ;
  while(n>0)
  {
    int bit = n&1 ;
    int digit ;
    if(bit) digit =1;
    else digit =0;
    ans = (ans * 10) + digit ;
    n = n >> 1;
  }
  cout << ans ;
*/

//improved code for finding complement of a base 10 integer 
/*
  int n ; cin >> n ;
  int m = (~n);
  int mask =0 ;
  //loop to get how long is the bit representation of n , to make the mask
  while(n>0)
  {
   mask = mask | 1;
   if(n!=1) mask  = mask << 1; 
    n = n >> 1;

  }
   // here n!=1 was necessary to avoid the extra shift that wouldve happened if it wasnt there , dry run the code for the test case 5
  cout << mask << endl;
  int ans = mask & m ;
  cout << ans; 
*/

  // brute force approach to check if the number is power of two or not 
  /*
  int n ; cin >> n;
  int temp =1;
  int cnt =0;
  for(int i = 0 ;i<31;i++)
  { temp = temp *2;
    if (temp == n ) cnt +=1 ;
  }
   cout << cnt << "\n";
*/
/*   // brilliant logic to check if number is power of two or not
  int n ; cin >> n;
  if(n==0) cout<< "no power of two here buddy";
  else cout << (ceil(log2(n))==floor(log2(n)));
*/




}


