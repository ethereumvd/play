#include<bits/stdc++.h>
#define loop(n,i) for(int i=0;i<n;i++) 
using namespace std;
int main()
{
    int n ; cin >> n ;
    vector<int> A(n) ;
    loop(n,i) cin >> A[i] ;
    
    int m ; cin >> m ;
    vector<int> B(m) ;
    loop(m,i) cin >> B[i] ;

    loop(n,i)
    {
        loop(m,j)
        {
            int a = A[i] ;
            int b = B[j] ;
            int sum = a + b ;
            
            bool inA = false ;
            bool inB = false ;

            loop(n,k)
            {
                if(A[k]==sum)
                {
                    inA = true ;
                    break ;
                }
            }
            loop(m,l)
            { 
                if(B[l]==sum)
                {
                    inB = true ;
                    break;
                }
            }
            if(!inA && !inB)
            {
                cout << a << " " << b ;
                return 0;
            }

           
        }
    }
}
