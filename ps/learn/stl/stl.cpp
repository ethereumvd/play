#include<bits/stdc++.h>
using namespace std;
void stl_algorithms()
{
    vector<int> v;

    for(int i=0;i<10;i++) v.push_back(i) ;
    for(int i=0;i<v.size();i++) cout << v[i] << " " ;
    cout << "\n";

    if(binary_search(v.begin(),v.end(),6)) cout << "6 is present" ;
    else cout << "6 is not present";

    cout << "\n";

    int a = 7 ;
    int b =9;
    cout << max(a,b) << "\n" << min(a,b) << "\n";

    swap(a,b);
    cout << a << "\n";

    string s = "abcdefghijklmnopqrstuvwxyz";
    reverse(s.begin(),s.end());
    cout << s << "\n";

    rotate(v.begin(),v.begin()+5,v.end());
    for(int i=0 ;i<v.size();i++) cout << v[i] << " ";
    cout << "\n";

    sort(v.begin()+3,v.end()-1);
    for(int i=0 ;i<v.size();i++) cout << v[i] << " ";
    cout << "\n";
}
void mapp()
{
    map<int,string> m ;

    m[1] = "ethereum" ;
    m[2] = "is" ;
    m[99] = "nigga" ;
    m.insert({6,"bheem"});
    for(auto i:m) cout << i.first << " ";
    cout << "\n";

    m.erase(6);
    for(auto i:m) cout << i.first << " ";
    cout << "\n";
}
void sett()
{
    set<int> s;//repeated elements are stored once only in set
    s.insert(5);
    s.insert(5);
    s.insert(9);
    s.insert(9);
    s.insert(6);
    s.insert(4);
    s.insert(0);

    for(int i:s) cout<< i << " " ;
    cout << "\n";

    set<int>::iterator it = s.begin();
    it++;
    
    s.erase(it);
    s.erase(s.begin());
    for(int i:s) cout << i << " ";
    
    cout << "\n";

    cout << s.count(5) ;
}
void priority_queuee()
{
    priority_queue<int> maxi;//by default it is max heap ,when max heap whenever we fetch elmnt it will give element with max value
    priority_queue<int,vector<int>,greater<int> > mini;

    maxi.push(1);
    maxi.push(2);
    maxi.push(9);
    maxi.push(0);

    int n = maxi.size();
    
    for(int i =0 ; i<n ;i++) 
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << "\n";

    mini.push(10);
    mini.push(3);
    mini.push(2);
    mini.push(11);
    
    n= mini.size();
    for(int i=0; i<n;i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << "\n";
    

}
void queuee()
{
    queue<string> q;
    q.push("hello");
    q.push("world");
    q.push("again");

    cout << "first element " << q.front()<< "\n";
    q.pop();
    cout << " first element " << q.front() << "\n";



}
void stackk()
{
    stack<string> s;
    s.push("hello");
    s.push("world");
    s.push("again");

    cout << "top element is :- " << s.top() << "\n";

    s.pop();
    cout << s.top() << "\n";
    cout << s.size() << "\n";
    cout << "empty or not " << s.empty() << "\n";

}
void listt()
{
    list<int> l;
    l.push_back(22);
    l.push_front(99);
    for(int i:l) cout << i << " ";
    
    cout << "\n";

    list<int> n(5,101);
    for(int i:n) cout << i << " ";

    cout << "\n";
    
    l.erase(l.begin());//o(n)comlexity as we have to traverse the list
    for(int i:l) cout << i << " ";

    cout << "\n";

    cout << n.size() << "\n";

    list<int> m(n);
    for(int i:m) cout << i << " ";
}
void dequee()
{
    deque<int> d;
    d.push_back(69);
    d.push_front(96);
    for(int i:d) cout << i << " ";

    d.pop_back();
    d.pop_front();
    for(int i:d) cout << i << " ";
    
    d.push_back(6969);
    d.push_front(9696);
    cout << d.at(2) << " ";
    cout << d.size() <<" ";
    

}
void vectorr()
{
    //dynamic array
    vector<int> a(5,1);//makes a with 5 elemnts all intialised to 1
    vector<int> copied(a);//copies the vector a to the vector copied
    vector<int> v;
    v.push_back(9);
    cout << v.capacity()<<endl;
    v.push_back(1);
    cout << v.capacity()<<endl;
    v.push_back(88);
    cout << v.capacity()<<endl;

    cout << v.size()<<endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    v.clear();// empties the vector

}
void array()
{
    //static , not dynamic
    std::array<int,8> a ={1,2,3,4,5,6,7,8};
    int size =a.size();
    for(int i =0;i<size;i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
    cout << "element at 2nd index" << a.at(2) << endl;
    cout << "empty or not"<< a.empty() << endl;
    cout << "first elmnt" << a.front() << endl;
    cout << "last elmnt" << a.back() << endl;

}
int main()
{
   //vectorr(); 
   //dequee();
   //listt();
   //stackk();
   //queuee();
   //priority_queuee();
   //sett();
   //mapp();
   //stl_algorithms();
}
