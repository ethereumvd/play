#include<iostream>
using namespace std;

class Example {
public:
    Example() {
        cout << "created example normally" << endl;
    }
    Example(int x) {
        cout << "created example with " << x << endl;
    }
};

class Without {

public:
    string m_name;
    Example m_example;

    Without(int x, string name) {
        m_example = Example(x);
    }
};

class With {
public:
    string m_name;
    Example m_example;

    With(int x, string name) : m_name(name) , m_example(Example(x)) {}
};


int main() {
    cout << "without mem init list : - " << endl ;
    Without wi = Without(10, "ethereum");
    cout << "with mem init list : - " << endl ;
    With w = With(10, "ethereum");
}
