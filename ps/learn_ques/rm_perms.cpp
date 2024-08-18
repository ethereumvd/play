//https://leetcode.com/problems/permutation-in-string/description/
#include<bits/stdc++.h>
using namespace std;
bool check_equal(int window_cnt[],int part_cnt[])
{
    for(int i=0;i<26;i++)
    {
        if(window_cnt[i]!=part_cnt[i]) return false;
    }
    return true;
}
bool find_all_perms(string &s,string &part)
{
    int part_cnt[26] = {0};
    int pl = part.length();

    for(int i=0;i<pl;i++) 
    {
        int idx = part[i]-'a';
        part_cnt[idx]++;
    }

    
    int window_cnt[26]={0};
    int i=0;
    while(i<pl)
    {
        int idx2 = s[i]-'a';
        window_cnt[idx2]++;
        i++;
    }

    if(check_equal(window_cnt,part_cnt)) return true;
    
    while(i<s.length())
    {
        int old_idx = s[i-pl] -'a';
        int new_idx = s[i] -'a';
        window_cnt[new_idx]++;
        window_cnt[old_idx]--;
        if(check_equal(window_cnt,part_cnt)) return true;
        i++;
    }
    return false;
}
int main()
{
    string s; getline(cin,s);
    string part ; getline(cin,part);

    find_all_perms(s,part) ? cout << "found perm :)" << "\n" : cout << "no perms found :(" << "\n";
}
