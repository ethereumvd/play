#include<iostream>
using namespace std;
int main(){

    int n ; //4 bytes of memory
    int* a = new int ; //total 8+4 bytes of memory
    //heap memory has to freed manually 
    /*
    while(true){
        int* ptr = new int ; 
    }
    */
    //the above will take up memory until the program crashes
    //the stack memory , of the pointer will get freed but not the heap (dynamic)
    delete a ; //for freeing up memory 
}
