#include<iostream>

class entity {

    public :
        static int x ;

        static void printt() ;

};

void entity::printt() {
    std::cout << x << "\n" ;
}

int entity::x = 9;
//entity::x = 10 ;
// not allowed because this is a standalone statement 
//and we cannot declare standalone statements outside of a function

//entity::printt();
// also not allowed as it is also a standalone statement
//function calls are also standalone statements 
//hence cannot be declared in global scope

int main() {

    entity::printt() ;
    return 0 ;
}
