#include<iostream>
// #include<string>
using namespace std;

class String {

private:
    int32_t m_size;
    char* m_data;

public:

    String(const char* str) {
        cout << "created" << endl;
        m_size = ;
    }


};

class Entity {
private:
    String m_name;

public:

    Entity(String name) : m_name(name) {}

};

int main() {
    cout << "he" ;
}
