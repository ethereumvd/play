#include<iostream>
class entity {

    public :
        static int x , y ; 
        //these variables belong to the class itself and not any specific object
        //we can access these variables without creating an instance of entity 
        
        static void printt() {
            std::cout << x << "," << y << "\n" ;
        }
};

int entity::x ; //:: is scope resolution operator
int entity::y ;
//we do this so that the compiler actually allocates memory for x and y 
//however there is no need to do this for static methods in a class like printt 

int main() {

    entity e ;
    e.x = 1 ; e.y = 2 ;

    e.printt() ;

    entity e1 ;
    e1.x =3 ; e1.y = 4 ;

    e.printt() ;
    e1.printt();

    return 0 ;
}
