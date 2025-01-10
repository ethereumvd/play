#include<iostream>

class entity {

    public :
        float X , Y ;

        entity() {
        }

        entity(float x ,float y) {
            X = x ;
            Y = y ;
        }

        void init() {
            X = 0.0f ;
            Y = 0.0f ;
        }

        void print() {
            std::cout << X << " , " << Y << "\n" ;
        }
};

int main() {
    entity e ;
    e.print() ;
    e.init() ;
    e.print() ;
    e.Y = 9 ; e.Y = 7 ;
    e.print();
}
