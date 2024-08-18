#include<bits/stdc++.h>
using namespace std;
void frequency_of_chars(string &s)
{
    int freq[26]={0} ;
    int idx;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&& s[i]<= 'z') idx =  s[i] -'a';
        if(s[i]>='A' && s[i]<='Z') idx = s[i] - 'A';
        freq[idx]++;
    }
    for(int k=0;k<26;k++) cout << freq[k] << " " ;
    cout << '\n';
    int max_idx = 0;
    for(int l =0;l<26;l++)
    {
        if(freq[l]>freq[max_idx]) max_idx=l;
    }
    cout << char(max_idx+'a');

}
int main()
{
    string s;
    getline(cin,s);

    frequency_of_chars(s);
}
