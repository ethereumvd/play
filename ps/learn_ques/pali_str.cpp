#include<bits/stdc++.h>
using namespace std;
char tolower(char ch)//for case insensitive checking
{
   if(ch>='a'&& ch<='z') return ch;
   else return (ch - 'A' + 'a');
}
int getlength(char c[])
{
    int cnt =0;
    int i =0;
    while(c[i]!='\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}
void check_palindrome(char c[])
{
    bool is_palindrome = true;
    int start_idx =0;
    int end_idx = getlength(c) -1;
    while(start_idx<=end_idx)
    {
       if((c[start_idx]>='!'&& c[start_idx]<='/' ) | c[start_idx]==' ')
       {     
            start_idx++;
            if(tolower(c[start_idx])==tolower(c[end_idx])) 
            {
                start_idx++;
                end_idx--;
                continue;
            }
            else 
            {
                is_palindrome = false;
                break;
            }
       }
       if((c[end_idx]>='!'&& c[end_idx]<='/') | c[end_idx]==' ')
       {     
            end_idx--;
            if(tolower(c[start_idx])==tolower(c[end_idx])) 
            {
                start_idx++;
                end_idx--;
                continue;
            }
            else 
            {
                is_palindrome = false;
                break;
            }
       }
       else
       {
            if(tolower(c[start_idx])==tolower(c[end_idx])) 
            {
                start_idx++;
                end_idx--;
                continue;
            }
            else 
            {
                is_palindrome = false;
                break;
            }

       }
    }
    is_palindrome ? cout << "palindrome" : cout << "not palindrome";

}
int main()
{
    char c[20]; cin >> c;
    check_palindrome(c);
}
