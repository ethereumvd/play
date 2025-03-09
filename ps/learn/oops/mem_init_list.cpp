#include<iostream>

class example {
public :
    example() {
        std::cout << "created entity" << "\n";
    }
    example(int x) {
    std::cout << "created entity with: " << x << "\n";
    }
};

class entity {
private:
    std::string m_name;
    int m_score;
    example m_ex;
public:
    entity()
        : m_name("Unknown"),m_score(0),m_ex(9) //always initialise in the order you initialised the members/variables of the class
    {
        /*m_ex(9);*/ //this is obviosly not possible,only possible while declaring
        /*m_ex = example(8);*/
        //above would create 2 entity instances one of which would go to waste
        //so we better use a member initialiser list 
        //otherwise it decreases performance
    }
    entity(const std::string& name) {
        m_name = name;
    }
    
    std::string getname() { 
        return m_name; 
    }
};

int main() {

    //get used to member initializer lists 
    //otherwise youll be wasting performance

    entity e;
    e.getname();
    return 0;

}
