#include<bits/stdc++.h>
using namespace std;
int getlength(char name[])
{
    int counter =0;
    int i =0;
    while(name[i]!='\0') 
    {
        counter++;
        i++;
    }
    return counter;
}
void strr()
{
    char name[20];
    cin >> name;
    cout << "your name :- " << name << "\n";

    cout << getlength(name) << " "<< strlen(name);
    
    string s1;
    getline(cin,s1);
    cout << s1;
    cout << s1.length();
    string s2 ;
    getline(cin,s2);
}
int main()
{
    strr();
}
