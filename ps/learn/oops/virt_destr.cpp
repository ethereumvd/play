#include<bits/stdc++.h>
using namespace std;


class Base {
public:
    Base() { cout << "Base constructor called..." << endl; }
    virtual ~Base() {cout << "Base destructor called..." << endl; }
};

class Derieved : public Base {
public:
    Derieved() {m_ptr = new int; cout << "Derieved constructor called..." << endl;}
    ~Derieved() {delete m_ptr; cout << "Derieved destructor called..." << endl;}
private:
    int* m_ptr;
};

int main() {
    Base* base = new Base();
    delete base;

    cout << "-------------------------------" << endl;

    Derieved* der = new Derieved();
    delete der;

    cout << "-------------------------------" << endl;

    Base* poly = new Derieved();
    delete poly;
    // this does not call the destructor of the Dereived class 
    // IFF base class destructor is not virtual
    // delete checks the type of pointer and sees its base*
    // so it checks in the vtable of base 
    // if not marked virtual it wont se anything ans just call base's destr 
}
