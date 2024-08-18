#include<bits/stdc++.h>
using namespace std;
void reverse_this_word(string &s,int start_idx,int end_idx,int i)
{
    while(start_idx<=end_idx)
    {
        swap(s[start_idx],s[end_idx]);
        start_idx++;
        end_idx--;
    }
}
void reverse_words(string &s)
{
   string reversed ="";
   int start_idx =0;
   int end_idx;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]==' ' | i==s.length()) 
       {
           end_idx=i-1;
           reverse_this_word(s,start_idx,end_idx,i);
           start_idx=i+1;
           continue;
       }
       else continue;
   }
   cout << s;

}
int main()
{
    string s ;
    getline(cin,s);

    reverse_words(s);
}
