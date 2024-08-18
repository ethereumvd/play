#include<bits/stdc++.h>
using namespace std;
int getlength(char c[])
{
    int cnt =0 ;
    int i =0;
    while(c[i]!='\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}
void reversee(char c[])
{
    int n=getlength(c);
    n=c.size();
    int start_idx = 0;
    int end_idx =  n-1;
    while(start_idx<=end_idx)
    {
        swap(c[start_idx],c[end_idx]);
        start_idx++;
        end_idx--;
    }
    cout << c;
}
int main()
{
    char something[20]; cin >> something;

    reversee(something);
}
