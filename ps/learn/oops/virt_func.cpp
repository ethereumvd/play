#include<iostream>

class entity {

    public :
        
        virtual std::string getname() { return "Entity";}
        /*std::string getname() { return "Entity" ;}*/
        /*without using virtual , same getname function used for player and entity*/

};

class player : public entity {

    private:

        std::string m_name ;
        
    public :

        player(const std::string& name)
            : m_name(name){}

        std::string getname() override { return m_name ;}

    /*override only used with virtual functions , it is not required to write */
    /*override but it makes the code readable*/

};

void printname(entity* entity) {

    std::cout << entity->getname() << std::endl ;

}

int main() {

    entity* e = new entity ;
    printname(e);

    player* p = new player("ethereum") ;
    printname(p);

    /*this will print "entity" twice as it will consider the getname function of */
    /*entity */
    /*virtual functions do something called dynamic dispatch which compilers */
    /*implement through v tables*/

    /*additional memory required for v table */
    /*and the compiler will have to look up through the v table that would */
    /*give minor performance issues*/
    /*this wont matter unless we are in a embedded system */

    delete(e); delete(p);

    return 0;

}
