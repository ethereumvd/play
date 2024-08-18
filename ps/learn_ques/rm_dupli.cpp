//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
#include<bits/stdc++.h>
using namespace std;
bool check_occurence(int count[])
{
    for(int i=0;i<26;i++)
    {
        if(count[i]!=0) return false;
    }
    return true;
}
void remove_adjacent_dupliactes(string &s)
{
    bool found = true;
    while(found)
    {
        found = false;
        for(int i =0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1]) 
            {
                s.erase(i,2);
                found =true;
                break;
            }
        }
    }
    cout << s;

}
int main()
{
    string s ; getline(cin,s);

    remove_adjacent_dupliactes(s);
}
