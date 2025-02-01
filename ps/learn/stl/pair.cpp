#include<bits/stdc++.h>
using namespace std;
void pairr() {

    pair<int,string> p ;
    p = {7,"wasd"} ;
    cout << p.first << " " << p.second << "\n";
    p = make_pair(10,"abcd") ;
    cout << p.first << " " << p.second << "\n";

    pair<int,string> ps = p ;
    //doesnt go by reference only a copy is made 
    //if we use &ps then reference used 
    //pair<int,string> &ps = p ; like this
    ps = make_pair(9,"qwer");
    cout << p.first << " " << p.second << "\n";
    cout << ps.first << " " << ps.second << "\n";

    pair<int,int> p_arr[3] ;
    //array of pairs , dont generally use this intead use vector of pairs
    p_arr[0] = {1,7} ; 
    p_arr[1] = {2,10} ;
    p_arr[2] = {3,11} ;

    for(int i = 0 ; i < 3 ;i++) {
        cout << p_arr[i].first << " " << p_arr[i].second << "\n";
    }
   
    swap(p_arr[1],p_arr[2]);

    for(int i = 0 ; i < 3 ;i++) {
        cout << p_arr[i].first << " " << p_arr[i].second << "\n";
    }

}

int main() {

    pairr();
    return 0 ;
}
