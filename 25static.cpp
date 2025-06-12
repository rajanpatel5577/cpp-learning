/*
ststic at file scope:
A static variable at file scope is visible only within the file it is declared in.
It is not visible to other files, even if they include the header file where it is declared.

// static at function scope:
A static variable at function scope retains its value between function calls.
It is initialized only once, and its lifetime extends until the program terminates, but its scope is limited to the function in which it is declared.

static at class scope:
A static member variable of a class is shared among all instances of the class.
It is not tied to any specific instance, and it can be accessed using the class name or through an instance of the class.
static methods can be called without creating an instance of the class.
*/

#include <iostream>
#include <string>

class A
{

public:
    static int staticVar;
    int nonStaticVar;
    void printVlaue()
    {
        std::cout << "Static variable value: " << staticVar << std::endl;
        std::cout << "nonStatic variable value: " << nonStaticVar << std::endl;
    };
    static void printStaticValue()
    {
        std::cout << "Static variable value: " << staticVar << std::endl;
        // std::cout << "nonStatic variable value: " << nonStaticVar << std::endl; //not able to access non-static variable from static method
    };
};

int A::staticVar; 

int main()
{
    A a1;
    a1.staticVar = 10;
    a1.nonStaticVar = 11;

    A a2;
    a2.staticVar = 20;
    a2.nonStaticVar = 22;
    // A::staticVar = 10; // Set the static variable using the class name

    a1.printVlaue();
    a2.printVlaue(); // Output

    A::printStaticValue(); 
};
