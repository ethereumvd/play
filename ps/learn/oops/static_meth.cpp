#include <iostream>
class Example {
private:
    int nonStaticVar;         // Non-static member
    static int staticVar;     // Static member

public:
    Example(int value) : nonStaticVar(value) {}

    static void staticMethod() {
        // std::cout << nonStaticVar; // ERROR: Cannot access non-static member
        std::cout << "Static method: I cannot access non-static members directly!\n";
    }

    void nonStaticMethod() {
        std::cout << "Non-static method: I can access non-staticVar = " << nonStaticVar << "\n";
        std::cout << "Non-static method: I can also access staticVar = " << staticVar << "\n";
    }
};

int Example::staticVar = 42;

//if it is a static method , then how will it know which instance of the many instances of the non static variable i am referring to ? 
//but if it is a non static method , then it will belong to a particular instance hence it will know which non static variable to refer .

int main() {
    Example obj1(10);

    Example::staticMethod();
    obj1.nonStaticMethod();  

    return 0;
}

