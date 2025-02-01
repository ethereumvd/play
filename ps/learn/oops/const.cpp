#include<iostream>
class entity {

private :
    int m_X , m_Y ;
    mutable int var ; //allows methods which are const to change the variable
public :
    int get_x () const
    //this tells that get_x cannot change anyhting , it's like a read only method
    {
        return m_X ;
        var = 2 ;
    }

    void set_x (int x) {
        m_X = x ;
    } 

};

void print_entity(const entity &e) { 
    //here also const means that i can only call const functions 

    std::cout << e.get_x() << std::endl ;
}
int main() {

    const int MAX_AGE = 90 ;
    
    const int* a = new int;
    //*a = 2 ; here we cannot change the value dereferenced by a but we can change a itself 
    a =(int*)&MAX_AGE ; 

    int* const b = new int ; 
    *b = 43 ;
    //b = (int*)&MAX_AGE ;
    //cannot do this because now it is const b that is we cannot change b itself but the value held by b 
    delete(a);
    delete(b);

    entity e ;
    return 0 ;
}
